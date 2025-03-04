#include "ztransform.h"
#include <math.h>
#include <stdlib.h>

/**
 * Computes the Z-transform of a discrete-time signal at a specified point.
 *
 * @param x The input signal array
 * @param N Length of the input signal
 * @param z The complex point at which to evaluate the Z-transform
 * @return The computed Z-transform value as a complex number
 */
double complex z_transform(const double x[], int N, double complex z) {
    double complex X_z = 0.0 + 0.0 * I;
    
    if (x == NULL || N <= 0) {
        return X_z;
    }
    
    for (int n = 0; n < N; n++) {
        X_z += x[n] * cpow(z, -n);
    }
    
    return X_z;
}