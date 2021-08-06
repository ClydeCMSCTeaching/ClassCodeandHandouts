#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
    int *array;
    size_t length;
    size_t capacity;
} VectorInt_T;

VectorInt_T* createVectorInt(size_t initCap);

//less preferred, functional style less c-like style
VectorInt_T createVectorIntStack(size_t initCap);

void destroyHeapVec(VectorInt_T myVec);

void freeVectorInt(VectorInt_T *myVec);

void resizeVectorInt(VectorInt_T *myVec, size_t newSize);

void resizeVectorInt(VectorInt_T *myVec, size_t newSize);

void printVectorInt(VectorInt_T *myVec);

void appendVectorInt(VectorInt_T *myVec, int newElement);

#endif 