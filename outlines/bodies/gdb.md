Debuggers
=========

* Believe it or not, but many people write incorrect code.
* Testing sometimes helps you identify that code is incorrect.
  + Unit testing helps you narrow done a possible location of the problem -
    if the unit tests for a procedure fail, it's likely that the procedure
    is incorrect.
  + Clear box testing helps you narrow it even further.
* In C, segmentation faults also help you identify that code is incorrect.
* Once you know *that* it is incorrect, you need tools that help 
  you identify *why* it is incorrect.
* What tools are available?
  + The most important tool is *yourself* - you should read through
    the code to see if there are things that don't make sense.
  + You'll often find yourself saying "I'm pretty sure that the
    value is *this* at *this point*."  How do you verify?
    - Use `assert`.
    - Use `printf` statements.  (Not a great idea.)
    - Use a debugger - a program that lets you trace the execution of your
      program and inspect variables
* I can't do much about about the ways you look at code, and I don't
  want you to use `printf`, so we'll look at using a debugger.
* Detour: Why not use `printf`?  Because you spend a lot of time
  inserting and removing print statements.  A debugger is usually much faster.

gdb
===

* gdb is the standard debugging tool for C.
* It's a command-line tool.
  + There are GUIs available, but my experience is that people are often
    faster without them.
* It's fast.
* It lets you do all sorts of creative things, like attach to a running
  process.
* It has a huge array of options.  We'll focus on just a few.

Tracing Crashes
===============

We'll start with one typical use of gdb - figuring out what line in your
program caused a segfault.
We'll use [](../Examples/gdb/boom.c)`boom.c`</a>, a program that I designed to crash.

* You should compile with the `-g` flag.  This enables debugging
  information.  
* Start the debugger 
<pre>
$ **gdb boom**
</pre>
* Run the program 
<pre>
(gdb) **run**
</pre>
* Observe the output
<pre>
Program received signal SIGSEGV, Segmentation fault.
0x08048440 in baz (i=0) at boom.c:64
64          *ip = i;
</pre>
* Check the stack
<pre>
(gdb) **bt**
#0  0x08048440 in baz (i=0) at boom.c:64
#1  0x080483f5 in qux (i=1) at boom.c:55
#2  0x0804840c in qux (i=2) at boom.c:57
...
#12 0x0804844f in baz (i=67) at boom.c:66
#13 0x08048466 in main (argc=1, argv=0xbffffa54) at boom.c:77
</pre>
* Analyze
  + Clearly, 13 recursive calls is bad luck.
  + Hmmm ... the problem seems to be in the assignment
* Look at variables
<pre>
(gdb) **p i**
$1 = 0
(gdb) **p ip**
$2 = (int *) 0x0
</pre>
* Fix.

Some other operations
=====================

**l *LINE_NUMBER***
* List code starting with that line* 
**l *PROCEDURE***
* List code starting with that procedure* 
**b *LINE_NUMBER***
* Stop when execution hits that line number* 
**run**
* Run the program until the first breakpoint* 
**n**
* Execute the next line* 
**s**
* Step into a procedure call (if the next line does not involve a procedure call, does the same thing as n* 
**c**
* Continue execution* 
**p *EXPRESSION***
* Print the value of an expression* 
**watch *variable***
* Stop when the variable has changed.* 

Another Example
===============

* We'll explore another program ([](../Examples/gdb/maplike.c)maplike.c</a>) with a subtle bug.

