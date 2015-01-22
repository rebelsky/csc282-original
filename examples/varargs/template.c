/**
 * stack.c
 *   A simple experiment to explore where parameters and local variables
 *   go on the stack.
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

