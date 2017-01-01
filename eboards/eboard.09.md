CSC282 2015S, Class 09: Automating Work with Make
=================================================

_Overview_

* Preliminaries.
* Project ecosystems.
* An introduction to Make.
* Example: A standard C project.
* Good Make practice: Standard targets
* Example, continued: Adding more targets to our project.
* Using variables.
* Example, continued: Improving our Makefile with variables.

Preliminaries
-------------

### Admin

* Code for today is in [examples/make/gcd](../examples/make/gcd)
* Homework: Create a Makefile for some project you've built
  in the past.  Post the Makefile and an explanatory document to the repo.
* CS Table Friday is Therac 25!

Project ecosystems
------------------

Let's look at a comparatively simple (but common) C project.

* You build a library of math functions to use in your other programs.
    * sqrt
    * gcd
    * ...
* You want command-line version of many of these
* You want unit tests for all of these functions
* What files would you expect to see?
    * A dot see file for the library (or parts of the library)
      `mathlib.c`.
    * A header file for that library.  `mathlib.h`.
    * The gcd utility that calls the library.  `gcd.c`.
    * Compiled files (`mathlib.o` and `gcd.o`)
    * Executables (`gcd`)
    * Unit tests (`gcdtest.c`)
    * Makefile
    * Unit testing library or utilities
    * Header file for the unit testing utilities
* Building projects requires that we remember commands
    * "To build gcd, I need to build gcd.o and srmath.o and
      link them together.  The command for doing so is ..."
        * Minimal solution: Put the command in a file
        * Slightly less minimal solution: Make that file executable
        * Maybe we should have a common form for doing this
* When we change files, we need to rebuild
   * "When I change my library, I should rerun all of the unit tests
     and rebuild all of the command-line libraries"
* If compiling is expensive, I should only recompile what is
  necessary.
* Make was designed to handle these and related issues

Detours
-------

* Common problem: user types text, "312".  Program wants a number.
    * The text can come from the command line or in an interactive
      terminal program (or a field in a GUI program)
* Since it's a common problem, a common solution exists.  `atoi` and
  `atol` and ...

An introduction to Make
-----------------------

* A solution to the issues described above
* Target - The thing you want to build (e.g., `gcd`)
* Dependencies - The things you need in order to build it.
* Instructions - THe things you do to build it.
* We also have "virtual" targets - represent actions/activities,
  not files.
    * "I want all of the tests to succeed before I rebuild my
      command-line tools."
* In Make

        target: dependencies
                instruction1
                instruction2
                instruction3

* To use it: `make TARGET`
* Make is smart enough to build anything you depend upon
* Can you have more than one makefile per directory?
     * Naming conventions make that hard.  "Makefile" or "makefile"
     * Control with `make -f MAKEFILE TARGET`

Example: A standard C project
-----------------------------

* Example

        gcd: gcd.o srmath.o
                cc -o gcd gcd.o srmath.o
        gcd.o: gcd.c
                cc -c -o gcd.o gcd.c
        srmath.o: srmath.c
                cc -c -o srmath.o srmath.c
* Note: Make has default (smart) rules
* Note: Make has some variables you can set

Good Make practice: Standard targets
------------------------------------

* clean - remove cruft (.o files or equiv, executables)
* test - make sure that all of our tests run
* everything - build all of the stuff (not standard)
* default - what to build by default.  MUST BE FIRST TARGET.
* format - format your code (not standard)
Example, continued: Adding more targets to our project
------------------------------------------------------

Using variables
---------------

Example, continued: Improving our Makefile with variables
---------------------------------------------------------

