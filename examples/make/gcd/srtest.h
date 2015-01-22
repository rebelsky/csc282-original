/**
 * srtest.h
 *   Header file for SamR's testing utilities.
 *
 *   Copyright (c) 2013-14 Samuel A. Rebelsky.  All rights reserved.
 *
 *   This file is part of SRTest, SamR's simple testing utilities.
 *
 *   SRTest is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   SRTest is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with SRTest.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __SRTEST_H__
#define __SRTEST_H__


// +-------+-----------------------------------------------------------
// | Usage |
// +-------+

/*

  sr_reset ();
  SR_CHECK_LONG (stderr, 5, 2+3);
  sr_report ();
  exit (sr_get_errors() != 0)

 */


// +-------+-----------------------------------------------------------
// | Notes |
// +-------+

/*

  The design team is currently debating whether or not to give clients
  direct access to the variables that count tests and errors.  The header
  currently includes not only functions to access the variables, but also
  extern variable declarations to access those variables.

 */


// +---------+---------------------------------------------------------
// | Headers |
// +---------+

#include <stdio.h>      // For fprintf, FILE, and such.


// +--------+----------------------------------------------------------
// | Macros |
// +--------+

/**
 * Check to see if an expression that returns a long has an expected value.  
 * Ideally, the expression and the value will be free from side effects.
 * If the values do not match and ERR is not null, prints an error message 
 * to ERR.
 */
#define SR_CHECK_LONG(ERR,EXP,VAL) sr_check_long (ERR, #EXP, EXP, VAL);


// +-----------+-------------------------------------------------------
// | Variables |
// +-----------+

/**
 * A count of the number of tests conducted.  Except in special circumstances,
 * you should only read this value and not change it.  Note that the
 * SR_CHECK_XXX functions update this value.
 */
extern int sr_tests;

/**
 * A count of the number of errors encountered.  Except in special 
 * circumstances, you should only read this value and not change it.
 */
extern int sr_errors;


// +-----------+-------------------------------------------------------
// | Functions |
// +-----------+

/**
 * Check to see if an expression that returns a long has an expected value.  
 * Ideally, the expression and the value will be free from side effects.
 * expstr is a string that represents the expression (so that we can print 
 * it out if necessary).
 *
 * If the expression does not match the value and ERR is not null, prints 
 * an error message to ERR.
 *
 * Note that it is usually better to use the CHECK_LONG macro, rather than
 * check_long, because the mcros ensures that the strings and values match.
 *
 * Returns true (1) upon success and false (0) upon failure.
 */
extern int sr_check_long (FILE *err, char *expstr, long exp, long val);

/**
 * Get the number of errors encountered.
 */
extern int sr_get_errors (void);

/**
 * Report on tests conducted
 */
extern void sr_report (FILE *err);

/**
 * Reset the testing framework.
 */
extern void sr_reset (void);

#endif // __SRTEST_H__
