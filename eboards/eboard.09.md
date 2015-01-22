CSC295 2014S, Class 09: Automating Work with Make
=================================================

_Overview_

* Preliminaries.
    * Admin.
    * Questions.
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

* Homework: Create a Makefile for some project you've built
  in the past.  Post the Makefile and an explanatory document to the repo.
    * If you already did the homework, no need to repeat

Project ecosystems
------------------

* Someone has built utility code (in C) for doing mathematical computations.
* What are the likely files that they'll have?
    * Source code
        * library.c - Source code
        * library.h - header for code
        * External libraries? (Maybe)
            * utest.c - Unit testing
            * utest.h - Unit testing
        * footest.c - Test for function foo.
        * Simple applications that build upon the library
            * gcd.c - Compute the gcd of numbers specified on the command line
    * Intermediate/generated files
        * library.o, utest.o, gcd.o
    * Executables
        * footest, gcd
    * Real libraries
        * library.a
        * library.so
    * Packaged versions of the code
        * library.tar.gz
        * library.deb
    * Makefile (what we're learning about)
    * Information
        * README - Information for lots of people
        * MANIFEST - List of the files
        * DEVELOPER - Information for developers
        * LICENSE - GPLV3
* What will they want to do with the files?  What are the tasks?
    * Build the applications
    * Build the library
    * Build the tarball
    * Build and run tests
    * Get rid of cruft
* Somewhere, there are instructions for doing all of these tasks
    * To make gcd, you need to ...

An introduction to Make
-----------------------

* A tool to help manage all of the above.
* First basic idea of make: Once you've written down an instruction, there
  should be no need to type that instruction again; the computer should
  be able to figoure it out.
* Second basic idea of make: There are often dependencies in your steps.
  (E.g., whenever you change foo.h, you should recompile anything taht
  includes foo.h).
    * You should document them
    * The computer should be able to figure out dependencies
* Third basic idea of make: Many tasks are nearly identical.  We can
  have some generic rules.
* Fourth idea: Configurable!

The world of make

* targets - Things that we want do do or build
    * file targets - files
    * phony targets - tasks
* dependences: notes as to the relationship of files
    * "if this changes, you need to rebuild this"
* rules: instructions for building something or doing a task

Normal pattern

    target: prerequisites
            instructions

Example: A standard C project
-----------------------------

* gcd.c - UI for the gcd function in srmath.c
* gcdtest.c - A test of the gcd function in srmath.c
* Makefile - Puts it all together
* srmath.c - My handy-dandy math library
* srmath.h - header file for above
* srtest.c - My handy-dandy testing library
* srtest.h - header file for above
* testdemo.c - A demo for the testing library

Let's start writing the makefile

        gcd: gcd.o srmath.o
                gcc -o gcd gcd.o srmath.o

        gcd.o: srmath.h
        gcd.o: gcd.c 
                gcc -c -o gcd.o gcc.c

Narrative

* Let's make gcd
* Note: Make has a default rule for changing .c file to a .o
        $(CC) $(CFLAGS) -c -o FILE.o FILE.c
* .o files should depend on .h files that the .c file includes
    * Suppose we have 'int foo()'
    * bar.c calls foo, finds out about it from the .h file.  
      The code generated assumes the return value is an int.
    * We decide to change foo, so that it's 'double foo()'
    * Right now, the generated object code still assumes it's an int
    * We need to recompile for safety
* Side note: The first rule in the file is the one that gets executed
  if you don't say what to make

You can use any command in the insructions

Good Make practice: Standard targets
------------------------------------

First rule should be default.

    default: THINGS YOU REALLY WANT TO BUILD

You should be able to clean up cruft

    clean: # Remove .o and similar files
    distclean: # Remove .o and ANYTHING WE'VE BUILT

It's difficult to remember the testing commands, so have a test target

    test: test-executable another-test
             ./test-executable
             ./another-test

Build the tarball

    package:
          tar cvf package.tar.gz file1.c file2.c ...

Install the code where it belongs

    install:

Standard sequence when you build from scratch: make, make test, /usr/bin/sudo make install

Example, continued: Adding more targets to our project
------------------------------------------------------

Using variables
---------------

There's a lot of repetition in make files

        gcd: gcd.o srmath.o
                gcc -o gcd gcd.o srmath.o

        GCD_REQUIRES = gcd.o srmath.o
        gcd: $(GCD_REQUIRES)
                gcc -o gcd $(GCD_REQUIRES)

There are even built-in variables for "the thing on the left hand side $@ of the dependency and the thing on the right hand side $^."

        gcd: gcd.o srmath.o
                gcc -o $@ $^

There are ways to write generic rules!

Example, continued: Improving our Makefile with variables
---------------------------------------------------------

