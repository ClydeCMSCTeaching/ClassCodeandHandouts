#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

btree_node* btree_node_create() {
    btree_node* b = (btree_node*)malloc(sizeof(btree_node));
    b->item = NULL;
    b->lsub = NULL;
    b->rsub = NULL;
    return b;
}

btree_node* btree_node_create_with_item(void *item) {
    btree_node* b = (btree_node*)malloc(sizeof(btree_node));
    b->item = item;
    b->lsub = NULL;
    b->rsub = NULL;
    return b;
}

void btree_node_destroy(btree_node* node) {
    if (node == NULL) {
        return;
    }
    
    if (node->item != NULL) {
        free(node->item);
    }

    if (node->rsub != NULL) {
        btree_node_destroy(node->rsub);
        node->rsub = NULL;
    } 

    if (node->lsub != NULL) {
        btree_node_destroy(node->lsub);
    }

    free(node);
}


btree* btree_create() {
    btree *tree = (btree*)malloc(sizeof(btree));
    tree->root = NULL;
    return tree;
}

void btree_destroy(btree* tree) {
    btree_node_destroy(tree->root);
    free(tree);
}

int btree_isempty(btree* tree) {
    if (tree == NULL) {
        return 0;
    }

    return (tree->root == NULL) ? 1 : 0; // if (tree->root == NULL) then 1 else 0
}

int btree_node_size(btree_node *node) {
    if (node == NULL) { return 0; }

    return (1 + btree_node_size(node->lsub) 
             + btree_node_size(node->rsub));

}

int btree_size(btree *tree) {
    if (tree == NULL || tree->root == NULL) {
        return 0;
    }   

    return btree_node_size(tree->root);
}

int btree_node_height(btree_node *node) {
    if (node == NULL) {return 0;}

    int l = btree_node_height(node->lsub);
    int r = btree_node_height(node->rsub);

    return 1 + ((l > r) ? l : r); // max (l, r) + 1
}

int btree_height(btree *tree) {
    if (tree == NULL || tree->root == NULL) {
        return 0;
    }   

    return btree_node_height(tree->root);
}


btree_node* btree_node_insert(btree_node *node, 
                              void *item, 
                              Comparator comp) {
    if (node == NULL) {
        btree_node *newnode = btree_node_create();
        newnode->item = item;
        return newnode; // if this first thing is NOT the case
    } else if (comp(item, node->item) < 0) {
        node->lsub = btree_node_insert(node->lsub, item, comp);
    } else if (comp(item, node->item) > 0) {
        node->rsub = btree_node_insert(node->rsub, item, comp);
    } 
    // else { // comp(item, node->item) == 0
    //     return node;
    // }

    return node;
}


int btree_insert(btree *tree, void* item) {
    if (tree) { // if(tree) <==> if(tree == NULL)
        tree->root = btree_node_insert(tree->root, item, tree->comp);
    }
    return 0;
}

void btree_node_print(btree_node *node, Printer p) {
    if (node != NULL) {
        btree_node_print(node->lsub, p);
        p(node->item);
        printf("\n");
        btree_node_print(node->rsub, p);
    }
}

void btree_print(btree *tree) {
    if (tree) {
        btree_node_print(tree->root, tree->printer);
    }
}