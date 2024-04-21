#ifndef C_DATASTRUCTURES_LINKED_LIST_H
#define C_DATASTRUCTURES_LINKED_LIST_H

#include <stdbool.h>
#include "common_public.h"

// opaque types
typedef struct LinkedList LinkedList;

/**,
 * Doubly-linked list
 *
 * A linked list is a set of items where each item is part of a head that
 * also contains a link to a head.
 *
 * Source: Introduction to Algorithms, Fourth Edition, Cormen et. al.
 */

/**
 * Node of the linked list.
 */
LinkedList* linked_list_create();

/**
 * Empty the list.
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * @param list
 */
void linked_list_clear(LinkedList* list);

/**
 * Get the size of the list.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 * @param list
 * @return size of the list, or -1 if the list is NULL.
 */
int linked_list_size(LinkedList* list);

/**
 * Check if the list is empty.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 * @param list
 * @return true if the list is empty, false otherwise.
 */
bool linked_list_is_empty(LinkedList* list);

/**
 * Search for a first occurrence of a node with a given key.
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * @param list
 * @param key
 * @return pointer to the node with the given key, or NULL if not found.
 */
Node* linked_list_search(LinkedList* list, node_key_t key);

/**
 * Insert a node at the beginning of the list.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 * @param list
 * @param node
 * @return pointer to the inserted node.
 */
Node* linked_list_prepend(LinkedList* list, Node* node);

/**
 * Insert a node at the end of the list.
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * @param list
 * @param node
 * @return pointer to the inserted node.
 */
Node* linked_list_append(LinkedList* list, Node* node);

/**
 * Insert a node after the given node key.
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * @param list
 * @param node
 * @param new_node
 * @return pointer to the inserted node.
 */
bool linked_list_insert(LinkedList* list, node_key_t key, Node* node);

/**
 * Delete a node from the list that matches the given key.
 * Time Complexity: O(n) due to the search for the node.
 * Space Complexity: O(1)
 * @param list
 * @param node
 * @param new_node
 */
bool linked_list_delete(LinkedList* list, node_key_t key);

/**
 * Print the list.
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * @param list
 */
void linked_list_print(LinkedList* list);

#endif  // C_DATASTRUCTURES_LINKED_LIST_H
