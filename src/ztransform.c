#include <complex.h>
#include <math.h>

/**
 * Computes the Z-transform of a discrete-time signal x[n] at a specified complex point z.
 * The Z-transform is defined as:
 *     X(z) = sum_{n=0}^{N-1} x[n] * z^{-n}
 *
 * @param x The input signal array, where x[n] is the sample at time n, for n=0 to N-1
 * @param N Length of the input signal (number of samples)
 * @param z The complex point at which to evaluate the Z-transform
 * @return The computed Z-transform value X(z) as a complex number
 * @note If x is NULL or N <= 0, the function returns 0 + 0i
 * @warning The function may exhibit numerical instability for certain values of z or large N
 */
double complex z_transform(const double x[], int N, double complex z) {
    double complex X_z = 0.0 + 0.0 * I;

    // Input validation: return 0 for invalid inputs
    if (x == NULL || N <= 0) {
        return X_z;
    }

    // Compute z inverse once to optimize the loop
    double complex z_inv = 1.0 / z;
    double complex power = 1.0; // z^0 = 1

    // Compute the Z-transform sum iteratively
    for (int n = 0; n < N; n++) {
        X_z += x[n] * power;
        power *= z_inv;
    }

    return X_z;
}