/**
 * env.c
 *   A simple hack to print an enviornment variable.  Intended mostly
 *   as an example of getenv in C.
 */


// +---------+---------------------------------------------------------
// | Headers |
// +---------+

#include <stdio.h>
#include <stdlib.h>


// +------+------------------------------------------------------------
// | Main |
// +------+

int
main (int argc, char *argv[])
{
  int i;
  for (i = 1; i < argc; i++)
    {
      char *val = getenv (argv[i]);
      if (val == NULL)
        printf ("%s is <UNDEFINED>\n", argv[i]);
      else
        printf ("%s is %s\n", argv[i], getenv (argv[i]));
    } // for
  return 0;
} // main
