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

