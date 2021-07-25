/* singlemaintemp.c
 * a basic c program which converts a user input
 * Celsius temperature to a F temperature.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    double fahr, celsius; 

    //print out user information
    printf("This program converts from C to F\n");

    //get user input
    printf("Enter a temperature in Celsius >");
    scanf("%lf", &celsius);

    //convert the temp
    fahr = (celsius * 9.0) / 5.0 + 32;

    //display to the user
    printf("%lfC == %lfF\n", celsius, fahr);

    //return program success
    return(0);


}