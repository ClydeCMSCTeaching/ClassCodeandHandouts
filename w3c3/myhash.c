#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myhash.h"
 
LP_HashTable* lp_hashtable_create(size_t size) {
    LP_HashTable* tb = (LP_HashTable*)malloc(sizeof(LP_HashTable));
    tb->table_size = size;
    tb->table = (si_pair*)malloc(size * sizeof(si_pair));
    for (int i = 0; i < size; i++) {
        tb->table[i].key = NULL;
        tb->table[i].value = 0;
    }
    return tb;
}


void lp_hashtable_destroy(LP_HashTable* tb) {
    free(tb->table);
    free(tb);
}


void lp_hashtable_print(LP_HashTable* tb) {
    ///print buckets
    for (int i = 0; i < tb->table_size; i++) {
        printf("|%d|\t", i);
    }
    printf("\n");

    //print keys
    for (int i = 0; i < tb->table_size; i++) {
        if (tb->table[i].key == NULL) {
            printf("|NULL|\t");
        } else {
            printf("|%s|\t", tb->table[i].key);
        }
    }
    printf("\n");

    //print values
        for (int i = 0; i < tb->table_size; i++) {
        if (tb->table[i].key == NULL) {
            printf("|NULL|\t");
        } else {
            printf("|%d|\t", tb->table[i].value);
        }
    }
    printf("\n");

}


//beacuse tables can be different sizes, you need a function to convert a hash 
// the size hash you are working with
int getHash(LP_HashTable* tb, int hash) {
    return hash % tb->table_size;
}

//our lookuip
int lp_hashtable_get(LP_HashTable* tb, Key_t key, si_pair* found_item) {
    int hash_to_find = getHash(tb, strHash(key));

    //check if that spot is open
    if (tb->table[hash_to_find].key == NULL) {
        return -1;
    } else { // spot has something there
        if (strcmp(tb->table[hash_to_find].key, key) == 0) {
            *found_item = tb->table[hash_to_find];
            return 0;
        } else { // we need to probe
            for (int i = 0; i < tb->table_size; i++) {
                int spot = ( hash_to_find + i ) % tb->table_size;
                if (tb->table[spot].key == NULL) {
                    return -1;
                } else { // there is something let's check
                    if (strcmp(tb->table[spot].key, key) == 0) {
                                *found_item = tb->table[spot];
                                return 0;
                    }
                }
            }
        }
    }

    return -1;
}



int strHash(char *str) {
    int h = 0;
    while(*str != '\0') {
        h += (int) (*str);
        str += 1;
    }
    return h;
}

void lp_hashtable_insert(LP_HashTable* tb, si_pair item) {
    // first hashes the the string, then hashes to be the right size
    int hash_to_insert = getHash(tb, strHash(item.key));


    //check if that spot is open
    if (tb->table[hash_to_insert].key == NULL) {
        tb->table[hash_to_insert] = item;
        return;
    } else { // spot is not open, we need to probe
        
        for (int i = 1; i < tb->table_size; i++) {
            int spot = (hash_to_insert + i) % tb->table_size;
            if (tb->table[spot].key == NULL) {
                tb->table[spot] = item;
                return;
            }
        }
    }

    printf("No spots left... table is full\n");
}

void lp_hashtable_resize(LP_HashTable *tb, size_t new_size) {

    LP_HashTable new_table;
    new_table.table = (si_pair*)malloc(new_size * sizeof(si_pair));
    new_table.table_size = new_size;

    for (int i = 0; i < tb->table_size; i++) {
        if (tb->table[i].key != NULL) {// if item is there 
            lp_hashtable_insert(&new_table, tb->table[i]);
        }
    }
    free(tb->table);

    tb->table = new_table.table;
    tb->table_size = new_size;
}
