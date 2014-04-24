/**
 * ex3.c
 *   An example of an invalid memory reference.
 */


// +---------+---------------------------------------------------------
// | Headers |
// +---------+

#include <assert.h>
#include <stdio.h>


// +---------+---------------------------------------------------------
// | Helpers |
// +---------+

/**
 * A function that returns an array on the stack.
 */
void
vals (int *result[])
{
  int values[10];
  *result = values;
} // vals

/**
 * A function that fills in some values in an array.
 */
void
f (int n)
{
  int i;
  int values[10];
  for (i = 0; i < 10; i++)
    {
      values[i] = n;
    }
} // f


// +------+------------------------------------------------------------
// | Main |
// +------+

int
main (void)
{
  int *stuff;
  vals (&stuff);
  stuff[0] = 42;
  f (5);
  printf ("%d\n", stuff[0] == 42);
  return 0;
} // main
