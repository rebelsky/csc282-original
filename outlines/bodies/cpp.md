A C Project "Ecosystem"
-----------------------

If we're going to talk about C, we should think about the structure
of a typical project.  What do we expect to have?  We'll look at Sam's
traditional model ofo the project

* External resources
    * Standard tools: GCC, Make, Lint, Valgrind, ...
    * Standard libraries.   (The ones included with every C program.)
    * Additional libraries.  (Optional; Either already on every system
      or installed.)
    * Information on those libraries.  (typically in `.h` files).
* Project-specific resources
    * A bunch of project-specific library code (typically in `.c` files).
    * Information on that library code (typically in `.h` files)
    * Tests of that library code (typically in `.c` files).
    * One or more applications that use the code.
    * Potentially custom tools to help with things.
* A Makefile that gives instructions for tying everything together.

Steps in Compilation
--------------------

* In 161, you learn to compile C code directly to executable code.
* However, there are multiple phases the C compiler goes through in
  that compilation.  These steps are particularly relevant when you
  are dealing with real ecosystems.
* First, the compiler runs the *C Preprocessor*.  The preprocessor
  deals with some simple textual substitution.
    * Replace `#include "*file*"` with the contents of *file* (relative path).
    * Replace `#include <*file*>`. with the contents of
      `*file*` (found in the include path - starts with 
      `/usr/include`, but also anything else that you specify
      with `-I*dir*` also some environment variable).
    * Replace defined constants with their values.
    * Replace macros with their bodies.
    * Process preprocessor conditionals
* Second, the compiler does the main work of translating to assembly code.
    * (Okay, in most cases, the compiler translates to an internal 
      type of assmebly and then has to spend a bit of extra work generating
      "real" assembly code.)
* Third, assemble the assembly into relocatable object code.
    * This assembly code allows the variables and procedures to be put at
      different locations in memory.  
    * That is, there are effectively "placeholders" for many things that
      still need to be filled in (where in static memory a global variable
      is, where in memory the start of a procedure is)
* Finally, linke the relocatable object code with appropriate libraries
  to build the executable.
    * For all but the basic libraries, you need to specify the library
      name with <code>-l*name*</code>.
    * You may also need to specify a path to the library.
* You can get the compiler to build any of these intermediate forms
  using flags
    * `-E` - just the preprocessor
    * `-S` - up through assembly
    * `-c` - up through relocatable object code

Including Files
---------------

* Useful for headers. (Why?)
* Can include regular code, too. (Why?)
    * E.g., an alternative to separate compilation.

Playing with Macros
-------------------

* Simplest: Constants.  Mostly useful for readability.
* Standard: Alternative to functions.
    * Usually more efficient than function calls.
* But still dangerous if used less carfully.

CPP Conditionals
----------------

* Typical use: Different code on different systems.
* Another typical use: Insert code for debugging by printing or whatever.
* Sam sometimes puts unit tests in that way.  Your main gets put
  in an ifdef section.

Detour: Standard Header File Format
-----------------------------------

* So, why do we write header files in the "standard" format?
* Consider two include files, zebra.h and stripes.h.  zebra.h includes
  stripes.h.  What happens?

The Preprocessor and the Command Line
-------------------------------------

* Can put -D*whatever*
    * Makes it easier to change how you compile your program on the fly.

Some Great Preprocessor Hacks
-----------------------------

* Include one file multiple times (with different definitions) to
  get simlar definitions.  (E.g., different kinds of lists.)
* Process the same list multiple times.

