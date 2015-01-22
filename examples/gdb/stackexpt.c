#include <stdio.h>

void
foo (int x)
{
  printf ("x is at %p\n", &x);
  if (x > 0)
    foo (x-1);
}

int
main (int argc, char *argv[])
{
  foo (5);
  return 0;
} // main
