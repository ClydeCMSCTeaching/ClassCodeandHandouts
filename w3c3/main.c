#include <stdlib.h>
#include <stdio.h>

#include "myhash.h"

int main() {
    si_pair p1 = {"Carwyn", 123};
    si_pair p2 = {"Homer", 445};
    si_pair p3 = {"Star", 4223};
    si_pair p4 = {"Neel", 4566};
    si_pair p5 = {"Wasim", 34};
    si_pair p6 = {"Kaisha", 12};
    si_pair p7 = {"Kirby", 2345};
    si_pair p8 = {"Ravinder", 67745};


    LP_HashTable* mytabe = lp_hashtable_create(10);

    lp_hashtable_insert(mytabe, p1);
    lp_hashtable_insert(mytabe, p2);
    lp_hashtable_insert(mytabe, p3);
    lp_hashtable_insert(mytabe, p4);
    lp_hashtable_insert(mytabe, p5);
    lp_hashtable_insert(mytabe, p6);
    lp_hashtable_insert(mytabe, p7);
    lp_hashtable_insert(mytabe, p8);


    lp_hashtable_print(mytabe);


}