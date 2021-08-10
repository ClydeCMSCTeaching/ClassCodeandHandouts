#include <stdlib.h>
#include <stdio.h>


typedef struct {
    int r, g, b;
} pixel;




int main() {
    pixel my1dimage[100];

    for (int i = 0; i < 100; i++ ){
        my1dimage[i] = (pixel) {150, 234, 43};
    }

    for (int i =0; i< 100;i++ ){
        printf("(%d, %d, %d) ", my1dimage[i].r, my1dimage[i].b, my1dimage[i].g);
    }
    printf("\n");

}