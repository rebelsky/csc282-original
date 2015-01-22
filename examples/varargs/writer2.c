/**
 * writer2.c
 *   A mechanism for writing different kinds of values that uses a 
 *   different strategy than printf.
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


// +-------+-----------------------------------------------------------
// | Types |
// +-------+

/**
 * Valid parameter types.
 */
enum ptype
  {
    P_INT, P_FLOAT, P_DOUBLE, P_STRING, P_CHAR, P_END
  };


// +---------+---------------------------------------------------------
// | Helpers |
// +---------+

/**
 * Write a sequence of values, each of which is prefixed by a ptype.
 * End with P_END.
 */
void
write (enum ptype type0, ...)
{
  va_list params;
  va_start (params, type0);
  enum ptype type = type0;

  int i = 0;

  int n;
  char c;
  char *s;
  float f;
  double d;

  while (type != P_END)
    {
      printf ("%02d: ", i++);
      switch (type)
        {
          case P_INT:
            n = va_arg (params, int);
            printf ("%d\n", n);
            break;
          case P_CHAR:
            c = (char) va_arg (params, int);
            printf ("'%c'\n", c);
            break;
          case P_FLOAT:
            f = (float) va_arg (params, double);
            printf ("%f\n", f);
            break;
          case P_STRING:
            s = va_arg (params, char *);
            printf ("\"%s\"\n",s);
            break;
          case P_DOUBLE:
            d = va_arg (params, double);
            printf ("%lf\n", d);
            break;
          default:
            printf ("???\n");
            goto escape;
        } // switch
      type = (enum ptype) va_arg (params, int);
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
  write (P_STRING, "Hello",
         P_STRING, "Goodbye",
         P_INT, -3,
         P_DOUBLE, 42,
         P_FLOAT, 3.14,
         P_DOUBLE, 3.14,
         P_CHAR, 'a',
         P_END);
  return 0;
} // main

