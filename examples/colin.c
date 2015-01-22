/**
 * Experiments with various forms of max.
 */

#include <stdio.h>

#define MAX(a,b) (((a) > (b)) ? (a) : (b));

int 
max (int a, int b)
{
  if (a > b)
    return a;
  else
    return b;
} // max(int,int)

static inline int
imax (int a, int b)
{
  if (a > b)
    return a;
  else
    return b;
} // imax(int, int)

int 
main(int argc, char *argv[])
{
  int a = 2;
  int b = 3;
  int c = 0;
  printf ("a = %d, b = %d, c = %d\n", a, b, c);

  c = MAX(a++,b++);
  printf ("a = %d, b = %d, c = %d\n", a, b, c);

  c = max(a++,b++);
  printf ("a = %d, b = %d, c = %d\n", a, b, c);

  c = imax(a++,b++);
  printf ("a = %d, b = %d, c = %d\n", a, b, c);

} // main(int, char *[])
