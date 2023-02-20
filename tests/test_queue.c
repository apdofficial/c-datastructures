#include "utest.h"
#include <stdlib.h>
#include "data_structures.h"

struct QueueFixture{
    Stack stack;
    Item dummy_item;
    Item dummy_item2;
};


UTEST_F_SETUP(QueueFixture) {
    utest_fixture->stack = stack_create();
    ASSERT_NE(utest_fixture->stack, NULL);
    char data[2] = {0x41, 0x42};
    Item item = item_create( data, 2);
    utest_fixture->dummy_item = item;
    char data2[2] = {0x43, 0x44, 0x45};
    Item item2 = item_create( data2, 3);
    utest_fixture->dummy_item2 = item2;
}

UTEST_F_TEARDOWN(QueueFixture) {
    stack_clear(utest_fixture->stack);
    ASSERT_EQ(stack_size(utest_fixture->stack), 0);
    ASSERT_TRUE(stack_is_empty(utest_fixture->stack));
}

UTEST_F(QueueFixture, size_is_zero_when_empty) {
    ASSERT_EQ(stack_size(utest_fixture->stack), 0);
}

UTEST_F(QueueFixture, is_empty_when_empty) {
    ASSERT_TRUE(stack_is_empty(utest_fixture->stack));
}

UTEST_F(QueueFixture, peek_node) {
    stack_push(utest_fixture->stack, utest_fixture->dummy_item);
    Item peeked_item = stack_peek(utest_fixture->stack);
    for (size_t i = 0; i < peeked_item->size; ++i) {
        ASSERT_EQ(peeked_item->data[i], utest_fixture->dummy_item->data[i]);
    }
    ASSERT_EQ(peeked_item->size, utest_fixture->dummy_item->size);
}

UTEST_F(QueueFixture, push_node) {
    stack_push(utest_fixture->stack, utest_fixture->dummy_item);
    Item pushed_node = stack_peek(utest_fixture->stack);
    ASSERT_EQ(pushed_node->size, utest_fixture->dummy_item->size);
    for (size_t i = 0; i < pushed_node->size; ++i) {
        ASSERT_EQ(pushed_node->data[i], utest_fixture->dummy_item->data[i]);
    }
}

UTEST_F(QueueFixture, pop_node) {
    stack_push(utest_fixture->stack, utest_fixture->dummy_item);
    stack_push(utest_fixture->stack, utest_fixture->dummy_item2);

    Item popped_item = stack_pop(utest_fixture->stack);
    for (size_t i = 0; i < popped_item->size; ++i) {
        ASSERT_EQ(popped_item->data[i], utest_fixture->dummy_item2->data[i]);
    }
    ASSERT_EQ(popped_item->size, utest_fixture->dummy_item2->size);
}

UTEST_F(QueueFixture, size_is_one_when_one_node) {
    stack_push(utest_fixture->stack, utest_fixture->dummy_item);
    ASSERT_EQ(stack_size(utest_fixture->stack), 1);
}

UTEST_F(QueueFixture, is_not_empty_when_one_node) {
    stack_push(utest_fixture->stack, utest_fixture->dummy_item);
    ASSERT_FALSE(stack_is_empty(utest_fixture->stack));
}

UTEST_F(QueueFixture, size_is_two_when_two_nodes) {
    stack_push(utest_fixture->stack, utest_fixture->dummy_item);
    stack_push(utest_fixture->stack, utest_fixture->dummy_item2);
    ASSERT_EQ(stack_size(utest_fixture->stack), 2);
}

UTEST_F(QueueFixture, is_not_empty_when_two_nodes) {
    stack_push(utest_fixture->stack, utest_fixture->dummy_item);
    stack_push(utest_fixture->stack, utest_fixture->dummy_item2);
    ASSERT_FALSE(stack_is_empty(utest_fixture->stack));
}

UTEST_F(QueueFixture, clear_stack) {
    stack_push(utest_fixture->stack, utest_fixture->dummy_item);
    stack_push(utest_fixture->stack, utest_fixture->dummy_item2);
    stack_clear(utest_fixture->stack);
    ASSERT_EQ(stack_size(utest_fixture->stack), 0);
    ASSERT_TRUE(stack_is_empty(utest_fixture->stack));
}

UTEST_F(QueueFixture, clear_empty_stack) {
    stack_clear(utest_fixture->stack);
    ASSERT_EQ(stack_size(utest_fixture->stack), 0);
    ASSERT_TRUE(stack_is_empty(utest_fixture->stack));
}

UTEST_F(QueueFixture, pop_empty_stack) {
    Item popped_item = stack_pop(utest_fixture->stack);
    ASSERT_EQ(popped_item, NULL);
}

UTEST_F(QueueFixture, peek_empty_stack) {
    Item peeked_item = stack_peek(utest_fixture->stack);
    ASSERT_EQ(peeked_item, NULL);
}

UTEST_F(QueueFixture, push_null_node) {
    ASSERT_EQ(stack_size(utest_fixture->stack), 0);
    stack_push(utest_fixture->stack, NULL);
    ASSERT_EQ(stack_size(utest_fixture->stack), 0);
    ASSERT_TRUE(stack_is_empty(utest_fixture->stack));
}

UTEST_F(QueueFixture, pop_null_node) {
    stack_push(utest_fixture->stack, NULL);
    Item popped_item = stack_pop(utest_fixture->stack);
    ASSERT_EQ(popped_item, NULL);
}

UTEST_F(QueueFixture, peek_null_node) {
    stack_push(utest_fixture->stack, NULL);
    Item peeked_item = stack_peek(utest_fixture->stack);
    ASSERT_EQ(peeked_item, NULL);
}

UTEST_F(QueueFixture, push_null_stack) {
    stack_push(NULL, utest_fixture->dummy_item);
    ASSERT_EQ(stack_size(utest_fixture->stack), 0);
    ASSERT_TRUE(stack_is_empty(utest_fixture->stack));
}

UTEST_F(QueueFixture, pop_null_stack) {
    Item popped_item = stack_pop(NULL);
    ASSERT_EQ(popped_item, NULL);
}

UTEST_F(QueueFixture, peek_null_stack) {
    Item peeked_item = stack_peek(NULL);
    ASSERT_EQ(peeked_item, NULL);
}

UTEST_F(QueueFixture, size_null_stack) {
    ASSERT_EQ(stack_size(NULL), 0);
}

UTEST_F(QueueFixture, is_empty_null_stack) {
    ASSERT_TRUE(stack_is_empty(NULL));
}

UTEST_F(QueueFixture, clear_null_stack) {
    stack_clear(NULL);
    ASSERT_EQ(stack_size(utest_fixture->stack), 0);
    ASSERT_TRUE(stack_is_empty(utest_fixture->stack));
}

UTEST_F(QueueFixture, push_null_item) {
    stack_push(utest_fixture->stack, NULL);
    ASSERT_EQ(stack_size(utest_fixture->stack), 0);
    ASSERT_TRUE(stack_is_empty(utest_fixture->stack));
}

UTEST_F(QueueFixture, pop_null_item) {
    stack_push(utest_fixture->stack, NULL);
    Item popped_item = stack_pop(utest_fixture->stack);
    ASSERT_EQ(popped_item, NULL);
}

UTEST_F(QueueFixture, peek_null_item) {
    stack_push(utest_fixture->stack, NULL);
    Item peeked_item = stack_peek(utest_fixture->stack);
    ASSERT_EQ(peeked_item, NULL);
}

UTEST_F(QueueFixture, push_null_stack_and_item) {
    stack_push(NULL, NULL);
    ASSERT_EQ(stack_size(utest_fixture->stack), 0);
    ASSERT_TRUE(stack_is_empty(utest_fixture->stack));
}

UTEST_F(QueueFixture, pop_null_stack_and_item) {
    Item popped_item = stack_pop(NULL);
    ASSERT_EQ(popped_item, NULL);
}

UTEST_F(QueueFixture, peek_null_stack_and_item) {
    Item peeked_item = stack_peek(NULL);
    ASSERT_EQ(peeked_item, NULL);
}

UTEST_F(QueueFixture, size_null_stack_and_item) {
    ASSERT_EQ(stack_size(NULL), 0);
}

UTEST_F(QueueFixture, is_empty_null_stack_and_item) {
    ASSERT_TRUE(stack_is_empty(NULL));
}

UTEST_F(QueueFixture, clear_null_stack_and_item) {
    stack_clear(NULL);
    ASSERT_EQ(stack_size(utest_fixture->stack), 0);
    ASSERT_TRUE(stack_is_empty(utest_fixture->stack));
}

UTEST_F(QueueFixture, push_null_stack_and_null_item) {
    stack_push(NULL, NULL);
    ASSERT_EQ(stack_size(utest_fixture->stack), 0);
    ASSERT_TRUE(stack_is_empty(utest_fixture->stack));
}

UTEST_F(QueueFixture, pop_null_stack_and_null_item) {
    Item popped_item = stack_pop(NULL);
    ASSERT_EQ(popped_item, NULL);
}

UTEST_F(QueueFixture, peek_null_stack_and_null_item) {
    Item peeked_item = stack_peek(NULL);
    ASSERT_EQ(peeked_item, NULL);
}

UTEST_F(QueueFixture, size_null_stack_and_null_item) {
    ASSERT_EQ(stack_size(NULL), 0);
}

UTEST_F(QueueFixture, is_empty_null_stack_and_null_item) {
    ASSERT_TRUE(stack_is_empty(NULL));
}

UTEST_F(QueueFixture, clear_null_stack_and_null_item) {
    stack_clear(NULL);
    ASSERT_EQ(stack_size(utest_fixture->stack), 0);
    ASSERT_TRUE(stack_is_empty(utest_fixture->stack));
}

UTEST_F(QueueFixture, push_one_item) {
    stack_push(utest_fixture->stack, utest_fixture->dummy_item);
    ASSERT_EQ(stack_size(utest_fixture->stack), 1);
    ASSERT_FALSE(stack_is_empty(utest_fixture->stack));
}

UTEST_F(QueueFixture, pop_one_item) {
    stack_push(utest_fixture->stack, utest_fixture->dummy_item);
    Item popped_item = stack_pop(utest_fixture->stack);
    ASSERT_EQ(popped_item, utest_fixture->dummy_item);
    ASSERT_EQ(stack_size(utest_fixture->stack), 0);
    ASSERT_TRUE(stack_is_empty(utest_fixture->stack));
}

UTEST_F(QueueFixture, peek_one_item) {
    stack_push(utest_fixture->stack, utest_fixture->dummy_item);
    Item peeked_item = stack_peek(utest_fixture->stack);
    ASSERT_EQ(peeked_item, utest_fixture->dummy_item);
    ASSERT_EQ(stack_size(utest_fixture->stack), 1);
    ASSERT_FALSE(stack_is_empty(utest_fixture->stack));
}

UTEST_F(QueueFixture, push_two_items) {
    stack_push(utest_fixture->stack, utest_fixture->dummy_item);
    stack_push(utest_fixture->stack, utest_fixture->dummy_item);
    ASSERT_EQ(stack_size(utest_fixture->stack), 2);
    ASSERT_FALSE(stack_is_empty(utest_fixture->stack));
}

UTEST_F(QueueFixture, pop_two_items) {
    stack_push(utest_fixture->stack, utest_fixture->dummy_item);
    stack_push(utest_fixture->stack, utest_fixture->dummy_item);
    Item popped_item = stack_pop(utest_fixture->stack);
    ASSERT_EQ(popped_item, utest_fixture->dummy_item);
    popped_item = stack_pop(utest_fixture->stack);
    ASSERT_EQ(popped_item, utest_fixture->dummy_item);
    ASSERT_EQ(stack_size(utest_fixture->stack), 0);
    ASSERT_TRUE(stack_is_empty(utest_fixture->stack));
}

UTEST_F(QueueFixture, peek_two_items) {
    stack_push(utest_fixture->stack, utest_fixture->dummy_item);
    stack_push(utest_fixture->stack, utest_fixture->dummy_item);
    Item peeked_item = stack_peek(utest_fixture->stack);
    ASSERT_EQ(peeked_item, utest_fixture->dummy_item);
    ASSERT_EQ(stack_size(utest_fixture->stack), 2);
    ASSERT_FALSE(stack_is_empty(utest_fixture->stack));
}

UTEST_MAIN();