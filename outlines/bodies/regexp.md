Going Over Homework
===================

Cleaning Up After Script
------------------------

* What solution did you come up with for cleaning up after script?

Environment Variables
---------------------

* What did you learn about environment variables?
* In general?
* For C?

A Bit About Basic Tools
=======================

* As you may remember from the first day of class, I noted that to be
  successful in using *nix, you need to know a variety of tools (and know
  *of* a wider variety).
* There's no way we can do a full in-depth exploration of each important
  *nix tools.  So we'll look at common uses of a few important tools.
* My goal is to do two or three today and to deal with others as they
  come up.

Grep
====

* Grep is a general-purpose search tool.
  + Searching in files for particular lines
  + Extract parts of streams
  + Searching large collections of files for those that contain particular
    lines.
  + ...
* Some files to play with
  + A collection of English words: `/usr/share/dict/american-english`
  + Web logs: `/var/log/apache2` on `www.cs.grinnell.edu`
  + Modified GIMP src: `/glimmer/src/sdc/final_version/app`
* Grep uses regular expressions - a simple technique for expressing textual
  patterns.
  + Warning: Although regular expressions are used by many programs, the
    syntax differs somewhat from program to program.
* Important components of Grep regular expressions
  + Letters and numbers (and some symbols) - Match the letter, symbol, number
  + Period matches any character
  + A list of letters and numbers in brackets match any of those,
    `[abcde]`
    - A caret at the start of the list means "anything but ..."
  + Caret (`^`) usually matches the start of the line
  + Dollar sign (`$`) usually matches the end of the line
  + Backslash can be a quote or a special character
    - `\&lt;` beginnning of word
    - `\&gt;` end of word
    - `\w` word character (alpha numeric)
    - `\\` backslash
    - `\[` open bracket
  + A star after a regular expression means zero or more copies
  + A plus after a regular expression means one or more copies
  + You can parenthesize regular expressions with `\(` and
    `\)`.
* Some flags
  + `-v` - any lines that don't match
  + `-l` - just list the files

Sed - The Stream Editor
=======================

* Sed is primarily intended for batch editing.
* Normal usage: Line specs command arguments
* Line specs:
  + No pattern: Every line
  + /pattern/: Lines that match a pattern
  + A number: That line
  + A number a comman and an address: Go from the first number until the
    address
* Commands
  + `s/source/target/options` - replace (substitute)
    - Typical option is `g` for global
  + `a/\<br>
    text` - append
    - `i` is inset

