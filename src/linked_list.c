#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "linked_list.h"

// it could be replaced by a circular doubly-linked list using a sentinel node
// to avoid special cases for the head and tail
struct LinkedList {
  Node* head;
  Metadata* metadata;
};

LinkedList* linked_list_create() {
  LinkedList* list = malloc(sizeof(struct LinkedList));
  if (!list) {
    fprintf(stderr, "Failed to allocate memory for LinkedList.\n");
    return NULL;
  }
  Metadata* metadata = malloc(sizeof(struct Metadata));
  if (!metadata) {
    fprintf(stderr, "Failed to allocate memory for LinkedListMetadata.\n");
    return NULL;
  }
  list->head = NULL;
  list->metadata = metadata;
  list->metadata->size = 0;
  return list;
}

void linked_list_clear(LinkedList* list) {
  Node* head = list->head;
  while (head) {
    Node* tmp = head;
    head = head->next;
    free(tmp);
  }
  list->head = NULL;
  list->metadata->size = 0;
}

int linked_list_size(LinkedList* list) {
  return list->metadata->size;
}

bool linked_list_is_empty(LinkedList* list) {
  return linked_list_size(list) == 0;
}

Node* linked_list_search(LinkedList* list, node_key_t key) {
  Node* x = list->head;
  while (x && x->key != key) {
    x = x->next;
  }
  return x;
}

Node* linked_list_prepend(LinkedList* list, Node* node) {
  node->next = list->head;
  node->prev = NULL;
  if (list->head)
    list->head->prev = node;
  list->head = node;
  list->metadata->size++;
  return node;
}

Node* linked_list_append(LinkedList* list, Node* node) {
  Node* x = list->head;
  while (x && x->next) {
    x = x->next;
  }
  if (x) {
    x->next = node;
    node->prev = x;
  } else {
    list->head = node;
  }
  list->metadata->size++;
  return node;
}

bool linked_list_delete(LinkedList* list, node_key_t key) {
  Node* x = linked_list_search(list, key);
  if (!x)
    return false;
  if (x->prev) {
    x->prev->next = x->next;
  } else {
    list->head = x->next;
  }
  if (x->next) {
    x->next->prev = x->prev;
  }
  free(x);
  list->metadata->size--;
  return true;
}

void linked_list_print(LinkedList* list) {
  Node* x = list->head;
  if (!x)
    return;
  while (x) {
    printf("[key: %lu, next: %p]", x->key, &x->next);
    x = x->next;
    if (x)
      printf(" -> ");
  }
  printf("\n");
}

bool linked_list_insert(LinkedList* list, node_key_t key, Node* node) {
  Node* x = linked_list_search(list, key);
  if (!x)
    return false;
  node->next = x->next;
  node->prev = x;
  x->next = node;
  list->metadata->size++;
  return true;
}
