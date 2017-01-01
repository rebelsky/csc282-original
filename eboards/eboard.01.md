CSC282 2015S, Class 01: Introduction
====================================

_Overview_

* Preliminaries.
    * Admin.
    * Upcoming Work.
    * Questions.
* The origins of the course.
* Some principles and practices.
* Example: C from K and R.
* Detour: A C memory problem.
* Exercises: Some simple tasks.
* Looking ahead.

Preliminaries
-------------

### Admin

* Welcome to "Thinking in C and *nix" (or whatever the course is called
  in the catalog).
* We are hiring this semester, so my brain may sometimes be elsewhere, and
  I will be even less organized than normal (hard as that is to imagine). 
  I apologize.

### Attendance

* I'll take attendance, mostly to help me make sure that I know everyone's
  name.  (I have about 90 students this semester, so knowing everyone is hard.)

### Questions

The origins of the course
-------------------------

* History: Compilers students said "Sam, you should have a course in all of
  these things about C and *nix that you know, and expect us to know, and
  are cool, but we don't know."  Now regularized.
* Sam's other perspective.  You are not yet competent C programmers; there
  are a host of things you need to know.

Policies and Procedures
-----------------------

* S/D/F. - Fairly straightforward grading.
* 1 credit: Reasonable workload.
* Expectations: 
    * Show up! (Miss no more than two classes.)
    * Try! (At least an hour per week.)a
    * Participate!
* Stuff is on the web, focus on outlines and eboards.
* Homework through Github.

Some principles and practices
-----------------------------

Sam expects coders to

* Document.  Both procedures (prmiarily purpose) and strange code.
        // Multiply a by 4, assuming ...
        a = a << 2;
* Test.  Autotmatic tests are better.
* Refactor.  If you write similar code more than once, write a separate
  procedure (...) that encapsulates the similarities.  If you are programming
  by copy-paste-change, it's probably time to refactor.
    * Copy-paste-change is inelegant.  And causes huge code growth.
      (Good if you are being paid per line.)
    * Updates are really hard unless you refactor.
* Encapsulate: Group things together into objects/libraries.  Find a simple 
  interface for your libraries.  Your client cares about what you achieve
  not how you achieve it.
* Format according to standards.  GNU C.

Thinking in C

Good C programmers ...

* Pay attention to the underlying representation
* Take advantage of the C preprocessor - #include and macros
    * We'll learn both simple and complex macros
    * Macros are effectively functions that act on program source code
* Know how to use tools for analyzing code
    * Debuggers - gdb
    * Memory analyzers - valgrind
    * Things that show you what code is being used the most
* Use libraries

Thinking *nix

* Small programs, working together
* Programs take text files as input and produce text files as output
* Don't do things by hand when you can do them by code
    * Scripting languages - Perl, Python, Ruby, PHP, Bash, ...
    * C
    * Makefiles
* Know enough bash (or tcsh or ...) to tie things together.

Example: C from K and R
-----------------------

    char *
    fun (char *t, char *s)
    {
      while (*t++ = *s++);
      return t;
    } // fun

Hypotheses

* Checks how many characters are equal and returns the part of t where
  differences begin.  (Never mind, = does not check for equality.  (And
  your code breaks when you think it does.))
* Puzzling when the increment
* Analysis
    * Goes through, assigns *s to *t
    * Returns what t now points to.
    * Increments as you go along.
    * Stops when you hit an ending character.
* Things this assumes you know
    * Assignment returns the value assigned.
    * Strings end with 0.
    * 0 also represents false.
    * ++ on pointers advances to the next memory location.
* strcpy, returning the memory address at the end of the string.
* Further issue: It's usefl to return the memory address at the 
  end of the string.

Detour: A C memory problem
--------------------------

How would you diagnose the following program that crashes?

    x = malloc (...);
    phase1 ();
    phase2 ();
    free (x);

Observations:

* If you remove the call to `free`, the program will run to completion.  
* If you move the call to `free` before the call to `phase2`, the program 
  will run to completion.
* There are no calls to `free` in `phase2`.  

Hypotheses

* There's memory allocated in phase2, and we run out of memory, so
  something goes wrong.  Possible, but not what was wrong.
* Could it be that they didn't malloc enough space?  Unlikely.
* The problem did not have to do with calls to malloc in phase2.
* Potentially, someone could overwrite x.
* It was an array-out-of-bounds problem, writing over malloc's variables.

Exercises: Some simple tasks
----------------------------

* Given a DOS-formatted text file (lines end with \r\n rather than just
  \n), convert it to a standard text file.
* Given a standard text file, convert all uppercase letters to lowercase.
* Given a standard text file, remove all blank spaces at the end of lines.  
* Make a list of all misspelled words in a text file.
* Given a CSV file in which each line has the form<br>
  `LastName,FirstName,Assignment,NumericGrade` <br>
  find the the five highest grades on homework 2.
* Given an HTML file, find the URLs of all images.  In case you don't
  know HTML, those will typically look like <br>
  `<img ... src="*URL*" ...>`
  + The `img` can have any capitalization (`img`,
    `IMG`, `Img`,  `iMg`, etc.)
  + There can be other text between the `img` and the
    `src`.  (That text cannot include a greater than sign.)
  + You may find it easier to start this problem by assuming that there's only one image tag on a line.

Homework
--------

This will appear online some time in the near future (probably over the
weekend).

Repository: `https://github.com/Grinnell-CSC282/hw1-2015S`

1. Read chapter 1 of Raymond to get a deeper understanding of the *nix
Philosophy.

2. Find good solutions to all of the tasks above.  (That
is, write a program or command to solve the task.)  Put them in a folder
with your name in the GitHub repository.

3. Make a list of *nix tools and utilities that you've found useful
(or even that you've just heard of).  Try to categorize and add a
short description.  Add the tools you've discovered to the `tools.md`
file in the repository.

