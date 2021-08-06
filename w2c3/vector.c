#define SIZE_CHUNKS 5
#define DEBUG 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "vector.h"


VectorInt_T* createVectorInt(size_t initCap) {
    VectorInt_T *newVec = (VectorInt_T *)malloc(sizeof(VectorInt_T));
    newVec->array = (int*)malloc(initCap * sizeof(int));
    newVec->capacity = initCap;
    newVec->length = 0;
    return newVec;
}

//less preferred, functional style less c-like style
VectorInt_T createVectorIntStack(size_t initCap) {
    VectorInt_T newVec;
    newVec.array = (int*)malloc(initCap * sizeof(int));
    newVec.capacity = initCap;
    newVec.length = 0;
    return newVec;
}
void destroyHeapVec(VectorInt_T myVec) {
    free(myVec.array);
}

void freeVectorInt(VectorInt_T *myVec){ 
    free(myVec->array);
    free(myVec);
}

void resizeVectorInt(VectorInt_T *myVec, size_t newSize) {
    // create a new array
    int *newArray = (int *)malloc(newSize * sizeof(int));

    //copy old stuff
    memcpy(newArray, myVec->array, myVec->length * sizeof(int));

    //free old one
    free(myVec->array);

    //set the new array to be in myVec
    myVec->array = newArray;
    myVec->capacity = newSize;
}

void printVectorInt(VectorInt_T *myVec) {
    for(int i = 0; i < myVec->capacity; i++) {
        if (i < myVec->length) 
            printf("%d ", myVec->array[i]);
        else if (DEBUG) // i > the length, but we want to show empty buckets
            printf("_ ");
    }
    printf("\n");
}

void appendVectorInt(VectorInt_T *myVec, int newElement) {
    // check if I need to resize
    if (myVec->capacity <= 0 || myVec->capacity == myVec->length) {
        resizeVectorInt(myVec, myVec->capacity + SIZE_CHUNKS); // if we do, we resize it more than we need to avoid having to do all the resizing
    }

    myVec->array[myVec->length] = newElement;
    myVec->length += 1;
}
