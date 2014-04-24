/**
 * ex5.c
 *   An example of using freed memory.
 */


// +---------+---------------------------------------------------------
// | Headers |
// +---------+

#include <assert.h>
#include <stdlib.h>


// +------+------------------------------------------------------------
// | Main |
// +------+

int
main (void)
{
  int *stuff;
  int *answer;
  // *stuff = 1;   // Assignment to unitialized memory
  stuff = malloc (sizeof (int));
  *stuff = 1;   // Legal assignment
  free (stuff);
  answer = malloc (sizeof (int));
  *answer = 42;
  *stuff = 1;   // Assignment to freed memory
  assert (*answer == 42);
  free (answer);
  return 0;
} // main
