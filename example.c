#include <stdio.h>
#include "data_structures.h"

void example_linked_list() {
  puts("\nexample_linked_list start");

  LinkedList* list = linked_list_create();
  Node* helloNode1 = node_create(item_create("Hello1", 5));
  linked_list_append(list, helloNode1);
  Node* helloNode2 = node_create(item_create("Hello2", 5));
  linked_list_prepend(list, helloNode2);

  printf("Size of the list is %d\n", linked_list_size(list));
  linked_list_print(list);

  Node* node = linked_list_search(list, node_get_key(helloNode1));

  for (int i = 0; i < node_get_item(node)->size; ++i) {
    printf("%c", node_get_item(node)->data[i]);
  }
  printf("\n");

  linked_list_delete(list, node_get_key(node));
  printf("Size of the list is %d\n", linked_list_size(list));

  puts("example_linked_list end");
}

void example_stack() {
  puts("\nexample_stack start");

  Stack* stack = stack_create();
  Item* item1 = item_create("Hello1", 5);
  stack_push(stack, item1);
  Item* item2 = item_create("Hello2", 5);
  stack_push(stack, item2);
  Item* item3 = item_create("Hello3", 5);
  stack_push(stack, item3);

  printf("Size of the stack is %d\n", stack_size(stack));
  stack_print(stack);

  Item* item = stack_pop(stack);
  for (int i = 0; i < item->size; ++i) {
    printf("%c", item->data[i]);
  }
  printf("\n");

  printf("Size of the stack is %d\n", stack_size(stack));

  stack_clear(stack);
  printf("Size of the stack is %d\n", stack_size(stack));

  puts("\nexample_stack end");
}

void example_queue() {
  puts("\nexample_queue start");

  Queue* queue = queue_create();
  Item* item1 = item_create("Hello1", 5);
  queue_enqueue(queue, item1);
  Item* item2 = item_create("Hello2", 5);
  queue_enqueue(queue, item2);
  Item* item3 = item_create("Hello3", 5);
  queue_enqueue(queue, item3);

  printf("Size of the queue is %d\n", queue_size(queue));
  queue_print(queue);

  Item* item = queue_dequeue(queue);
  for (int i = 0; i < item->size; ++i) {
    printf("%c", item->data[i]);
  }
  printf("\n");

  printf("Size of the queue is %d\n", queue_size(queue));

  queue_clear(queue);
  printf("Size of the queue is %d\n", queue_size(queue));

  puts("\nexample_queue end");
}

int main() {
  example_linked_list();
  example_stack();
  example_queue();
  return 0;
}
