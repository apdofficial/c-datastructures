#ifndef DATA_STRUCTURES_COMMON_PUBLIC_H
#define DATA_STRUCTURES_COMMON_PUBLIC_H

#include <stdlib.h>

// opaque types
typedef struct Node* Node;
typedef size_t node_key_t;

// public types
struct Item {
    size_t size;
    char *data;
};
typedef struct Item* Item;

/**
 * Creates a new Item.
 * @param data the data to store in the Item
 * @param size the size of the data
 * @return a pointer to the new Item
 */
Item item_create(char *data, size_t size);

/**
 * Creates a new Node.
 * @param item the Item to store in the Node
 * @return a pointer to the new Node
 */
Node node_create(Item item);

/**
 * Gets the Item stored in the Node.
 * @param node the Node to get the Item from
 * @return the Item stored in the Node
 */
Item node_get_item(Node node);

/**
 * Gets the key of the Node.
 * @param node the Node to get the key from
 * @return the key of the Node
 */
node_key_t node_get_key(Node node);

#endif //DATA_STRUCTURES_COMMON_PUBLIC_H
