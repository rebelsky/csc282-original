CSC295 2014S, Class 08: Sam Rants about Editors
===============================================

_Overview_

* Preliminaries.
    * Admin.
    * Questions.

Preliminaries
-------------

### Admin

* This week's homework, part 1: Macros
* This week's homework, part 2: What else do you want to know about vi?
* Next week's homework: Create a Makefile for some project you've built
  in the past.  Post the Makefile and an explanatory document to the repo.

### Questions

Macros
------

* A macro that gets the size of an array

    #define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

    * Warning!  Will work only in rare situations.  Don't count on it.
* A macro that takes a string and calls a function
    * Sam does not believe this is possible in the abstract.

Questions about `vi`
--------------------

* Why should we learn it?
    * You should know at least one editor deeply.
    * To find the right tool for yourself, you should explore a variety
      of tools.
    * Sometimes all you have is a terminal.  vi runs in the terminal.
      (so does emacs)
    * vi is ubiquitous.  Almost every Unix installation has vi or vim or
      some other clone.  Every Unix installation has ex.
    * Most of what we learn is novice friendly.  Your editor need not be
      novice friendly.  It needs to be expert friendly.
* Why does Sam use vi?
    * Needed it when sysadmin
    * Likes ubiquity
    * Has used it for way too long
    * Luck of the draw
    * Fast.
    * Easy to use the shell - I can send
* Why use emacs?
    * Programmable!  (And infinitely customizable.)
    * In Lisp!
* Good editors allow you to 
    * do global search and replace using regular
      expressions.  (Emacs, vi, some others.)
    * shove text through another program for processing
* How did Sam make those quick updates to his code?

     fprintf ("a1 is %s\", a1);
     fprintf ("a2 is %s\", a2);
     fprintf ("a3 is %s\", a3);

    * Three tasks
        * copy the line twice (yy to copy, p paste, p paste)
        * replace 1 with 2, replace 1 with 3
            :s/1/2/g    - Just on this line
            :1,$s/1/2/g - On every line
            :.,.+5s/1/2/g - On this line and the next five lines
        * put stdin in all three
            :.,$s/(/(stdin/

* How does Sam deal with his bad formatting?

    a aid all come confused for good is Now of people the the time to
    to user vi


* Can you write your own commands?
    * Usually use shell commands, which you can write

* How does it deal with indentation?  Use indent!

   int
   main (int argc, char *argv[])
   {
     int i;
     return 0;
   }

* Can we autocolor text in vi?
    * Yes
* vi can also be set to automatically indent to the same as the previous
  line (:set ai; :set noai)

        hello goodbyegoodbyegoodbye zebra
* Using regular expressions
   \(PATTERN\) is a parenthesized pattern
   In the replacement, \1 is the first parenthesized pattern, \2 is the
   second parenthesized pattern, and so on and so forth

   "All words that start with g should be tripled"
   :s/\(g[a-z]*\)/\1\1\1/g

   good bye good day great morning
