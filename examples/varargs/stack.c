/**
 * stack.c
 *   A simple experiment to explore where parameters and local variables
 *   go on the stack.
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


// +--------+----------------------------------------------------------
// | Macros |
// +--------+

/**
 * Print the address of a variable.
 */
#define APRINT(X) printf ("&%s is %p (%lu)\n", #X, &X, (long) &X);


// +---------+---------------------------------------------------------
// | Helpers |
// +---------+

/**
 * Print the addresses of some variables and recurse, counting down
 * until the first parameter is 0.
 */
void
fun (int p0, int p1, int p2)
{
  int v0;
  int v1;
  int v2;

  printf ("------------------------------------------------------------\n");
  APRINT (p0);
  APRINT (p1);
  APRINT (p2);

  APRINT (v0);
  APRINT (v1);
  APRINT (v2);
  printf ("------------------------------------------------------------\n\n");

  if (p0 > 0)
    fun (p0 - 1, p1, p2);
} // fun


// +------+------------------------------------------------------------
// | Main |
// +------+

int
main (int argc, char *argv[])
{
  fun (3, 2, 1);
  return 0;
} // main
