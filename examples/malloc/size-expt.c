/**
 * size-expt.c
 *   A quick (FAILED) experiment to see how well Sam can guess 
 *   malloc's strategy for keeping track of the size of an allocated
 *   chunk.  (My hypothesis was that malloc used the  ...)
 */

#include <stdio.h>
#include <stdlib.h>

#define PRINT_EXP(EXP,TYPESTR) \
  printf (#EXP ": " TYPESTR "\n", EXP)

int
main (int argc, char *argv[])
{
  int *foo = malloc (10 * sizeof(int));
  int *bar = malloc (128 * sizeof(int));
  char *baz = malloc (10);

  PRINT_EXP (foo[-1], "%d");
  PRINT_EXP (bar[-1], "%d");
  PRINT_EXP (baz[-1], "%d");

  foo[-1] = 30;
  free (foo);

  return 0;
} // main 
