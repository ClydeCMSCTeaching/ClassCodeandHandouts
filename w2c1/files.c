#include <stdio.h>
#include <stdlib.h>

void printFileToTerminal(char *filename) {
    FILE *fp;
    char *line = NULL; // we give the getline function a null pointer, and it will malloc for us
    size_t read = 0;//size_t should be used with fopen
    size_t len = 0; //size_t should be used with fopen
    //size_t is basically an unsigned int or unsigned long depending on computer.

    fp = fopen(filename, "r"); // "r" specifies the file is read not "w" for write
    //check if file was actually opened
    if (fp == NULL) {
        printf("crap, file was not opened successfully... maybe it doesn't exist?\n");
        return;
    }

    //while we successfully read a line, (otherwise the result will be -1 for EOF or error)
    while ((read = getline(&line, &len, fp)) != -1 ) {
        printf("%s", line); // new line is included with the line.
    }
    printf("\n");
}

int main() {
    printFileToTerminal("example.txt");
}
