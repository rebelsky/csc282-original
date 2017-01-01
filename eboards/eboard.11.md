CSC282 2015S, Class 11: Miscellaneous C Programming Issues
==========================================================

_Overview_

* Preliminaries.
    * Admin.
    * Upcoming Work.
    * Extra Credit.
    * Questions.
* Sorting, revisited.
    * Function pointers.
* Testing C programs.
    * Testing with macros.
    * Testing through the command line.
    * Testing with `assert`.
* Memory issues in C programs.
    * Checking memory problems with valgrind.

Preliminaries
-------------

### Admin

* Homework: Find or write a program with interesting memory errors 
  and show how valgrind helps you identify them.
* Cool CS talk today at 4:30 p.m.
* Alumni talk tonight about social media.

### Questions

Sorting, revisited
------------------

In Scheme

        ;;; Procedure:
        ;;;   sort
        ;;; Parameters:
        ;;;   lst, a list (or perhaps vec, a vector)
        ;;;   order, a two-parameter predicate that represents
        ;;;     a total order.  ("Does a come before b?")

In Java, we also think about providing a Comparator (or using 
Comparables)

What about C?  What's your signature for a procedure that sorts
an array of strings?

* Question: Do we sort "in place" or do we return a sorted array?

        /**
         * Sort strings.  Return 1 upon success and 0 upon failure.
         */
        int
        sort (char *strings[], int len)
        {
        } // sort

Function pointers
-----------------

* Can we make this take a comparator?

        /**
         * Sort strings.  Return 1 upon success and 0 upon failure.
         */
        int
        sort (char *strings[], int len, int (*compare)(char *x, char *y))
        {
        } // sort

* This says "compare is a function that takes two strings as input
  and returns an integer."
* The parentheses are important!
* Many novice C programmers find this hard to read.  Sometimes
  typedefs are useful.

        /**
         * Functions that return negative if x comes before y, 0 if
         * x "equals" y, and pos if x is greater than y.
         */
        typedef int (*Comparator)(char *x, char *y);

        int
        sort (char *strings[], int len, Comparator compare)
        {
        } // sort

* How do we call sort?

        int 
        compare_by_length (char *x, char *y)
        {
          return strlen (x) - strlen (y);
        } // compare_by_length

        sort (strings, adfas, compare_by_length);

Memory issues in C programs
---------------------------

* Everyone gets segfaults.
* How do you find/fix them?
    * Run gdb, look at a stack trace
    * Unfortunately, not all memory errors happen where the program
      crashes.
         * Free earlier and use later.  (The error may be in the free.)
         * Using freed memory, and only sometimes that fails.

Checking memory problems with valgrind
--------------------------------------

* Approximate demos.

Testing C programs
------------------

Testing with macros
-------------------

Testing through the command line
--------------------------------

Testing with `assert`
---------------------

