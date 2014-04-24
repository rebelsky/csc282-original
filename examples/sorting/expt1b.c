/** 
 * expt1a.c
 *   An experiment to see how strings_sort works.  Sorts the strings
 *   entered on the command line by size.
 */


// +---------+---------------------------------------------------------
// | Headers |
// +---------+

#include <stdio.h>
#include <string.h>

#include "sort1.h"


// +---------------+---------------------------------------------------
// | Local Helpers |
// +---------------+

/**
 * Compare two strings by size.
 */
static int
strcmp_size (char *str1, char *str2)
{
  return (strlen (str1) - strlen (str2));
} // strcmp_size

static int
strcmp_size_report (char *str1, char *str2)
{
  int result = strcmp_size (str1, str2);
  if (result < 0)
    fprintf (stderr, "%s < %s\n", str1, str2);
  else if (result >= 0)
    fprintf (stderr, "%s > %s\n", str1, str2);
  else
    fprintf (stderr, "%s == %s\n", str1, str2);
  return result;
} // strcmp_size_report


// +------+------------------------------------------------------------
// | Main |
// +------+

int
main (int argc, char *argv[])
{
  int i;
  strings_sort (argc-1, argv+1, strcmp_size);
  for (i = 1; i < argc; i++)
    printf ("%s\n", argv[i]);
  return 0;
} // main

