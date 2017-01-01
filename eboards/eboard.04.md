CSC282 2015S, Class 04: Compilation, Macros, and the C Preprocessor
===================================================================

_Overview_

* Dealing with script files.
* A C program ecosystem.
* Steps in compilation.
* Including files.
* Detour: Why we have included files.
* Macros.
* CPP cnditionals.
* Detour: Standard header file format.
* Command-line flags.
* Hack: Generic data types.

Preliminaries
-------------

### Admin

* Sam gone next week.  Mr. Stone discusses cron and other exciting
  ways to make programs run unattended.
* HW forthcoming: Read about macros in C and find/develop an
  interesting example.  We'll talk about them in two weeks.

### Questions

Moving .jpg files
-----------------

Code by NK.

    #!/bin/sh
    # first argument is where from, second argument is where too.
    for file in $(find $1 | grep .jpg) ; do
      echo "copying $file to $2"
      cp $file $2
    done

Observation 1: $1 and $2 refer to command-line arguments.

Question: How do we figure out what `find $1 | grep .jpg` does?

* Google: Nope.  
* `man grep` - search for lines that match a pattern
* `man find` - when used as `find dir`, lists all the files in
  a directory.

Conclusion: The command `find $1 | grep .jpg` finds all the jpg
files within a directory.

Question: Might it find thigns other than jpg files.  We might
have a filename with .jpg in the middle.  (or just any character
and jpg).  use `\.jpg$`.

Other improvements: `find` can actually have some parameters that
specify what files to find.

    find . -name '*.jpg'

Note `time cmd` tells you how long a command takes

Detour: How do pipes work?

* Traditionally: We start both processes.  The client process
  runs until it requests input from the server.  Then the client
  blocks on the server.  The server runs until it generates a
  buffer full of output (or flushes the buffer).  At that point,
  it goes to sleep and the client is resumed.

A C program ecosystem
---------------------

On the design and implementation of larger programs written in C.

* Some motivation for this comes from the time period.
* Some comes from good program design.

Simple model of C programs: Put everything in one file.
(Alternate: Put things in separate files.)

* If we change one line in one function, we have to recompile
  everything.
    * Partially a time period issue.
    * Recompiling Gimp completely on a MathLAN workstation:
      about 30 minutes
* If we separate the large file into smaller files, we can resuse
  code.  (Libraries!)
* Easier for the programmer to read, as long as there's a good
  naming system, a table of contents, or grep.
* Provides more protection of your code in cases of accidental
  deletion.  (But you use a version control system ...)
* Easier for collaboration.

Traditionally, a C project includes

* The .c file for each part of the project.
* Unit tests for each part of the project (I wish).
* Question: I'm compiling partb.c which depends on parta.c.  How
  does the compiler know about the functions in parta?
    * We could recompile everything together!
    * We could `#include parta.c`, but that has the slow compilation
      issue.

Detour: Steps in compilation
----------------------------

The 161 model: .c -> executable

The actual steps:

* Preprocessor: Handles #include and #define and other directives
  (converts C code to C code).
* Translator: Converts C code to assembly code
* Assembler: Converts assembly code to relocatable object code
  (.o suffix)
* Linker: Joins togethers multiple object files into an executable

For our silly program

* parta.c -> parta.o
* partb.c -> partb.o
* parta.o + partb.o + stdio.la + ... -> prog

Back to the Question
--------------------

_When compiling partb, how does the compiler know about parta?_

> We've just seen that it doesn't have to.  Maybe it's smart.

_Why do we not get the warning that 'foo' is not declared?_

> The C compiler trusts the user.

_What should we do?_

> Quick hack:

        extern double foo(double);

> Normal strategy: For every .c file, you create a .h file that
  gives such declarations.

> Here's parta.h

        #ifndef __PARTA_H__
        #define __PARTA_H__

        /**
         * parta.h
         *   Amazing mathemtical utils by NK and cmapsdfay.
         *
         * Released under GPL 3.0.  You should have received a
         * license with this software.  If not, got to
         * Richard Stallman's abode and ask for a copy.
         */
        extern double foo(double);

        #endif __PARTA_H__
Including files
---------------

Detour: Why we have included files
----------------------------------

Macros
------

CPP cnditionals
---------------

Detour: Standard header file format
-----------------------------------

Command-line flags
------------------

Hack: Generic data types
------------------------

