#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "book.h"

int main() {
    Book *book1 = book_create("Algorithm Design", "Tardos", 2015);
    Book *book2 = book_create("The Waves", "Virgina Woolf", 1939);
    Book *book3 = book_create("The Communist Manifesto", "Marx", 1849);
    Book *book4 = book_create("Being and Time", "Heidgegger", 1931);
    Book *book5 = book_create("Being and Nothingness", "Sartre", 1920);


    // set up our tree
    btree *mytree = btree_create();
    mytree->comp = book_compare_title;
    mytree->printer = book_print;


    btree_insert(mytree, book1);
    btree_insert(mytree, book2);
    btree_insert(mytree, book3);
    btree_insert(mytree, book4);
    btree_insert(mytree, book5);

    btree_print(mytree);

    printf("Size of tree: %d\n", btree_size(mytree));
    printf("Height of tree: %d\n", btree_height(mytree));

    return 0;
}