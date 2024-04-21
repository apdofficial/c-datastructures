#include <stdlib.h>

#include "data_structures.h"
#include "utest.h"

struct QueueFixture {
  Queue* queue;
  Item* dummy_item1;
  Item* dummy_item2;
};

UTEST_F_SETUP(QueueFixture) {
  utest_fixture->queue = queue_create();
  ASSERT_NE(utest_fixture->queue, NULL);
  char data[2] = {0x41, 0x42};
  Item* item = item_create(data, 2);
  utest_fixture->dummy_item1 = item;
  char data2[3] = {0x43, 0x44, 0x45};
  Item* item2 = item_create(data2, 3);
  utest_fixture->dummy_item2 = item2;
}

UTEST_F_TEARDOWN(QueueFixture) {
  queue_clear(utest_fixture->queue);
  ASSERT_EQ(queue_size(utest_fixture->queue), 0);
  ASSERT_TRUE(queue_is_empty(utest_fixture->queue));
}

UTEST_F(QueueFixture, size_is_zero_when_empty) {
  ASSERT_EQ(queue_size(utest_fixture->queue), 0);
}

UTEST_F(QueueFixture, is_empty_when_empty) {
  ASSERT_TRUE(queue_is_empty(utest_fixture->queue));
}

UTEST_F(QueueFixture, peek_node) {
  queue_enqueue(utest_fixture->queue, utest_fixture->dummy_item1);
  Item* peeked_item = queue_peek(utest_fixture->queue);
  for (size_t i = 0; i < peeked_item->size; ++i) {
    ASSERT_EQ(peeked_item->data[i], utest_fixture->dummy_item1->data[i]);
  }
  ASSERT_EQ(peeked_item->size, utest_fixture->dummy_item1->size);
}

UTEST_F(QueueFixture, enqueue_node) {
  queue_enqueue(utest_fixture->queue, utest_fixture->dummy_item1);
  Item* enqueued_node = queue_peek(utest_fixture->queue);
  ASSERT_EQ(enqueued_node->size, utest_fixture->dummy_item1->size);
  for (size_t i = 0; i < enqueued_node->size; ++i) {
    ASSERT_EQ(enqueued_node->data[i], utest_fixture->dummy_item1->data[i]);
  }
}

UTEST_F(QueueFixture, dequeue_node) {
  queue_enqueue(utest_fixture->queue, utest_fixture->dummy_item1);
  queue_enqueue(utest_fixture->queue, utest_fixture->dummy_item2);

  Item* dequeued_item = queue_dequeue(utest_fixture->queue);
  for (size_t i = 0; i < dequeued_item->size; ++i) {
    ASSERT_EQ(dequeued_item->data[i], utest_fixture->dummy_item1->data[i]);
  }
  ASSERT_EQ(dequeued_item->size, utest_fixture->dummy_item1->size);
}

UTEST_F(QueueFixture, size_is_one_when_one_node) {
  queue_enqueue(utest_fixture->queue, utest_fixture->dummy_item1);
  ASSERT_EQ(queue_size(utest_fixture->queue), 1);
}

UTEST_F(QueueFixture, is_not_empty_when_one_node) {
  queue_enqueue(utest_fixture->queue, utest_fixture->dummy_item1);
  ASSERT_FALSE(queue_is_empty(utest_fixture->queue));
}

UTEST_F(QueueFixture, size_is_two_when_two_nodes) {
  queue_enqueue(utest_fixture->queue, utest_fixture->dummy_item1);
  queue_enqueue(utest_fixture->queue, utest_fixture->dummy_item2);
  ASSERT_EQ(queue_size(utest_fixture->queue), 2);
}

UTEST_F(QueueFixture, is_not_empty_when_two_nodes) {
  queue_enqueue(utest_fixture->queue, utest_fixture->dummy_item1);
  queue_enqueue(utest_fixture->queue, utest_fixture->dummy_item2);
  ASSERT_FALSE(queue_is_empty(utest_fixture->queue));
}

UTEST_F(QueueFixture, clear_queue) {
  queue_enqueue(utest_fixture->queue, utest_fixture->dummy_item1);
  queue_enqueue(utest_fixture->queue, utest_fixture->dummy_item2);
  queue_clear(utest_fixture->queue);
  ASSERT_EQ(queue_size(utest_fixture->queue), 0);
  ASSERT_TRUE(queue_is_empty(utest_fixture->queue));
}

UTEST_F(QueueFixture, clear_queue_with_one_node) {
  queue_enqueue(utest_fixture->queue, utest_fixture->dummy_item1);
  queue_clear(utest_fixture->queue);
  ASSERT_EQ(queue_size(utest_fixture->queue), 0);
  ASSERT_TRUE(queue_is_empty(utest_fixture->queue));
}

UTEST_F(QueueFixture, clear_queue_with_two_nodes) {
  queue_enqueue(utest_fixture->queue, utest_fixture->dummy_item1);
  queue_enqueue(utest_fixture->queue, utest_fixture->dummy_item2);
  queue_clear(utest_fixture->queue);
  ASSERT_EQ(queue_size(utest_fixture->queue), 0);
  ASSERT_TRUE(queue_is_empty(utest_fixture->queue));
}

UTEST_MAIN();
