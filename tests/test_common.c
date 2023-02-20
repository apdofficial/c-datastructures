#include "utest.h"
#include <stdlib.h>
#include "data_structures.h"

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
    ASSERT_EQ(node_get_key(node), (node_key_t)0);
    ASSERT_EQ(node_get_item(node)->size, (node_key_t)2);
    for (size_t i = 0; i < node_get_item(node)->size; ++i) {
        ASSERT_EQ(node_get_item(node)->data[i], data[i]);
    }
}

UTEST_MAIN();