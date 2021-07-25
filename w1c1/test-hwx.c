#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include "hwx.h"

/*
 * test_convert_celsius_to_fahr
 * tests the function convert_celsius_to_fahr in "hwx.h" 
 * params:
 *      celsius (double) - temp to convert
 *      expected (double) - resulting value
 *      accuracy (double) - tolerence to error 
 * returns:
 *      unsigned int - returns 1 if test passes, 0 otherwise
 */
unsigned int test_convert_celsius_to_fahr(double celsisus, double expected, double accuracy){
    double fahr, difference;

    fahr = convert_celsius_to_fahr(celsisus);
    difference =  fabs(fahr - expected); // fabs is abs but for double/float
    
    if (difference <= accuracy) {
        printf("Test passed: %lfC -> %lfF, expected %lfF\n", celsisus, fahr, expected); 
        return(1);
    }
    // why isn't an else needed?
    printf("Test FAILED: %lfC -> %lfF, expected %lfF\n", celsisus, fahr, expected); 
    return(0);
}

int main() {
    double fahr, celsius;
    unsigned int total_tests = 0, passed_tests = 0;
    printf("This program tests a function to convert C to F.\n");

    passed_tests += test_convert_celsius_to_fahr(100.0, 212.0, 0.5);
    total_tests++;

    printf("Passed %u tests out of %u total.\n", passed_tests, total_tests);
}