/**
 * Some fun with arrays and their sizes, using a macro that ML found
 * in the wild.
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

int
whatever (int vals[])
{
  fprintf (stdout, "The size of vals is %d\n", ARRAY_SIZE(vals));
} // whatever(int[])

int
main (int argc, char *argv[])
{
  int a1[] = { 1, 2, 3, 4, 5 };
  long a2[10];
  double *a3 = (double *) malloc (sizeof (double) * 15);

  fprintf (stdout, "Number of elements in a1: %d\n", ARRAY_SIZE (a1));
  fprintf (stdout, "Number of elements in a2: %d\n", ARRAY_SIZE (a2));
  fprintf (stdout, "Number of elements in a3: %d\n", ARRAY_SIZE (a3));
  fprintf (stdout, "Number of elements in argv: %d\n", ARRAY_SIZE (argv));

  whatever (a1);

  exit (0);
} // main (stdout, int, char*)
