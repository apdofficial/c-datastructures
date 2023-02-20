#ifndef DATA_STRUCTURES_COMMON_C
#define DATA_STRUCTURES_COMMON_C

#include <stdio.h>
#include "common_public.h"
#include "common.h"

node_key_t generate_unique_key() {
    static node_key_t key = 0;
    return key++;
}

Item item_create(char *data, size_t size) {
    Item item = malloc(sizeof(struct Item));
    if (!item) {
        fprintf(stderr, "Failed to create new Item.\n");
        return NULL;
    }
    item->size = size;
    item->data = data;
    return item;
}

struct Node* node_create(Item item) {
    Node node = malloc(sizeof(struct Node));
    if (!node) {
        fprintf(stderr, "Failed to create new Node.\n");
        return NULL;
    }
    node->item = item;
    node->next = NULL;
    node->prev = NULL;
    // optionally we could use the memory address of the node as a key
    node->key = generate_unique_key();
    return node;
}

Item node_get_item(Node node){
    if (!node) return NULL;
    return node->item;
}

node_key_t node_get_key(Node node){
    if (!node) return -1;
    return node->key;
}
#endif //DATA_STRUCTURES_COMMON_C
