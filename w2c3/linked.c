#include <stdlib.h>
#include <stdio.h>


typedef int elem;
typedef struct list_node list;
struct list_node {
    elem item;
    list* next;
};

list* createLinkedList(elem item) {
    list* node = (list*) malloc(sizeof(list));
    node->item = item;
    node->next = NULL;
}

list* destroyLinkedList(list *start) {
    list *pos = start;
    list *prev = pos;
    while(pos != NULL) {
        pos = pos->next;
        free(prev);
        prev = pos;
    }
}

void printList(list *start) {
    list *pos = start;
    while(pos != NULL) {
        printf("%d ", pos->item);
        pos = pos->next;
    }
    printf("\n");
}

void appendList(list* start, elem item) {
    list* newNode = (list*) malloc(sizeof(list));
    newNode->item = item;
    newNode->next = NULL;

    list* pos = start;
    while(pos->next != NULL) {
        pos = pos->next;
    }
    //pos now equals the end of the list
    pos->next = newNode;
}

  ///  something -> somethign_else

void removeList(list* start, list* removeNode) {
    list *pos = start;

    while(pos != NULL && pos->next != removeNode) {
        pos = pos->next;
    }
    /// pos->next ===== the node we want to remove
    pos->next = removeNode->next;
    free(removeNode);
}

list* findList(list *start, elem item) {

    for (list *pos = start; pos != NULL; pos = pos->next) 
        if (pos -> item == item )
            return pos;
    return NULL;
}


int main() {    

    list* start = createLinkedList(0);
    appendList(start, 1);
    appendList(start, 10);
    appendList(start, 100);


    list* whereIsThe10Node = findList(start, 10);

    printf("This is the list:\n");
    printList(start);
    printf("This is where 10 is (in memory)\n");
    printf("%p\n", whereIsThe10Node);
    removeList(start, whereIsThe10Node);
    printf("now we removed it\n");
    printList(start);



}