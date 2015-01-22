/**
 * simonsays.c
 *   A simple illustration of variable-parameter procedures.
 *
 *   Copyright (c) 2013-2014 Samuel A. Rebelsky.  All rights reserved.
 *
 *   This file is part of The Glimmer Guide to C (GGC).
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


// +---------+---------------------------------------------------------
// | Helpers |
// +---------+

void
someone_says (char *who, ...)
{
  char *statement;
  va_list rest;

  va_start (rest, who);

  while ((statement = va_arg (rest, char *)) != NULL)
    {
      printf ("%s says \"%s\"\n", who, statement);
    } // while

  va_end (rest);
} // someone_says


// +------+------------------------------------------------------------
// | Main |
// +------+

int
main (int argc, char *argv[])
{
  someone_says ("Sam", "I love C.", "Don't you?", NULL);
  someone_says ("Student", 
                "I don't love C's all that much.",
                "I like B's.",
                "I love A's.",
                "I don't know what's higher than an A.",
                NULL);
  someone_says ("Simon",
                "Touch your toes.",
                "Touch your nose.",
                "Touch your toes again.",
                "Stop touching your nose.",
                "Gotcha!",
                NULL);
  someone_says ("HB");
  return 0;
} // main

