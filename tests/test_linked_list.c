#include <stdlib.h>

#include "data_structures.h"
#include "utest.h"

struct LinkedListFixture {
  LinkedList* list;
};

UTEST(item, create) {
  char data[2] = {0x41, 0x42};
  Item* item = item_create(data, 2);
  ASSERT_NE(item, NULL);
  ASSERT_EQ(item->size, (node_key_t)2);
  for (size_t i = 0; i < item->size; ++i) {
    ASSERT_EQ(item->data[i], data[i]);
  }
}

UTEST(node, create) {
  char data[2] = {0x41, 0x42};
  Item* item = item_create(data, 2);
  Node* node = node_create(item);
  ASSERT_NE(node, NULL);
  ASSERT_EQ(node_get_key(node), (node_key_t)0);
  ASSERT_EQ(node_get_item(node)->size, (node_key_t)2);
  for (size_t i = 0; i < node_get_item(node)->size; ++i) {
    ASSERT_EQ(node_get_item(node)->data[i], data[i]);
  }
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
  Node* node = linked_list_search(utest_fixture->list, 0);
  ASSERT_EQ(node, NULL);
}

UTEST_F(LinkedListFixture, prepend_node) {
  char data[2] = {0x41, 0x42};
  Item* item = item_create(data, 2);
  Node* node = node_create(item);
  Node* prepended_node = linked_list_prepend(utest_fixture->list, node);
  ASSERT_EQ(prepended_node, node);
  ASSERT_EQ(linked_list_size(utest_fixture->list), 1);
  ASSERT_FALSE(linked_list_is_empty(utest_fixture->list));
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(node)), node);
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(prepended_node)), prepended_node);
}

UTEST_F(LinkedListFixture, append_node) {
  char data[2] = {0x41, 0x42};
  Item* item = item_create(data, 2);
  Node* node = node_create(item);
  Node* appended_node = linked_list_append(utest_fixture->list, node);
  ASSERT_EQ(appended_node, node);
  ASSERT_EQ(linked_list_size(utest_fixture->list), 1);
  ASSERT_FALSE(linked_list_is_empty(utest_fixture->list));
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(node)), node);
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(appended_node)), appended_node);
}

UTEST_F(LinkedListFixture, delete_node) {
  char data[2] = {0x41, 0x42};
  Item* item = item_create(data, 2);
  Node* node = node_create(item);
  Node* prepended_node = linked_list_prepend(utest_fixture->list, node);
  ASSERT_EQ(prepended_node, node);
  ASSERT_EQ(linked_list_size(utest_fixture->list), 1);
  ASSERT_FALSE(linked_list_is_empty(utest_fixture->list));
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(node)), node);
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(prepended_node)), prepended_node);
  bool deleted_node = linked_list_delete(utest_fixture->list, node_get_key(node));
  ASSERT_TRUE(deleted_node);
  ASSERT_EQ(linked_list_size(utest_fixture->list), 0);
  ASSERT_TRUE(linked_list_is_empty(utest_fixture->list));
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(node)), NULL);
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(prepended_node)), NULL);
}

UTEST_F(LinkedListFixture, clear) {
  char data[2] = {0x41, 0x42};
  Item* item = item_create(data, 2);
  Node* node = node_create(item);
  Node* prepended_node = linked_list_prepend(utest_fixture->list, node);
  ASSERT_EQ(prepended_node, node);
  ASSERT_EQ(linked_list_size(utest_fixture->list), 1);
  ASSERT_FALSE(linked_list_is_empty(utest_fixture->list));
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(node)), node);
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(prepended_node)), prepended_node);
  linked_list_clear(utest_fixture->list);
  ASSERT_EQ(linked_list_size(utest_fixture->list), 0);
  ASSERT_TRUE(linked_list_is_empty(utest_fixture->list));
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(node)), NULL);
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(prepended_node)), NULL);
}

UTEST_F(LinkedListFixture, insert_node) {
  char data[2] = {0x41, 0x42};
  Item* item = item_create(data, 2);
  Node* node = node_create(item);
  Node* prepended_node = linked_list_prepend(utest_fixture->list, node);
  ASSERT_EQ(prepended_node, node);
  ASSERT_EQ(linked_list_size(utest_fixture->list), 1);
  ASSERT_FALSE(linked_list_is_empty(utest_fixture->list));
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(node)), node);
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(prepended_node)), prepended_node);
  char data2[2] = {0x43, 0x44};
  Item* item2 = item_create(data2, 2);
  Node* node2 = node_create(item2);
  bool inserted_node = linked_list_insert(utest_fixture->list, node_get_key(node), node2);
  ASSERT_TRUE(inserted_node);
  ASSERT_EQ(linked_list_size(utest_fixture->list), 2);
  ASSERT_FALSE(linked_list_is_empty(utest_fixture->list));
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(node)), node);
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(prepended_node)), prepended_node);
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(node2)), node2);
}

UTEST_F(LinkedListFixture, insert_node_at_beginning) {
  char data[2] = {0x41, 0x42};
  Item* item = item_create(data, 2);
  Node* node = node_create(item);
  Node* prepended_node = linked_list_prepend(utest_fixture->list, node);
  ASSERT_EQ(prepended_node, node);
  ASSERT_EQ(linked_list_size(utest_fixture->list), 1);
  ASSERT_FALSE(linked_list_is_empty(utest_fixture->list));
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(node)), node);
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(prepended_node)), prepended_node);
  char data2[2] = {0x43, 0x44};
  Item* item2 = item_create(data2, 2);
  Node* node2 = node_create(item2);
  bool inserted_node = linked_list_insert(utest_fixture->list, node_get_key(node), node2);
  ASSERT_TRUE(inserted_node);
  ASSERT_EQ(linked_list_size(utest_fixture->list), 2);
  ASSERT_FALSE(linked_list_is_empty(utest_fixture->list));
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(node)), node);
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(prepended_node)), prepended_node);
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(node2)), node2);
}

UTEST_F(LinkedListFixture, insert_node_at_end) {
  char data[2] = {0x41, 0x42};
  Item* item = item_create(data, 2);
  Node* node = node_create(item);
  Node* prepended_node = linked_list_prepend(utest_fixture->list, node);
  char data2[2] = {0x41, 0x42};
  Item* item2 = item_create(data2, 2);
  Node* node2 = node_create(item2);
  Node* prepended_node2 = linked_list_prepend(utest_fixture->list, node2);
  ASSERT_EQ(prepended_node, node);
  ASSERT_EQ(linked_list_size(utest_fixture->list), 2);
  ASSERT_FALSE(linked_list_is_empty(utest_fixture->list));
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(node)), node);
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(prepended_node)), prepended_node);
  char data3[2] = {0x43, 0x44};
  Item* item3 = item_create(data3, 2);
  Node* node3 = node_create(item3);
  bool inserted_node = linked_list_insert(utest_fixture->list, node_get_key(node2), node3);
  ASSERT_TRUE(inserted_node);
  ASSERT_EQ(linked_list_size(utest_fixture->list), 3);
  ASSERT_FALSE(linked_list_is_empty(utest_fixture->list));
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(node)), node);
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(prepended_node)), prepended_node);
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(node2)), node2);
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(node3)), node3);
}

UTEST_F(LinkedListFixture, insert_node_at_middle) {
  char data[2] = {0x41, 0x42};
  Item* item = item_create(data, 2);
  Node* node = node_create(item);
  Node* prepended_node = linked_list_prepend(utest_fixture->list, node);
  ASSERT_EQ(prepended_node, node);
  ASSERT_EQ(linked_list_size(utest_fixture->list), 1);
  ASSERT_FALSE(linked_list_is_empty(utest_fixture->list));
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(node)), node);
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(prepended_node)), prepended_node);
  char data2[2] = {0x43, 0x44};
  Item* item2 = item_create(data2, 2);
  Node* node2 = node_create(item2);
  bool inserted_node = linked_list_insert(utest_fixture->list, node_get_key(prepended_node), node2);
  ASSERT_TRUE(inserted_node);
  ASSERT_EQ(linked_list_size(utest_fixture->list), 2);
  ASSERT_FALSE(linked_list_is_empty(utest_fixture->list));
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(node)), node);
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(prepended_node)), prepended_node);
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(node2)), node2);
  char data3[2] = {0x45, 0x46};
  Item* item3 = item_create(data3, 2);
  Node* node3 = node_create(item3);
  inserted_node = linked_list_insert(utest_fixture->list, node_get_key(node2), node3);
  ASSERT_TRUE(inserted_node);
  ASSERT_EQ(linked_list_size(utest_fixture->list), 3);
  ASSERT_FALSE(linked_list_is_empty(utest_fixture->list));
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(node)), node);
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(prepended_node)), prepended_node);
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(node2)), node2);
}

UTEST_F(LinkedListFixture, insert_node_at_invalid_index) {
  char data[2] = {0x41, 0x42};
  Item* item = item_create(data, 2);
  Node* node = node_create(item);
  Node* prepended_node = linked_list_prepend(utest_fixture->list, node);
  ASSERT_EQ(prepended_node, node);
  ASSERT_EQ(linked_list_size(utest_fixture->list), 1);
  ASSERT_FALSE(linked_list_is_empty(utest_fixture->list));
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(node)), node);
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(prepended_node)), prepended_node);
  char data2[2] = {0x43, 0x44};
  Item* item2 = item_create(data2, 2);
  Node* node2 = node_create(item2);
  bool inserted_node = linked_list_insert(utest_fixture->list, node_get_key(node), node2);
  ASSERT_TRUE(inserted_node);
  ASSERT_EQ(linked_list_size(utest_fixture->list), 2);
  ASSERT_FALSE(linked_list_is_empty(utest_fixture->list));
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(node)), node);
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(prepended_node)), prepended_node);
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(node2)), node2);
  char data3[2] = {0x45, 0x46};
  Item* item3 = item_create(data3, 2);
  Node* node3 = node_create(item3);
  inserted_node = linked_list_insert(utest_fixture->list, -1, node3);
  ASSERT_FALSE(inserted_node);
  ASSERT_EQ(linked_list_size(utest_fixture->list), 2);
  ASSERT_FALSE(linked_list_is_empty(utest_fixture->list));
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(node)), node);
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(prepended_node)), prepended_node);
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(node2)), node2);
}

UTEST_F(LinkedListFixture, remove_node_at_beginning) {
  char data[2] = {0x41, 0x42};
  Item* item = item_create(data, 2);
  Node* node = node_create(item);
  Node* prepended_node = linked_list_prepend(utest_fixture->list, node);
  ASSERT_EQ(prepended_node, node);
  ASSERT_EQ(linked_list_size(utest_fixture->list), 1);
  ASSERT_FALSE(linked_list_is_empty(utest_fixture->list));
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(node)), node);
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(prepended_node)), prepended_node);
  char data2[2] = {0x43, 0x44};
  Item* item2 = item_create(data2, 2);
  Node* node2 = node_create(item2);
  bool inserted_node = linked_list_insert(utest_fixture->list, node_get_key(node), node2);
  ASSERT_TRUE(inserted_node);
  ASSERT_EQ(linked_list_size(utest_fixture->list), 2);
  ASSERT_FALSE(linked_list_is_empty(utest_fixture->list));
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(node)), node);
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(prepended_node)), prepended_node);
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(node2)), node2);
  char data3[2] = {0x45, 0x46};
  Item* item3 = item_create(data3, 2);
  Node* node3 = node_create(item3);
  inserted_node = linked_list_insert(utest_fixture->list, node_get_key(node2), node3);
  ASSERT_TRUE(inserted_node);
  ASSERT_EQ(linked_list_size(utest_fixture->list), 3);
  ASSERT_FALSE(linked_list_is_empty(utest_fixture->list));
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(node)), node);
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(prepended_node)), prepended_node);
  ASSERT_EQ(linked_list_search(utest_fixture->list, node_get_key(node2)), node2);
}

UTEST_MAIN();
