#include <stdlib.h>
#include <stdio.h>

#include "common.h"
#include "stack.h"

struct Stack{
    Node top;
    Metadata metadata;
};

Stack stack_create() {
    Stack stack = malloc( sizeof(struct Stack));
    if (!stack){
        fprintf(stderr, "Failed to allocate memory for Stack.\n");
        return NULL;
    }
    Metadata metadata = malloc(sizeof(struct Metadata));
    if (!metadata){
        fprintf(stderr, "Failed to allocate memory for StackMetadata.\n");
        return NULL;
    }
    stack->top = NULL;
    stack->metadata = metadata;
    stack->metadata->size = 0;
    return stack;
}

void stack_clear(Stack stack) {
    if (!stack) return;
    Node head = stack->top;
    while (head) {
        Node tmp = head;
        head = head->next;
        free(tmp);
    }
    stack->top = NULL;
    stack->metadata->size = 0;
}

int stack_size(Stack stack) {
    if(!stack) return 0;
    return stack->metadata->size;
}

bool stack_is_empty(Stack stack) {
    if(!stack) return true;
    return stack_size(stack) == 0;
}

void stack_push(Stack stack, Item item) {
    if (!stack || !item) return;
    Node node = node_create(item);
    node->item = item;
    node->next = stack->top;
    stack->top = node;
    stack->metadata->size++;
}

Item stack_pop(Stack stack) {
    if (!stack) return NULL;
    if (stack_is_empty(stack)) return NULL;
    Node head = stack->top;
    Item item = head->item;
    stack->top = head->next;
    free(head);
    stack->metadata->size--;
    return item;
}

Item stack_peek(Stack stack) {
    if (!stack) return NULL;
    if (stack_is_empty(stack)) return NULL;
    return stack->top->item;
}

void stack_print(Stack stack) {
    if (!stack) return;
    Node x = stack->top;
    if (!x) return;
    while (x){
        printf("[key: %lu, next: %p]", x->key, &x->next);
        x = x->next;
        if (x) printf(" -> ");
    }
    printf("\n");
}
