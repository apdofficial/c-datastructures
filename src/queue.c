#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "common.h"
#include "queue.h"


struct Queue{
    Node head;
    Node tail;
    Metadata metadata;
};

Queue queue_create() {
    Queue queue = malloc( sizeof(struct Queue));
    if (!queue){
        fprintf(stderr, "Failed to allocate memory for Queue.\n");
        return NULL;
    }
    Metadata metadata = malloc(sizeof(struct Metadata));
    if (!metadata){
        fprintf(stderr, "Failed to allocate memory for QueueMetadata.\n");
        return NULL;
    }
    queue->head = NULL;
    queue->tail = NULL;
    queue->metadata = metadata;
    queue->metadata->size = 0;
    return queue;
}

void queue_clear(Queue queue) {
    if (!queue) return;
    Node head = queue->head;
    while (head){
        Node tmp = head;
        head = head->next;
        free(tmp);
    }
    queue->head = NULL;
    queue->tail = NULL;
    queue->metadata->size = 0;
}

int queue_size(Queue queue) {
    if(!queue) return 0;
    return queue->metadata->size;
}

bool queue_is_empty(Queue queue) {
    if(!queue) return false;
    return queue_size(queue) == 0;
}

void queue_enqueue(Queue queue, Item item) {
    if (!queue) return;
    Node node = node_create(item);

    if (queue_is_empty(queue)){
        queue->head = node;
        queue->tail = node;
    } else {
        queue->tail->next = node;
        queue->tail = node;
    }
    queue->metadata->size++;
}

Item queue_dequeue(Queue queue) {
    if (!queue) return NULL;
    if (queue_is_empty(queue)) return NULL;
    Node head = queue->head;
    Item item = head->item;
    queue->head = head->next;
    free(head);
    queue->metadata->size--;
    return item;
}

void queue_print(Queue queue) {
    if (!queue) return;
    Node x = queue->head;
    if (!x) return;
    while (x){
        printf("[key: %lu, next: %p]", x->key, &x->next);
        x = x->next;
        if (x) printf(" -> ");
    }
    printf("\n");
}
















