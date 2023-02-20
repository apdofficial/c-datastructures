#ifndef DATA_STRUCTURES_COMMON_H
#define DATA_STRUCTURES_COMMON_H

#include "common_public.h"

struct Node {
    node_key_t key;
    Item item;
    Node next;
    Node prev;
};

struct LinkedListMetadata {
    int size;
};

#endif //DATA_STRUCTURES_COMMON_H
