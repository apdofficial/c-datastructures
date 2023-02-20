#include "../utest.h"
#include <stdlib.h>
#include "data_structures.h"
#include "../src/common.h"

struct LinkedListFixture{
    LinkedList list;
};

UTEST(item, create) {
    char data[2] = {0x41, 0x42};
    Item item = item_create(data, 2);
    ASSERT_NE(item, NULL);
    ASSERT_EQ(item->size, (node_key_t)2);
    for (size_t i = 0; i < item->size; ++i) {
        ASSERT_EQ(item->data[i], data[i]);
    }
}

UTEST(node, create) {
    char data[2] = {0x41, 0x42};
    Item item = item_create(data, 2);
    Node node = node_create(item);
    ASSERT_NE(node, NULL);
    ASSERT_EQ(node->key, (node_key_t)0);
    ASSERT_EQ(node->item->size, (node_key_t)2);
    for (size_t i = 0; i < node->item->size; ++i) {
        ASSERT_EQ(node->item->data[i], data[i]);
    }
    ASSERT_EQ(node->next, NULL);
}

UTEST_F_SETUP(LinkedListFixture) {
    utest_fixture->list = linked_list_create();
    ASSERT_NE(utest_fixture->list, NULL);
}

UTEST_F_TEARDOWN(LinkedListFixture) {
    linked_list_clear(utest_fixture->list);
    ASSERT_EQ(linked_list_size(utest_fixture->list), 0);
    ASSERT_TRUE(linked_list_is_empty(utest_fixture->list));
}

UTEST_F(LinkedListFixture, size_is_zero_when_empty) {
    ASSERT_EQ(linked_list_size(utest_fixture->list), 0);
}

UTEST_F(LinkedListFixture, is_empty_when_empty) {
    ASSERT_TRUE(linked_list_is_empty(utest_fixture->list));
}

UTEST_F(LinkedListFixture, search_node_based_on_key) {
    Node node = linked_list_search(utest_fixture->list, 0);
    ASSERT_EQ(node, NULL);
}

UTEST_F(LinkedListFixture, prepend_node) {
    char data[2] = {0x41, 0x42};
    Item item = item_create(data, 2);
    Node node = node_create(item);
    Node prepended_node = linked_list_prepend(utest_fixture->list, node);
    ASSERT_EQ(prepended_node, node);
    ASSERT_EQ(linked_list_size(utest_fixture->list), 1);
    ASSERT_FALSE(linked_list_is_empty(utest_fixture->list));
    ASSERT_EQ(linked_list_search(utest_fixture->list, node->key), node);
    ASSERT_EQ(linked_list_search(utest_fixture->list, prepended_node->key), prepended_node);
}

UTEST_F(LinkedListFixture, append_node) {
    char data[2] = {0x41, 0x42};
    Item item = item_create(data, 2);
    Node node = node_create(item);
    Node appended_node = linked_list_append(utest_fixture->list, node);
    ASSERT_EQ(appended_node, node);
    ASSERT_EQ(linked_list_size(utest_fixture->list), 1);
    ASSERT_FALSE(linked_list_is_empty(utest_fixture->list));
    ASSERT_EQ(linked_list_search(utest_fixture->list, node->key), node);
    ASSERT_EQ(linked_list_search(utest_fixture->list, appended_node->key), appended_node);
}

UTEST_F(LinkedListFixture, delete_node) {
    char data[2] = {0x41, 0x42};
    Item item = item_create(data, 2);
    Node node = node_create(item);
    Node prepended_node = linked_list_prepend(utest_fixture->list, node);
    ASSERT_EQ(prepended_node, node);
    ASSERT_EQ(linked_list_size(utest_fixture->list), 1);
    ASSERT_FALSE(linked_list_is_empty(utest_fixture->list));
    ASSERT_EQ(linked_list_search(utest_fixture->list, node->key), node);
    ASSERT_EQ(linked_list_search(utest_fixture->list, prepended_node->key), prepended_node);
    bool deleted_node = linked_list_delete(utest_fixture->list, node->key);
    ASSERT_TRUE(deleted_node);
    ASSERT_EQ(linked_list_size(utest_fixture->list), 0);
    ASSERT_TRUE(linked_list_is_empty(utest_fixture->list));
    ASSERT_EQ(linked_list_search(utest_fixture->list, node->key), NULL);
    ASSERT_EQ(linked_list_search(utest_fixture->list, prepended_node->key), NULL);
}

UTEST_F(LinkedListFixture, clear) {
    char data[2] = {0x41, 0x42};
    Item item = item_create(data, 2);
    Node node = node_create(item);
    Node prepended_node = linked_list_prepend(utest_fixture->list, node);
    ASSERT_EQ(prepended_node, node);
    ASSERT_EQ(linked_list_size(utest_fixture->list), 1);
    ASSERT_FALSE(linked_list_is_empty(utest_fixture->list));
    ASSERT_EQ(linked_list_search(utest_fixture->list, node->key), node);
    ASSERT_EQ(linked_list_search(utest_fixture->list, prepended_node->key), prepended_node);
    linked_list_clear(utest_fixture->list);
    ASSERT_EQ(linked_list_size(utest_fixture->list), 0);
    ASSERT_TRUE(linked_list_is_empty(utest_fixture->list));
    ASSERT_EQ(linked_list_search(utest_fixture->list, node->key), NULL);
    ASSERT_EQ(linked_list_search(utest_fixture->list, prepended_node->key), NULL);
}

UTEST_MAIN();