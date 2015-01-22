/**
 * ex1.c
 *   A problem with a few memory errors.  Stolen from
 *    http://valgrind.org/docs/manual/quick-start.html#quick-start.interpret
 */

#include <stdlib.h>

void 
f (void)
{
  int* x = malloc(10 * sizeof(int));
  // int x[10]; // Can we catch errors using this?  Maybe not.
  x[10] = 0;        // problem 1: heap block overrun
  x[-1] = 0;        // problem 2: heap block underrun
                    // problem 3: memory leak -- x not freed
} // f

int 
main(void)
{
  f();
  return 0;
} // main
