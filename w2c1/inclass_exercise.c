
#include <stdlib.h>
#include <stdio.h>

/*
 * Write a function which takes an int array and prints to the screen every negitive number. 
 */
void printNeg(int myArr[], int size_myArr) {
    for (int i = 0; i < size_myArr; i++) {
        if (myArr[i] < 0) {
            printf("%d\n", myArr[i]);
        }
    }
}

/*
 * Write a function which takes a string and prints the first word (or the whole string if there are no spaces in the string). 
 * mystr MUST BE A STRING WHICH IS NULL TERMINATED
 */
void printFirstWord(char mystr[]) {
    int counter = 0;
    while ( mystr[counter] != ' ' &&  mystr[counter] != '\0') {
        printf("%c", mystr[counter]);
        counter++;
    }
    printf("\n");    

    /// The problem with this solution 
    // but you modified the array
    // int counter =0;
    // while(mystr[counter] != ' ' || mystr[counter] != '\0') {
    //     counter++;
    // }
    // // okay so from 0 to counter, there is a word 
    // mystr[counter] = '\0';
    // printf("%s\n", mystr)
    
}

int main() {
    int myArr[] = {1, 2, -2, 3, -4};

    printNeg(myArr, 5);

    char mystr[] = "hello how are you?";
    printFirstWord(mystr);
}