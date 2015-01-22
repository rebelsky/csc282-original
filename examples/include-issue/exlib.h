#ifndef __EXLIB_H__
#define __EXLIB_H__

/**
 * exlib.h
 *   Info on sample library functions.
 */

/**
 * Get some data.
 *
 * @pre: data can hold at least two values.
 */
void getData(int *data);

/**
 * Do some computation.
 */
int compute(double x, double y);

#endif // __EXLIB_H__
