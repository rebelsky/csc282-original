CSC295 2014S, Class 11: Debugging with GDB
==========================================

_Overview_

* Preliminaries.
    * Admin.
    * Questions.
* Debuggers.
* gdb, the GNU Debugger.
* Tracing crashes.
* Some other operations.
* Another example.

Preliminaries
-------------

### Admin

* We won't spend much time looking at your work; just consider questions.
* CS Pub Night tonight!
* Pioneer Weekend this weekend!
    * Get together, share an idea, build a prototype, eat some food,
      meet some new people, hack some code, get mentored, get reviewed, 
      maybe make some money.  Free T.
* Homework: Find a gdb feature we did not discuss and write a quick 
  guide to the feature.  Examples:
    * Debugging a running process
    * Tracking variables.
* Tomorrow's CS table is on data privacy.
* Cool CS talk today at 4:30 p.m.

### Questions

* Why can't I get install to work?

Debuggers
---------

* Sometimes code is incorrect.
* How do you tell?
    * Really good unit tests.
* How do you find where the issue is?
    * Unit tests tell us the functional unit where things seem to go
      wrong.
* How do you explore the issue in more detail?
    * Read the code, work an example by hand.
    * Once you know what you expect, you can put in assert statements.
       * These can live forever as documentation.
    * Put in printf statements.
       * Something we have to remove later.
    * Use debuggers to identify problems.

gdb, the GNU Debugger
---------------------

* Command-line: Fast to start up and use; not so intuitive
* Also GUIs on top of gdb.
* Really powerful: Can attach to running processes.
   * Reason 1: It's still running, and there may be a cost to "getting here"
   * Reason 2: Convenience
   * Reason 3: Lets you escape when something is unexected
   * Reason 4: Things like servers don't like to be stopped
   * Reason 5: Plugins
* Really big; I don't know all of it, you can learn more than me pretty
  quickly.

Tracing crashes
---------------

        $ gdb program

Starts gdb

        gdb> run

Runs the program.  If it crashes, tells you where

        gdb> bt

Prints the call stack.

        gdb> p var

Prints a variable

        gdb> l fun

List a function

        gdb> l line

List a line

        gdb> set var VAR = EXP

Guess.

Another example
---------------

