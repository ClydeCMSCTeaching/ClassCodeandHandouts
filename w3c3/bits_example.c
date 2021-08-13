#include <stdio.h>
#include <stdlib.h>


typedef struct {
    unsigned int is_spotted      : 1;
    unsigned int price           : 3;
    unsigned int ignore          : 10;
    unsigned int specialNumber   : 5;
    unsigned int ignore2         : 13;
} SpecialMessage;

void printMessageSemantics(SpecialMessage m) {
    printf("Message:\n");
    printf("\t isSpotted: %s\n", (m.is_spotted == 0) ? "FALSE" : "TRUE");
    printf("\t price: %u\n", m.price);
    printf("\t specialNumber: %u\n", m.specialNumber);
}

SpecialMessage readMessage(unsigned int m) {
    return *((SpecialMessage*) &m);
}


unsigned int encodeMessage(SpecialMessage m) {
    return *((unsigned int*) &m); // hack... you can't cast anything to anythhing, but you can cast a pointer to any other pointer
}

unsigned int encodeMessageShifting(SpecialMessage m) {
    unsigned int enc = 0;
    enc += (m.specialNumber << 13);
    enc += (m.price << 1);
    enc += m.is_spotted;
    return enc;
}

SpecialMessage readMessageShifting(int m) {
    SpecialMessage enc;

    unsigned int is_spotted_mask = 1;
    enc.is_spotted = (m & is_spotted_mask);

    unsigned int price_mask = 14;
    enc.price = (m & price_mask) >> 1;

    unsigned int specialNumber_mask = 253952;
    enc.specialNumber = (m & specialNumber_mask) >> 14;
    return enc;
}

int main() {
    printf("Size of my message %lu bytes\n", sizeof(SpecialMessage));
    unsigned int message;
    SpecialMessage read; 

    message = 1;
    printf("The message is encoded in the number %d.\n",  message);
    read = readMessage(message);
    printMessageSemantics(read);
    printf("\n\n");

    message = 1 + 2*2*2;
    printf("The message is encoded in the number %d.\n",  message);
    read = readMessage(message);
    printMessageSemantics(read);
    printf("\n\n");

    message = 2342983;
    printf("The message is encoded in the number %d.\n",  message);
    printf("Read from casting ");
    read = readMessage(message);
    printMessageSemantics(read);
    printf("Read from shfting ");
    read = readMessageShifting(message);
    printMessageSemantics(read);
    printf("\n\n");
}