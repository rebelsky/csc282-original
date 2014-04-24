/**
 * ex4.c
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
  int *more;
  // *stuff = 1;   // Assignment to unitialized memory
  stuff = malloc (sizeof (int));
  *stuff = 1;   // Legal assignment
  free (stuff);
  more = malloc (sizeof (int));
  *more = 2;
  *stuff = 1;   // Assignment to freed memory (and potentially reused mem)
  assert (*more == 2);
  return 0;
} // main
