#ifndef DATA_STRUCTURES_STACK_H
#define DATA_STRUCTURES_STACK_H

#include <stdbool.h>
#include "common_public.h"

// opaque types
typedef struct Stack* Stack;

/**,
 * Stack
 *
 * Stacks and queues are dynamic sets in which the element removed from
 * the set by the DELETE operation is prespecified. In a stack, the element
 * deleted is the most recently inserted.
 *
 * Source: Introduction to Algorithms, Fourth Edition, Cormen et. al.
*/

/**
 * Create a new stack.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 * @return pointer to the new stack, or NULL if the stack could not be created.
 */
Stack stack_create();

/**
 * Empty the stack.
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * @param stack
 */
void stack_clear(Stack stack);

/**
 * Get the size of the stack.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 * @param stack
 * @return size of the stack, or -1 if the stack is NULL.
 */
int stack_size(Stack stack);

/**
 * Check if the stack is empty.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 * @param stack
 * @return true if the stack is empty, false otherwise.
 */
bool stack_is_empty(Stack stack);

/**
 * Push an item to the stack.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 * @param stack
 * @param item
 */
void stack_push(Stack stack, Item item);

/**
 * Pop an item from the stack.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 * @param stack
 * @return item from the stack, or NULL if the stack is empty.
 */
Item stack_pop(Stack stack);

/**
 * Peek at the top of the stack.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 * @param stack
 * @return item from the stack, or NULL if the stack is empty.
 */
Item stack_peek(Stack stack);

/**
 * Print the stack.
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * @param stack
 */
void stack_print(Stack stack);


#endif //DATA_STRUCTURES_STACK_H
