#ifndef __LOG_H__
#define __LOG_H__

/**
 * log.h
 *   A variety of procedures that make it easier to log values.
 * 
 * Provides
 *   NOOP 
 *     Do nothing, but in such a way that we can safely put a
 *     semicolon after the operation.
 *   BLOCK(code)
 *     Build a simple block of code
 *   MSG(str)
 *     Print a "debugging" message using str.
 *   IVAR(exp)
 *     Print a "debugging" message giving an expression and its value.
 */

#include <stdio.h>

#define NOOP 

#define BLOCK(CODE) do { CODE } while (0)

#ifdef DEBUG
#define MSG(str) fprintf (stderr, "    // %s\n", str)
#define IVAR(exp) fprintf (stderr, "    //  %s = %d\n", #exp, exp);
#define DO(statement) BLOCK (fprintf (stderr, "%s;\n", #statement); statement;)

#else
#define MSG(str) NOOP
#define IVAR(exp) NOOP
#define DO(statement) statement
#endif

#endif // __LOG_H__
