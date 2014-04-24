/** 
 * expt1a.c
 *   An experiment to see how strings_sort works.  Sorts the strings
 *   entered on the command line.
 */


// +---------+---------------------------------------------------------
// | Headers |
// +---------+

#include <stdio.h>
#include <string.h>

#include "sort1.h"


// +------+------------------------------------------------------------
// | Main |
// +------+

int
main (int argc, char *argv[])
{
  int i;
  strings_sort (argc-1, argv+1, strcmp);
  for (i = 1; i < argc; i++)
    printf ("%s\n", argv[i]);
  return 0;
} // main

