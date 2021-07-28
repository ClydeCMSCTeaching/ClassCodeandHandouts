#include <stdlib.h>
#include <stdio.h>

/*
 * prints day of week in words from code
 * returns 0 if no error, 1 if there was an error
 */
unsigned int printWeekday(char daycode) {
    switch (daycode) {
        case 'M':
        case 'm': 
                printf("Monday\n");
                break;

        case 'T':
        case 't':
                printf("Tuesday\n");
                break;

        case 'W':
        case 'w':
                printf("Wednesday\n");
                break;

        case 'R':
        case 'r':
                printf("Thursday\n");
                break;

        case 'F':
        case 'f':
                printf("Friday\n");
                break;

        case 'S':
        case 's':
                printf("Saturday\n");
            
        case 'U':
        case 'u':
                printf("Sunday\n");

        default: // no char matches, so there is an error
                return 1;
    }

    return 0;
}

int main() {
    unsigned int errCode;
    char userInput; 
    printf("Enter a single letter day code >");
    scanf("%c", &userInput);

    errCode = printWeekday(userInput);

    return(errCode);
}