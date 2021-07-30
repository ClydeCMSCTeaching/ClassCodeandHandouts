#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define SPECIAL_SLOPE 0.0

int main() {
  double slope, y2, y1, x2, x1;

  printf("enter some numbers >");

  
  /*  for (slope = (y2 - y1) / (x2 - x1);
#       slope != SPECIAL_SLOPE;
       slope = (y2 - y1) / (x2 - x1)) {

    printf("The slope is %5.2f.\n", slope);
    printf("enter some numbers >");
    scanf("%lf%lf%lf%lf", &y2, &y1, &x2, &x1);  
    } */

  scanf("%lf%lf%lf%lf", &y2, &y1, &x2, &x1);
  slope = (y2 - y1) / (x2 - x1);
  while ( slope != SPECIAL_SLOPE) {
    printf("The slope is %f.\n", slope); // inside of print states floats -> f
    printf("enter some numbers >");
    scanf("%lf%lf%lf%lf", &y2, &y1, &x2, &x1);

    slope = (y2 - y1) / (x2 - x1);
  }

  

  return(0);
}


