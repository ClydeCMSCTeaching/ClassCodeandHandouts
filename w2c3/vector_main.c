#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vector.h"


int main() {
    VectorInt_T* myHeapVec = createVectorInt(5);

    printVectorInt(myHeapVec);

    appendVectorInt(myHeapVec, 6);
    appendVectorInt(myHeapVec, 12);
    appendVectorInt(myHeapVec, 14);
    appendVectorInt(myHeapVec, 2345);
    appendVectorInt(myHeapVec, 7);


    appendVectorInt(myHeapVec, 8);
    appendVectorInt(myHeapVec, 7);
    appendVectorInt(myHeapVec, 7);
    appendVectorInt(myHeapVec, 7);
    appendVectorInt(myHeapVec, 7);
    appendVectorInt(myHeapVec, 7);
    appendVectorInt(myHeapVec, 7);
    appendVectorInt(myHeapVec, 7);
    appendVectorInt(myHeapVec, 7);
    appendVectorInt(myHeapVec, 7);


    printVectorInt(myHeapVec);

    freeVectorInt(myHeapVec);
}

