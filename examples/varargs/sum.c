/**
 * sum.c
 *   A simple experiment to explore summing floating point values using
 *   varargs.
 *
 *   Copyright (c) 2013-14 Samuel A. Rebelsky.  All rights reserved.
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


// +--------+----------------------------------------------------------
// | Macros |
// +--------+

/**
 * Print a float.
 */
#define FPRINT(VAL) printf ("%s = %f\n", #VAL, VAL);


// +---------+---------------------------------------------------------
// | Helpers |
// +---------+

/**
 * Sum n values.
 */
float
sum (int n, ...)
{
  float sum = 0;
  int i;
  va_list floats;
  va_start (floats, n);
  for (i = 0; i < n; i++)
    {
      sum += (float) va_arg (floats, double);
    }
  va_end (floats);
  return sum;
} // sum


// +------+------------------------------------------------------------
// | Main |
// +------+

int
main (int argc, char *argv[])
{
  // +---------------+-----------------------------------------------------
  // | Sensible Sums |
  // +---------------+

  // Sum the empty collection of values
  FPRINT (sum (0));
  // Sum a single value
  FPRINT (sum (1, 3.14));
  // Sum two values
  FPRINT (sum (2, 3.14, 34.2));
  // Sum five of five values
  FPRINT (sum (5, 1.1, 2.1, 3.1, 4.1, 5.1));
  // Sum eight of eight values
  FPRINT (sum (8, 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1));
  // Sum three of three values, both positive and negative
  FPRINT (sum (3, 3.4, -3.0, -0.4));

  // +-----------------------------+---------------------------------------
  // | Somewhat Less Sensible Sums |
  // +-----------------------------+

  // Sum zero of two values
  FPRINT (sum (0, 3.14, 34.2));
  // Sum three of five values
  FPRINT (sum (3, 1.1, 2.1, 3.1, 4.1, 5.1));

  // +--------------------------+------------------------------------------
  // | Somewhat Suspicious Sums |
  // +--------------------------+

  // Sum eight of five values
  FPRINT (sum (8, 2.0, 2.0, 2.0, 2.0, 2.0));
  // Sum three of three values, all integers
  FPRINT (sum (3, 1, 2, 3));

  // And we're done.
  return 0;
} // main

