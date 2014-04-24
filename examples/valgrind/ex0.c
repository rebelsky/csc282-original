/**
 * ex0.c
 *   A perfectly valid program (or so I hope).
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
  int i;
  for (i = 0; i < 100; i++)
    {
      int *stuff = malloc (sizeof (int));
      *stuff = i;
      free (stuff);
    }
  return 0;
} // main
