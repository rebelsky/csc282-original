/**
 * writer1.c
 *   A printf-like mechanism for writing different kinds of values.
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


// +---------+---------------------------------------------------------
// | Helpers |
// +---------+

/**
 * Write the sequence of values specified by format.
 *   i - integer
 *   c - character
 *   s - string
 *   f - float
 *   d - double
 */
void
write (char *format, ...)
{
  // Prepare to use varargs.
  va_list params;
  va_start (params, format);

  int i;        // Counter variable for loops

  int n;        // Holds an integer parameter
  char c;       // Holds a character parameter
  char *s;      // Holds a string parameter
  float f;      // Holds a float parameter
  double d;     // Holds a double parameter

  // For each parameter
  for (i = 0; format[i] != '\0'; i++)
    {
      printf ("%02d: ", i);
      switch (format[i])
        {
          case 'i':
            n = va_arg (params, int);
            printf ("%d\n", n);
            break;
          case 'c':
            c = (char) va_arg (params, int);
            printf ("'%c'\n", c);
            break;
          case 'f':
            f = (float) va_arg (params, double);
            printf ("%f\n", f);
            break;
          case 's':
            s = va_arg (params, char *);
            printf ("\"%s\"\n",s);
            break;
          case 'd':
            d = va_arg (params, double);
            printf ("%lf\n", d);
            break;
          default:
            printf ("???\n");
            goto escape;
        } // switch
    } // while
escape:

  va_end (params);
} // write


// +------+------------------------------------------------------------
// | Main |
// +------+

int
main (int argc, char *argv[])
{
  write ("ssiifc", "Hello", "Goodbye", -3, 42, 3.14, 'x');
  return 0;
} // main

