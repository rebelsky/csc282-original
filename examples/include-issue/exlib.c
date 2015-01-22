/**
 * A simple library for an example of #include.
 */
#include "exlib.h"

void
getData (int *data)
{
  data[0] = 1;
  data[1] = 2;
} // getData (int *)

int
compute (double x, double y)
{
  return (int) (x + y);
} // compute (double,double)
