#include <stdio.h>
#include <stdlib.h> 

typedef struct sllist_node sllist;
struct sllist_node {
    void *item;
    sllist *next;
};

sllist* sllist_create() {
    return (sllist*)malloc(sizeof(sllist));
}

sllist* sllist_create_with_item(void * item) {
    sllist *myitem = (sllist*)malloc(sizeof(sllist));
    myitem->item = item;
    return myitem;
}

void sllist_append(sllist *list, void *item) {
    while(list != NULL && list->next != NULL) {
        list = list->next;
    }
    list->next = sllist_create_with_item(item);
}



void* sllist_iterate(sllist *list) {
    static sllist *cur_node; 

    // THIS IS FOR SETTING THE ITERATOR (OR STARTING IT)
    if (list != NULL) {
        cur_node = list;
        return NULL;
    } 


    // THIS IS FOR CHECKING IF WE ARE DONE ITERATING
    if (cur_node == NULL) {
        return NULL;
    }
    
    // keep going and iterating
    void* item = cur_node->item;
    cur_node = cur_node->next;
    return item;    
}


void* sllist_index(sllist *list, int index){
    sllist_iterate(list);
    int i = 0;
    for (void *p = sllist_iterate(NULL); p != NULL; p = sllist_iterate(NULL), i++) {
        if (index == i) {
            return p;
        }
    }
    return NULL;
}


void* sllist_head(sllist *list, int index){
    sllist_iterate(list);
    int i = 0;
    for (void *p = sllist_iterate(NULL); p != NULL; p = sllist_iterate(NULL), i++) {
        return p;
    }
    return NULL;
}

void* sllist_tail(sllist *list, int index){
    sllist_iterate(list);
    void *tmp = NULL;
    int i = 0;
    for (void *p = sllist_iterate(NULL); p != NULL; p = sllist_iterate(NULL), i++) {
        tmp = p;
    }
    return tmp;
}


typedef struct dllist_node dllist;
struct dllist_node {
    void *item;
    dllist *prev;
    dllist *next;
};


typedef struct {
    sllist* bottom_of_stack;
} stack;

void push(stack *stack, void *item) {
    //find the top of the stack

    sllist* pos = stack->bottom_of_stack;

    while(pos->next != NULL) {
        pos = pos->next;
    }
    // now pos is the top of the stack
    pos->next = sllist_create_with_item(item);
}

void* pop(stack *stack) {
    sllist* pos = stack->bottom_of_stack;

    while(pos->next != NULL && pos->next->next == NULL) {
        pos = pos->next;
    }
    // now pos is second to top of the stack
    void *item = pos->next->item; //get the top of stack item
    free(pos->next); // free the top of stack
    pos->next = NULL; //set the second top (now new top)

    return item;
}




int main() {
    //this is just init a linked list with 6 numbers
    int myInts[6] = {1, 2, 3, 4, 5, 6};
    sllist *myintlist = sllist_create_with_item((void*) myInts);
    for (int i = 1;  i < 6; i++) {
        sllist_append(myintlist, (void*)(myInts + i));
    }

    // showing how we use iterators
    sllist_iterate(myintlist); //start the iterator 
    for (void *p = sllist_iterate(NULL); p != NULL; p = sllist_iterate(NULL)) {
        printf("iterating the list... %d\n", *((int*)p));
    }


    printf("This is the 3rd thing: %d\n", *((int*)sllist_index(myintlist, 3)) );

}