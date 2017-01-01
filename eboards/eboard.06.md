CSC282 2015S, Class 06: Compilation, Macros, and the C Preprocessor
===================================================================

_Overview_

* Preliminaries.
    * Admin.
    * Upcoming Work.
    * Extra Credit.
    * Questions.
* Quick Review
* Including files.
* Macros.
* CPP conditionals.
* Detour: Standard header file format.
* Command-line flags.
* Hack: Generic data types. (Probably a future class.)

Preliminaries
-------------

### Admin

* This week's assignment: Forthcoming.
* Class next week may be on `gdb` if I can get Stone to teach it.
* Don't forget this week's CS Table!  It should be really interesting.

### Questions

Review: The C Program Ecosystem
-------------------------------

* The steps of compilation.
    * Start with source code: .c file
    * Preprocess to handle the lines that begin # and some
      related stuff (#include, #define, #ifdef, ...).  Output
      is still source code.
    * Translate the source code to assembly.  Convention that
      assembly files have a suffix of .s.
    * Assemble the assembly into relocatable object code, suffix
      of .o.  These are almost the final stage, so we keep them
      around for efficiency.
    * Executable: Linked .o files and libraries and everything else.
* The typical files in a "real" C program.
    * .c files that contain your code (mostly hand-written)
       * It's fun to write programs that generate C programs.
         "metaprogramming"
    * .h files - headers, get included in other files, provide
      information about other parts of the program (mostly hand
      written)
    * .o files will litter our directory during development.
      (Generated files)
        * utils.c contains a function called `do_work.
        * main.c calls `do_work`
        * utils.h contains the signature of `do_work` 
        * main.c include utils.h.
        * We have utils.h and do the include so that the compiler
          knows the types of parameters and the return type
    * Libraries!  (Various suffixes; .la or .a or .so)
    * Makefiles to provide instructions for doing the compilation
      and dependencies.
    * Executable(s)
    * Test(s)
    * Documentation!
    * ...
* What's the relationship between the .h file and the library?
    * The .h contains primarily the signatures of functions (and a bit more).
    * The library contains the information on how the funtions are
      implemented.  `stdlib.h` tells you what's in the standard library,
      but doesn't contain the code for that library.
    * At the point you're compiling, you don't need to know how things
      are implemented, you just need to know how to call them.
    * At the point you're linking, you just need to know what to link
      to.  Most C compilers automatically link stdlib and stdio.
    * This is an example of the general principal to *Separate 
      interface and implementation!*
        * If the client programmer doesn't know about the implementation
          he can't screw things up by relying on a particular
          implementation.
        * Easy to swap in different implementations.

Fun with Linking
----------------

* `sample.c` uses `fprintf`, `stdout`, and `sin`.
* With no #include, won't compile because `stdout` is undefined.
* With `#include <stdio.h>`, compiled with warnings.
        $ make sample.o
        cc    -c -o sample.o sample.c
        sample.c: In function ‘main’:
        sample.c:21:49: warning: incompatible implicit declaration of built-in function ‘sin’ [enabled by default]
        $ ls
        sample.c  sample.o
* However, we can't link
        $ make sample
        cc   sample.o   -o sample
        sample.o: In function `main':
        sample.c:(.text+0x28): undefined reference to `sin'
        collect2: error: ld returned 1 exit status
        make: *** [sample] Error 1
* If we `#include <math.h>`, we can compile without errors.
* But it still won't link.
* So we have to write
        $ cc sample.o -lm -o sample
* Or update the Makefile.
* What if we drop the `#include <math.h>`.  Can we still compile
  and link?   Probably, but with a warning.
    * Amazingly, even though we didn't give the signature, sin is
      standard enough that the compiler got it right.
* Observation: #include is different than linking.  We got information
  that sin is a function with the #include, but we only got the code for
  sin when we included -lm in our link stage.

Including files
---------------

* Since #include doesn't seem to include executable stuff.  What
  does it really do?
* We use angle brackets for standard include files (installed in
  system directories; come with the C compiler)
    * There is a variable, `LD_LIBRARY_PATH` tells the compiler
      where to look for those.
* We use quotation marks for the ones in the local directory
  (or whose full path we know).
* What does the include really do?

Macros
------

CPP conditionals
----------------

Detour: Standard header file format
-----------------------------------

Command-line flags
------------------

Hack: Generic data types
------------------------

