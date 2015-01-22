/**
 * ex0.c
 *   A not-so valid program
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
  int *ip = malloc (sizeof (int));
  int *jp = ip;
  // ...
  free (ip);
  free (jp);
  return 0;
} // main
