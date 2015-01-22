/**
 * A simple example of #include.
 */

#include <stdio.h>
#include "exlib.h"

int
main (int argc, char *argv[])
{
  int data[2];
  getData (data);
  printf ("compute (%d,%d) = %d\n", 
          data[0], data[1], 
          compute (data[0],data[1]));
  return 0;
} // main(int)
