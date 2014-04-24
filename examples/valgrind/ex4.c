/**
 * ex4.c
 *   An example of using freed memory.
 */


// +---------+---------------------------------------------------------
// | Headers |
// +---------+

#include <stdlib.h>


// +------+------------------------------------------------------------
// | Main |
// +------+

int
main (void)
{
  int *stuff;
  // *stuff = 1;   // Assignment to unitialized memory
  stuff = malloc (sizeof (int));
  *stuff = 1;   // Legal assignment
  free (stuff);
  *stuff = 1;   // Assignment to freed memory
  return 0;
} // main
