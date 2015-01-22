/**
 * arrays1.c
 *   A demonstration of why it can be hard to build arrays on the fly.
 *
 *   Copyright (c) 2013 Samuel A. Rebelsky.  All rights reserved.
 *
 *   This file is part of the Glimmer Guide to C (GGC).
 *
 *   GGC is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   GGC is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with GGC.  If not, see <http://www.gnu.org/licenses/>.
 */


// +---------+---------------------------------------------------------
// | Headers |
// +---------+

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>


// +---------+---------------------------------------------------------
// | Helpers |
// +---------+

/**
 * Print an array of integers.
 */
void
print_iarray (int size, int *arr)
{
  int i;
  printf ("{ ");
  for (i = 0; i < size-1; i++)
   printf ("%d, ", arr[i]);
  if (size > 0)
    printf ("%d ", arr[size-1]);
  printf ("}\n");
} // print_iarray

// +-------------+-----------------------------------------------------
// | Experiments |
// +-------------+

/**
 * An experiment in which I build an array whose content depends on a
 * function call.
 */
void
expt2 (int val)
{
  int vals2[] = { (int) random () * val };
  print_iarray (1, vals2);
}  // expt2


// +------+------------------------------------------------------------
// | Main |
// +------+

int
main (int argc, char *argv[])
{
  int vals0[] = { 1, 2, 3};
  int vals1[] = { 2, 3, 5, 7, 11, 13, 17, 19 };
  int vals2[] = { (int) random (), (int) random (), (int) random () };

  printf ("vals0: ");
  print_iarray (3, vals0);

  printf ("vals0[0..0]: ");
  print_iarray (1, vals0);

  printf ("vals0[0..-1]: ");
  print_iarray (0, vals0);

  printf ("vals1: ");
  print_iarray (8, vals1);

  printf ("vals2: ");
  print_iarray (2, vals2);

  return 0;
} // main

