/**
 * ex2.c
 *   An example of an invalid memory reference.
 */


// +---------+---------------------------------------------------------
// | Headers |
// +---------+

#include <assert.h>


// +---------+---------------------------------------------------------
// | Helpers |
// +---------+

/**
 * A function that returns an array on the stack.
 */
int *
vals ()
{
  int values[10];
  return values;
} // vals

/**
 * A function that fills in some values in an array.
 */
int
f (int n)
{
  int i;
  int values[10];
  for (i = 0; i < 10; i++)
    {
      values[i] = n;
    }
  return values[2];
} // f


// +------+------------------------------------------------------------
// | Main |
// +------+

int
main (void)
{
  int *stuff = vals ();
  stuff[0] = 25;
  f (5);
  assert (stuff[0] == 25);
  return 0;
} // main
