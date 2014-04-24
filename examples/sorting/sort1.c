/**
 * sort1.c
 *   A simple implementation of string sorting.
 */


// +---------+---------------------------------------------------------
// | Headers |
// +---------+

#include <stdio.h>
#include <string.h>
#include "sort1.h"


// +---------+---------------------------------------------------------
// | Helpers |
// +---------+

static int
strings_index_of_largest (int n, char *strings[], StringComparator compare)
{
  int guess = 0;        // Our current guess as to the biggest string
  int i;
  // Look at each string in turn
  for (i = 1; i < n; i++)
    {
      // If the ith element is bigger
      if (compare (strings[guess], strings[i]) < 0)
        {
          // Update our guess
          guess = i;
        } // if ith elt is bigger
    } // for each string
  // And we're done
  return guess;
} // strings_index_of_largest

int
strings_swap (int n, char *strings[], int i, int j)
{
  char *tmp = strings[i];
  strings[i] = strings[j];
  strings[j] = tmp;
  return 1;     // Success!
} // strings_swap


// +--------------------+----------------------------------------------
// | Exported Functions |
// +--------------------+

int
strings_sort (int n, char *strings[], StringComparator compare)
{
  int i;
  for (i = n-1; i > 0; i--)
    {  
      strings_swap (i, strings, 
                    i, 
                    strings_index_of_largest (i+1, strings, compare));
    } // for i
  return 1;     // Success
} // strings_sort
