#ifndef ZTRANSFORM_H
#define ZTRANSFORM_H

#include <complex.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Computes the Z-transform of a given sequence.
 *
 * @param x The input sequence.
 * @param N The length of the input sequence.
 * @param z The complex variable for the Z-transform.
 * @return The computed Z-transform as a complex number.
 */
double complex z_transform(const double x[], int N, double complex z);

#ifdef __cplusplus
}
#endif

#endif // ZTRANSFORM_H