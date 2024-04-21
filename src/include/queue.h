#ifndef DATA_STRUCTURES_QUEUE_H
#define DATA_STRUCTURES_QUEUE_H

#include "common_public.h"

// opaque types
typedef struct Queue Queue;

/**
 * Queue
 *
 * In a queue, the element deleted from the set is the one that has been in the
 * set the longest: the queue implements a first-in, first-out, or FIFO, policy.
 *
 * Source: Introduction to Algorithms, Fourth Edition, Cormen et. al.
 */

/**
 * Create a new queue.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 * @return pointer to the new queue, or NULL if the queue could not be created.
 */
Queue* queue_create();

/**
 * Empty the queue.
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * @param queue
 */
void queue_clear(Queue* queue);

/**
 * Get the size of the queue.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 * @param queue
 * @return size of the queue, or -1 if the queue is NULL.
 */
int queue_size(Queue* queue);

/**
 * Check if the queue is empty.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 * @param queue
 * @return true if the queue is empty, false otherwise.
 */
bool queue_is_empty(Queue* queue);

/**
 * Enqueue an item to the queue.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 * @param queue
 * @param item
 */
void queue_enqueue(Queue* queue, Item* item);

/**
 * Dequeue an item from the queue.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 * @param queue
 * @return item
 */
Item* queue_dequeue(Queue* queue);

/**
 * Peek the first item in the queue.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 * @param queue
 * @return item
 */
Item* queue_peek(Queue* queue);

/**
 * Print the queue.
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * @param queue
 */
void queue_print(Queue* queue);

#endif  // DATA_STRUCTURES_QUEUE_H
