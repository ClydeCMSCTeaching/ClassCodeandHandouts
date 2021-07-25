/* singlemaintemp.c
 * a basic c program which converts a user input
 * Celsius temperature to a F temperature.
 */

#include <stdio.h>
#include <stdlib.h>

/* convert_celsius_to_fahr
 * this function converts a temp in C to F
 * params: 
 *      cel (float) - the temperature in C
 * return:
 *      float - the temoerature in F
 */
float convert_celsius_to_fahr(float cel) {
    float f = (cel * 9) / 5 + 32;
    printf("%lfC == %lfF\n", celsisus, fahr);
}

int main() {
    double fahr, celsisus;

    //print out user information
    printf("This program converts from Celsisus to Fahr.\n");

    //get user input
    printf("Enter a temperature in Celsius >");
    scanf("%lf", &celsisus);

    // calculate the temperature
    fahr = convert_celsius_to_fahr(celsisus);
    
    // output the result
    printf("%lfC == %lfF\n", celsisus, fahr);

    return(0);
}