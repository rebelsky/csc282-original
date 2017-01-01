CSC282 2015S, Class 10: Improved Make
=====================================

_Overview_

* Preliminaries.
* A quick review of Make.
* Variables in Make.
* Some standard variables for C programs.
* Another example: Document development.
* Automatic variables.
* Generic rules.
* Standard make rules.
* Other useful techniques.
* Miscellaneous tools and techniques.

Preliminaries
-------------

### Admin

* Remember that there's an excellent free book on Make (listed in
  the course front door).  You learn make, like most tools, by
  using it in your own work.
* Homework one of two:
    * Version a: Create a full make suite for some useful C project, 
      including options for cleaning, packaging, and more.  (This
      version assumes that you look up the standard targets.)
    * Version b: Find a particularly creative makefile and explain
      some interesting parts.

### Questions

A quick review of Make
----------------------

Goals

* Make it easier to compile and update projects.
    * When you update something like a header file, it knows that
      it has to recompile, and recompiles only what is necessary.
* Document the steps needed for compilinga
    * We've documented in a computer-usable format
    * A human who knows the syntax could also follow them

Format

* Create a file called `Makefile`
* Need to specify target, action, dependencies

        target: dependencies
        \t      action1
        \t      action2
        ...

* We can include variables in our makefile (see next section)
* Targets can either be particular files or virtual targets

Learned from writing your own

* Broader issue: How to deal with a project that has a lot of .c and
  .h files.
* It makes you more efficient.
* It's relatively easy to do.
* If you have just one target, you can just type `make`.  If you 
  have multiple targets, typing `make` only makes the first one.
    * Standard practice: First target is called `default` and lists
      all the things you really want to make.

Variables in Make
-----------------

* Variables are a powerful tool.
    * A variable is a name for one or more things, which may be
      computed.
    * Use `pi` rather than `3.141592653589...` (mnemonic rather 
      than a value)
    * Saves repeated calculations: Use 'x' rather than ten lines
      of code that we use multiple times.
    * Allows you to make global changes.  E.g., if we write code that
      has to run in Indiana, we can redefine pi to 3.
    * Sometimes the same value has multiple meanings, and variables
      clarify the meaning.
* Certain variables in make make your code more obscure but easier
  to write.
* In make, initialize with

        VARIABLE = values or computations

* Custom is that variables are all caps
* In make, we generally use variables with `$(VARIABLE)`

Some standard variables for C programs
--------------------------------------

Make has a lot of standard rules (e.g., for building .o files from
.c files).  We can customize using variables.

* `CC`

Another example: Document development
-------------------------------------

Sam's web sites

* Simple things: Don't write in HTML
    * Write in Markdown (.md)
    * Write in Docbook/SGML - HTML + variables!
* Rules for converting
    * SGML/Docbook -> html
    * md -> html
        Multiple steps
          md -> htm
          add additional HTML in the header and footer
    * html -> postscript
    * postscript -> pdf

Automatic variables
-------------------

Rules are often almost identical.  So we want patterns that will
work with anything that follows some standard naming conventions.

* Converting .c to .o
* Converting .o to executable
* Converting .md to .htm
* Converting .htm to .html
* Converting .html to .ps
* Converting .ps to .pdf

Two mechansisms for doing this: Original Make and GNU Make.

Two stages: Automatic variables

* Refer to the target in the action `$@`
* Refer to the prerequisites: `$^`

        file.htm: file.md
                Markdown.pl < $^ > $@

Generic rules
-------------

* Use patterns for the target and dependecies (% means "anything")

        %.htm: %.md
                Markdown.pl < $^ > $@
        
Standard make rules
-------------------

        make -p

Other useful techniques
-----------------------

        VAR = $(shell COMMAND)

Miscellaneous tools and techniques
----------------------------------

