/**
 * boom.c
 *   A very simple program that crashes.
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
#include <stdlib.h>


// +---------+---------------------------------------------------------
// | Globals |
// +---------+

static int *ip;


// +-----------------+-------------------------------------------------
// | Predeclarations |
// +-----------------+

void qux (int i);
void baz (int i);


// +---------+---------------------------------------------------------
// | Helpers |
// +---------+

void
qux (int i)
{
  if ((i <= 1) || ((i % 2) == 1))
    baz (i - 1);
  else
    qux (i / 2);
} // qux

void
baz (int i)
{
  if ((i % 5) == 0)
    *ip = i;
  else
    qux (i);
} // baz


// +------+------------------------------------------------------------
// | Main |
// +------+

int
main (int argc, char *argv[])
{
  ip = malloc(sizeof(int));
  baz (67);
  printf ("Result is %d\n", *ip);
  return 0;
} // main
