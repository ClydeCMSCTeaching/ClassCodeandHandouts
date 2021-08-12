#ifndef TREE_H
#define TREE_H

typedef struct btree_node_ btree_node;
struct btree_node_ {
    void* item;
    btree_node* lsub;
    btree_node* rsub;
};


// -1 -> if p1 < p2
// 0 -> p1 == p2
// 1 -> p1 > p2
typedef int (*Comparator)(void*,void*);
typedef void (*Printer)(void*);


typedef struct {
    btree_node* root;
    Comparator comp;
    Printer printer;
} btree;

btree_node* btree_node_create();

btree_node* btree_node_create_with_item(void *item);

void btree_node_destroy(btree_node* node);


btree* btree_create();

void btree_destroy(btree* tree) ;

int btree_isempty(btree* tree);

int btree_node_size(btree_node *node);

int btree_size(btree *tree);

int btree_node_height(btree_node *node);

int btree_height(btree *tree);


btree_node* btree_node_insert(btree_node *node, 
                              void *item, 
                              Comparator comp);


int btree_insert(btree *tree, void* item);

void btree_node_print(btree_node *node, Printer p);

void btree_print(btree *tree);




#endif 