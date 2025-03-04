/**
 * @file main.c
 * @brief Example demonstrating usage of the Z-transform function
 */
#include <stdio.h>
#include <stdlib.h>
#include "../include/ztransform.h"

int main(void) {
    /* Define a simple unit impulse sequence of length 5 */
    const double sequence[] = {1.0, 1.0, 1.0, 1.0, 1.0};
    const int sequence_length = sizeof(sequence) / sizeof(sequence[0]);
    
    /* Evaluate Z-transform at z = 1 */
    const double complex z_point = 1.0 + 0.0 * I;
    
    /* Compute the Z-transform */
    double complex result = z_transform(sequence, sequence_length, z_point);
    
    /* Print the result */
    printf("X(z) = %.4f%+.6fi\n", creal(result), cimag(result));
    
    return EXIT_SUCCESS;
}