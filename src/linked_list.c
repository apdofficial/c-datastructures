#include <stdlib.h>
#include <printf.h>
#include "linked_list.h"
#include "common.h"

struct LinkedList{
    Node head;
    LinkedListMetadata metadata;
};

LinkedList linked_list_create() {
    LinkedList list = malloc( sizeof(struct LinkedList));
    if (!list){
        fprintf(stderr, "Failed to allocate memory for LinkedList.\n");
        return NULL;
    }
    LinkedListMetadata metadata = malloc(sizeof(struct LinkedListMetadata));
    if (!metadata){
        fprintf(stderr, "Failed to allocate memory for LinkedListMetadata.\n");
        return NULL;
    }
    list->head = NULL;
    list->metadata = metadata;
    list->metadata->size = 0;
    return list;
}

void linked_list_clear(LinkedList list) {
    if (!list) return;
    Node head = list->head;
    while (head){
        Node tmp = head;
        head = head->next;
        free(tmp);
    }
    list->head = NULL;
    list->metadata->size = 0;
}

int linked_list_size(LinkedList list) {
    if(!list) return -1;
    return list->metadata->size;
}

bool linked_list_is_empty(LinkedList list) {
    if(!list) return false;
    return linked_list_size(list) == 0;
}


Node linked_list_search(LinkedList list, node_key_t key) {
    if(!list) return NULL;
    Node x = list->head;
    while (x && x->key != key){
        x = x->next;
    }
    return x;
}

Node linked_list_prepend(LinkedList list, Node node) {
    if(!list) return NULL;
    if(!node) return NULL;
    node->next = list->head;
    node->prev = NULL;
    if(list->head) list->head->prev = node;
    list->head = node;
    list->metadata->size++;
    return node;
}

Node linked_list_append(LinkedList list, Node node) {
    if(!list) return NULL;
    if(!node) return NULL;
    Node x = list->head;
    while (x && x->next){
        x = x->next;
    }
    if (x){
        x->next = node;
        node->prev = x;
    } else {
        list->head = node;
    }
    list->metadata->size++;
    return node;
}

bool linked_list_delete(LinkedList list, node_key_t key) {
    if(!list) return false;
    Node x = linked_list_search(list, key);
    if (!x) return false;
    if (x->prev){
        x->prev->next = x->next;
    } else {
        list->head = x->next;
    }
    if (x->next){
        x->next->prev = x->prev;
    }
    free(x);
    list->metadata->size--;
    return true;
}

void linked_list_print(LinkedList list) {
    if (!list) return;
    Node x = list->head;
    if (!x) return;
    while (x){
        printf("[key: %lu, next: %p]", x->key, &x->next);
        x = x->next;
        if (x) printf(" -> ");
    }
    printf("\n");
}
