#ifndef HASH_H
#define HASH_H

#include <stdlib.h>

typedef char *Key_t;
typedef int value_t;

typedef struct {
    Key_t key;
    value_t value;
} si_pair;



typedef struct {
    si_pair *table;
    size_t table_size;
} LP_HashTable;


LP_HashTable* lp_hashtable_create(size_t size);
void lp_hashtable_destroy(LP_HashTable* tb);


//beacuse tables can be different sizes, you need a function to convert a hash 
// the size hash you are working with
int gethash(LP_HashTable* tb, int hash);
int strHash(char *str);

//our lookuip
int lp_hashtable_get(LP_HashTable* tb, Key_t key,  si_pair* found);

void lp_hashtable_insert(LP_HashTable* tb, si_pair item); 

void lp_hashtable_resize(LP_HashTable *tb, size_t new_size);

void lp_hashtable_print(LP_HashTable *tb);


#endif