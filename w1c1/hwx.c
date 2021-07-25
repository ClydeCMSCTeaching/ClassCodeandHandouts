#include <stdio.h>
#include <stdlib.h>

#include "hwx.h"

/* convert_celsius_to_fahr
 * this function converts a temp in C to F
 * params: 
 *      cel (float) - the temperature in C
 * return:
 *      float - the temoerature in F
 */
float convert_celsius_to_fahr(float cel) {
    float f = (cel * 9.0) / 5.0 + 32;
    return f; 
}