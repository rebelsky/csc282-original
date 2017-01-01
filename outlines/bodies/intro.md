Motivation
----------

This course is an extension of a seminar I ran in spring 2012 and that
students asked me to repeat in spring 2013, that I repeated in spring
2014, and that we have now regularized.  That seminar was an outgrowth
of things I observed and was told in CSC 362 2011F.  In particular, the
students in that course had much less familiarity with Makefiles than
I would have liked and they told me that they generally did not use gdb
when debugging their programs.  I also observed that many of them were
less than competent at dealing with memory leaks in their programs.

I do not blame my students for these flaws in their background.  Rather,
I expect that it's a consequnce of our decision to teach these issues
relatively early in their careers and of different faculty opinions on
what is important to teach.  (I'm not sure that students who took 161
from me have substantially different backgrounds from those who took it
from someone else.)

A few of the students asked me to spend some additional time teaching
the things that I consider important (and that they quickly found were
important).  But we didn't have class sessions to spare.  This class
is therefore my attempt to address some of the weaknesses that I or the
students observed.  I hope to offer it every year.

Policies and procedures
-----------------------

* You can find most of the information on this course on the Web.
* I'll admit that many of the "standard" documents (e.g., my
  notes on disabilities) are simply copied and pasted from previous years.
  Let me know if anything seems out of place.
* I will focus on keeping the outlines, Eboards, book, and schedule
  up to date,
* This is an S/D/F course.  Show up, be active, do the homework and you pass.  
  Miss more than two classes or two assignments and you fail.
* We'll take a quick look at [the current version of the
  schedule](../handouts/schedule.html) so that you can see how I plan to
  approach the course.

Principles and practices
------------------------

* From my perspective, this course is about three related issues:
    * Generally good programming practices
    * How to think like a *nix programmer
    * How to think like a C programmer
* We'll look at a few important issues in each

### Important programming practices

Since I'm teaching this course, I get to impose my favorite practices on
you.  (I'll note that most of our students who leave Grinnell and go on
to careers in programming find that I'm right about most of these things.)

* *Document*.  Odds are that you will need to reuse some of your 
  stuff later, and you will not remember what you did before.
* *Test* (preferably automatically).  If you plan to have others use 
  your program or library, you should make sure that it works correctly.
* *Refactor*.  If you find yourself programming by copy-paste-change, 
  it's probably time to write a more general function.
* *Encapsulate*.  Your libraries should provide a simple interface, and
  should stick to that interface.  For example, I think it's bad practice
  to have a library directly issue error messages.
* *Format*.  Your code should be clean and readable.  When possible, 
  follow some language formatting standard.  (I tend to use the GNU
  standards in C.)

You can take all of these with a grain of salt (or many many grains of
salt) when you're just writing quick-and-dirty code to get stuff done.
Keep in mind that your typical goal is efficiency.  You don't need to
comprehensively test a few-line throwaway program.  However, you should
document the program, because you may want to do a similar thing later.

### Some key *nix principles

Unix and its descendents have been around a long time.  They must be
doing something right.  So, what are the principles that have made
*nix so successful?  Here are a few particularly important principles
that many C/*nix programmers follow.  (We will expand upon these as the
seminar continues.)

* Don't do things by hand when you can more efficiently do them with
  a program.
    * <http://xkcd.com/1205/>
    * <http://xkcd.com/1319/>
* Write small programs and libraries that have a very focused purpose.
    * And save them for later.
* Chain together small programs to solve more complex problems.
* Communicate with text files.
* Share!

That first principle may seem a bit daunting.  Do you always write 
programs to do tasks?  No, you can certainly use programs.  Here are
ways you better do things "by program".

* Know the primary tools that Linux provides.  (We'll make a list.)
    * It's okay to know generally what they do and to read the documentation
      when you need more info.
* Be able to write your own small tools in some scripting language. 
  (I tend to script in Perl.  Python, Bash, Ruby, and even PHP can all be useful
  scripting languages, too.)
* Be able to write your own small tools in C.  (Sometimes you need speed.)
* Know enough *nix bash syntax to tie things together.

### Some important C practices

In addition to the general programming practices I've mentioned above,
there are a few approaches that C programmers should master.  (We'll
add more as the semester goes on.)

* Know how to use the C preprocessor, particularly `#include` and
  macros.
* Know how to use a debugger.
* Know how to use libraries.
* Understand memory: How pointers are used, how malloc works, etc.
  It's also useful to trace your programs' memory usage (e.g., using
  valgrind)

There are also things one should learn about over the longer term, including
threads, signals, and some common libraries (such as libraries for 
processing the command line).  Due to limited time, we probably won't
cover those in this course.

Thinking in C: A Simple Example
-------------------------------

The following code comes from K&amp;R (although it is reformatted).  What 
does it do?

    char *
    fun (char *t, char *s)
    {
      while (*t++ = *s++);
      return t;
    } // fun

Detour: A C Memory Problem
--------------------------

*Activity/Discussion*

To illustrate my point that understanding memory in C is important,
let's continue with a problem that a friend gave to me a while ago.
He showed me the following fragment of C code.

<pre>
  x = malloc (...);
  foo ();
  bar ();
  free (x);
</pre>

The program was crashing on the call to `free`.  

Here are some things he discovered.
* If he removed the call to `free`, the program ran through 
  to completion.  
* If he moved the call to `free` before the call to 
  `bar`, the program ran through to completion.  
* He had no calls to `free` in `bar`.  

What is likely to be wrong with his code?

Exercises: Some simple tasks
----------------------------

*Activity*

Here are some tasks that I find it useful to think about.  They illustrate
some kinds of tasks that people often find they have to do and give you the
opportunity to explore different approaches.  For each problem, we'll
make a list of ways to approach the problem (e.g., "Write a C program")
and estimate the time each would take.

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
   
*Homework*

This will appear online some time in the near future (probably over the
weekend).

Repository: `https://github.com/Grinnell-CSC282/hw1-2015S`

1. Read chapter 1 of Raymond to get a deeper understanding of the *nix
Philosophy.

2. Find good solutions to any of the tasks we did not solve in class.  (That
is, write a program or command to solve the task.)  Put them in a folder
with your name in the GitHub repository.

3. Make a list of *nix tools and utilities that you've found useful (or 
even that you've just heard of).  Try to categorize and add a short
description.  Add them to the `tools.md` file in the repository.

