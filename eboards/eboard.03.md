CSC282 2015S, Class 03: The Bash Shell - A Refresher
====================================================

_Overview_

* Preliminaries.
    * Admin.
    * Upcoming Work.
* Some things you should know.
* Files and directories.
* Command-line patterns.
* File and directory permissions.
* I/O redirection.
* Variables.
* Command-line history.
* The `script` command.

Preliminaries
-------------

### Admin

* There has been a request that we cover `cron` issues.  Would people like
  to do that?
* Homework:
    * Part 0: Create a directory for yourself in the repo.
    * Part 1: Write a program that cleans up after `script`.  Put it
      in the repo.  (I'd recommend using C, but it's up to you.)
        * I'm sure you can find one.  You learn more by writing it.
    * Part 2: Write a bash script that finds all of the files under
      the current directory that end with .jpg and moves them to a
      directory called images.  Put it in the repo.
    * Part 3: Suppose I have a file called `*` in my directory.
      How do I remove.  Suppose I have a file called `-rf *`, how
      do I delete it?

### Questions

* I need some help understanding that Make stuff.  Will you help?
    * Answer: Eventually.
    * Good Unix programmers find that Make is helpful to automate
      tasks
    * Example: Class outlines in Sam's world
        * Administrative stuff
        * Links
           * Based on the day of the semester (vary)
           * Based on the subject matter (consistent)
        * Short summary
        * Overview
        * Detailed information
    
Some things you should know
---------------------------

* Files and directories.
* Command-line patterns.
* File and directory permissions.
* I/O redirection.
* Variables.
* Command-line history.
* The `script` command.

Files and directories
---------------------

* Two ways to think about it: Internal (behind the scenes) and 
  external (client model)
* File is a collection of data.  Bits!  With a name.
* Many mechanisms for telling the type of the file.
    * Custom: Extension gives you information.  `.txt` is a text
      file (usually *nix or Mac), `*.jpg` is an image file using the
      JPEG image format, `.c` is a text file containing C code.
    * Custom: A header (first few bytes) that describes the content
      First two bytes correspond to the ascii values #!, Unix thinks
      it's a script.
    * Experiment: Can I open it with ...?
    * Compute: Inspect the data
* Note: The `file` command tells you an approximate type, based on
  suffix and content and first few bytes.
* Directory is a collection of files and other directories.
* Unix tries to distinguish the two.
* Internally, every file has one or more inodes, which has an
  address, access information, some file type data, some data, and 
  (optionally), a link to the next inode.
* The directory maps names to inodes.
* Unix treats lots of things as files, including devices.
* Know commands for making files and list files and making directories
  and list directories.
    * `mkdir` - create a directory
    * `ls` - list files 
        * If the parameter is a directory, lists all of the elements
          in that directory
        * Given multiple parameters, processes each in turn
        * Flags: -l is detail, -t organized by time, -F suffixes,
          -R recursive, -a hidden

Command-line patterns
---------------------

* ls * - everything
* ls *.x - everything that ends in .x
* ls {foo,bar}.c
* More: See notes and documentation

File and directory permissions
------------------------------

* Three basic kinds: user, group, other
* For each category, three characteristics: read (4), write (2), 
  execute (1)
* Slightly different meanings for directories

I/O redirection
---------------

* >, <, |
* stdout vs. stderr
    * stdout is where the normal outpt of your program goes
    * stderr is supposed to be where error messages go

Variables
---------

Command-line history
--------------------

The `script` command
--------------------

