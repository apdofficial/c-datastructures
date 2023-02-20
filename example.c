#include <stdio.h>
#include "data_structures.h"

int main() {
    LinkedList list = linked_list_create();
    Node helloNode1 = node_create(item_create("Hello1", 5));
    linked_list_append(list, helloNode1);
    Node helloNode2 = node_create(item_create("Hello2", 5));
    linked_list_prepend(list, helloNode2);

    printf("Size of the list is %d\n", linked_list_size(list));
    linked_list_print(list);

    Node node = linked_list_search(list,node_get_key(helloNode1));

    for (int i = 0; i < node_get_item(node)->size; ++i){
        printf("%c", node_get_item(node)->data[i]);
    }
    printf("\n");

    linked_list_delete(list, node_get_key(node));
    printf("Size of the list is %d\n", linked_list_size(list));
    return 0;
}
