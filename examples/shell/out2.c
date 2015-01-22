/**
 * out2.c
 *   A simple program that prints output to both stdout and stderr.
 */


// +---------+---------------------------------------------------------
// | Headers |
// +---------+

#include <stdio.h>


// +------+------------------------------------------------------------
// | Main |
// +------+

int
main (int argc, char *argv[])
{
  fprintf (stdout, "Hello.  My name is %s.\n", argv[0]);
  fprintf (stderr, "Warning!  The system is going down in 30 seconds.\n");
  fprintf (stdout, "And now I will say goodbye.\n");
  fprintf (stderr, "Or maybe 11.2 seconds!.\n");
  fprintf (stdout, "Goodbye.\n");
  return 0;
} // main
