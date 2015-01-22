/**
 * A quick and dirty example of the "amazing" debugging library.
 */


// +---------+---------------------------------------------------------
// | Headers |
// +---------+

#include "log.h"


// +---------+---------------------------------------------------------
// | Helpers |
// +---------+

int 
fib (int n)
{
  if (n <= 1)
    return 0;
  else
    return fib (n-1) + fib (n-2);
} // fib (int)


// +------+------------------------------------------------------------
// | Main |
// +------+

int 
main (int argc, char *argv[])
{
  MSG("Starting");
  int i;
  DO(i = 5);
  IVAR(i);
  IVAR(i*i);
  DO(i++);
  IVAR(i);
  DO(++i);
  MSG("Ending");
  return 0;
} // main (int, char *)
