/**
 * square.c
 *   A simple program that looks at a simple form of something like map
 *   in C.
 *
 *   Copyright (c) 2013 Samuel A. Rebelsky.  All rights reserved.
 *
 *   This file is part of the Glimmer Guide to GDB (G^3).
 *
 *   G^3 is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   G^3 is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with G^3.  If not, see <http://www.gnu.org/licenses/>.
 */


// +---------+---------------------------------------------------------
// | Headers |
// +---------+

#include <stdio.h>


// +-----------+-------------------------------------------------------
// | Constants |
// +-----------+

/**
 * The number of items in our array.
 */
#define N 4


// +---------+---------------------------------------------------------
// | Helpers |
// +---------+

/**
 * Some functions.
 */
static int 
fun (int i)
{
  return i*i;
} // fun



// +------+------------------------------------------------------------
// | Main |
// +------+

int
main (int argc, char *argv[])
{
  int size = N;
  int values[N];
  int i;

  // Do the mapping
  for (i = 0; i < size; i++)
    {
      values[i] = fun (i);
    } // for

  // Sum the results
  int sum = 0;
  for (i = 0; i < size; i++)
    sum += values[i];

  // Print the results
  printf ("The sum of the first %d squares is %d.\n", N, sum);

  // And we're done
  return 0;
} // main
