/**
 * Fun with assert.
 */

#include <assert.h>
#include <stdio.h>

int
main (int argc, char *argv[])
{
  printf("Stuff\n");
  assert(1 == 1);
  printf("More Stuff\n");
  assert(1 == 2);
  printf("Even More Stuff\n");
  return 0;
} // main
