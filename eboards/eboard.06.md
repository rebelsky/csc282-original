CSC295 2014S, Class 06: Using Macros for Logging
================================================

_Overview_

* Preliminaries.
    * Admin.
* Interesting macro examples.
* Requirements for a debugging/logging system.
* Implementation details.

Preliminaries
-------------

### Admin

* This week's assignment: Write a macro library for something interesting
* No class next week.  Use the time to teach yourself vi
    * Next week's assignment: 
        * Find four interesting vi settings, such as `sm`.
        * Make a list of four things you'd like to be able to do with vi.
* Cool CS activities:
    * Thursday extra: New curriculum

Interesting macro examples
--------------------------

* Small C functions that we think will be more efficient as macros 
  (no need to use the call/return; will inline suffice?)
* Lots of use of ?:
    * In Scheme if serves as both a statement and an expression
      (+ 1 (if (> x y) x y))
    * In C, `if` is a *statement*, so it can't be used as an expression
      1 + if (x > y) x; y;  ILLEGAL C
    * We need a conditional expression, as well as a conditional statement.
      (Let's make it confusing!)
      `test ? consequent : alternate`
    * Now I can write
      `z = 1 + (x > y) ? x : y;`
* A typical definition 
    #define MAX(a,b) (((a) > (b)) ? (a) : (b))
* What happens if we write
    int a = 2;
    int b = 3;
    int c = MAX(a++,b++);
    printf ("%d,%d,%d\n", a, b, c);
    // 3, 5, 4

Requirements for a debugging/logging system
-------------------------------------------

Print statements that are easy to enable/disable.

   #ifdef DEBUG
   #define MSG(str) fprintf (stderr, "  // %s\n", str)
   #else
   #define MSG(str)
   #endif

See the value of variables or expressions at various states in the program
I get it wrong when I type

   fprintf(stderr, "a = %d\n", a);

I want

   IVAR(x)

to print

   x = 4

Cool macro feature: #param gives the parameter as a string

    #ifdef DEBUG
    #define IVAR(exp) fprintf (stderr, " // %s = %d\n", #exp, exp)
    #else
    #define IVAR(exp)
    #endif

See the code as it executes

    #ifdef DEBUG
    #define DO(statement) do { fprintf(stderr, "%s;\n", #statement); statement;  } while (0)
    #else
    #define DO(statement) statement
    #fi

See the call structure

    START(FUNCTION_NAME)
    END(FUNCTION_NAME)

Generalized on/off printf

A natural extension of all of this: Unit testing

   CHECK_INT(expression, value)

* Evaluate expression
* Compare to value
* If the same, do nothing
* If different, print the expression, the value, and a message

Difficlty

   if (test)
     DO(x = x + 1);

Implementation details
----------------------

