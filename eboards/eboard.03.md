CSC295 2014S, Class 03: The Bash Shell - A Refresher
====================================================

_Overview_

* Preliminaries.
    * Admin.
    * Reviewing homework 2.
    * Questions.
* Some things you should know about *nix.

Preliminaries
-------------

### Admin

* I encourage you to attend CS table on Friday and talk about P vs. NP.
* Homework:
    * Part 1: Write a program that cleans up after `script`.  Put it
      in the repo.  (I'd recommend using C, but it's up to you.)
        * I'm sure you can find one.  You learn more by writing it.
    * Part 2: Try to teach yourself `vi` or `vim` and add to the list of
      questions you'd like answered or tasks you'd like to learn how
      to solve.
* The following week's homework
    * Part 1: Write a bash script that finds all of the files under
      the current directory that end with .jpg and moves them to a
      directory called images.  Put it in the repo.

### Reviewing homework 2

* Please post things
* Please post things using correct Markdown
* Yes, I know that doing "Learn Markdown" and "read Make" probably
  hit the two-hour mark.

### Questions

_Sam, will you talk about scenarios in which environment variables are
helpful or necessary?_

> Yes, see below.

Some things you should know
---------------------------

* Where the code you use is loaded from
    * The `which` command tells you which one is used
    * The `whereis` command tells you about more copies and about
      libraries
    * Control with the PATH environment variable
* Files and directories.
* Command-line patterns.
* File and directory permissions.
* I/O redirection.
* Variables.
* Command-line history.
* The `script` command.
* Real programming in Bash: Loops, Conditionals

Files and directories
---------------------

* Some basic things that are stored in a filesystem
    * Files (basically, a series of bytes)
    * Directories: Containers for files
    * Links: Connections to other directories/files
    * "Special files"
* How do you identify which files are in a directory?
    * `cd DIRECTORY; ls`
    * `ls DIRECTORY`
    * `ls` alone does NOT list everything.  The `-a` flag also shows
      the "hidden" files/directories that start with a period.
    * The `-F` flag - shows whether things are directories or ...
* Absolute vs. relative
    * Bash keeps track of a current/present working directory
    * Absolute: No matter where I am, this gives the directory
        * Always begin with a slash
    * Relative: From where I am, how do I get there
        * Don't begin with a slash
* Make and remove directories
    * mkdir - create
    * rmdir - remove if empty
    * rm -r - remove, including contents, use sparingly
    * rm -r * - remove way too much

Command-line patterns
---------------------

File and directory permissions
------------------------------

I/O redirection
---------------

Variables
---------

* Broadly, settings or variables that programs can use
* In particular, common things that programs can look up to see what
  your preferences are
    * EDITOR
    * VISUAL
    * PWD
    * PATH
    * LDLIBS
    * LPDEST
* Set with `VAR=VALUE`
* Export your variables if you want other programs to use them
* The variable PS1 stores your prompt.

Command-line history
--------------------

Misc. Useful Commands
---------------------

* `wc` - word count
* Make aliases in your .bashrc

    alias ls="ls -F"

The `script` command
--------------------

* You want to keep track of what happened.
* `script` sets up a log of everything you do, including backspaces.
* Saved by default in `typescript`
* `script FILENAME` saves in that file
* I don't know what the recursive thing does.
