Review
======

* Make makes it easier to build programs.
* You describe dependencies and instructions, it figures out which
  instructions to carry out (and carries them out).

Automatic Variables
===================

* The developers and users of make quickly found that it was useful
  to refer to certain portions of the rule, particularly
  + The target
  + The things the target depends upon
* For example, suppose we have
<pre>
foo: foo.o bar.o baz.o
        $(CC) -o foo foo.o bar.o baz.o
</pre>
* We are duplicating a lot of text here.  And, if we decide to add
  a file to the list of sources, we need to make updates in at least
  two separate places (the dependency and the instruction)
* We can avoid some duplication by creating our own variables.
<pre>
FOO_OBJECTS = foo.o bar.o baz.o
foo: $(FOO_OBJECTS)
        $(CC) -o foo $(FOO_OBJECTS)
</pre>
* However, it seems to be a bit time consuming to do that for every rule.
* What we'd really like to say is
<pre>
foo: foo.o bar.o baz.o
        $(CC) -o *target* *prerequisites*
</pre>
* Conveniently, Make provides "automatic variables" for just this
  purpose.
  + `$@` is "the target"
  + `$^` is "the prerequisites"
* And so we would write
<pre>
foo: foo.o bar.o baz.o
        $(CC) -o $@ $^
</pre>
* Isn't that nice and readable?  Well, at least it's short to type.
* There are a few other automatic variables, including
  + `$&lt;` is "the first prerequisite" (why might that
    be useful?)
  + `$?` is "the newer prerequisites"
  + `$*` is "the stem of the target"

Generic Rules
=============

* While there are many reasons to create rules for specific targets, it
  can be equally useful to create generic rules.
* For example, the instructions for creating a .o file from a .c file should
  work no matter what the name of the .c file is.
* There are two models of generic rules.  We'll consider the newer one,
  which may only work with GNU make.
* For generic rules, we usually have some common part (e.g., the stuff to 
  the left of theperiod).  We call that "the stem".
* We represent the stem with a percent sign.
* So
<pre>
%.o: %.c
        $(CC) -o $@ $&lt;
</pre>
* Or, if we've decided to do a funky organization to our code
<pre>
objects/%.o: src:/%.c
        $(CC) -o $@ $&lt;
</pre>

Other Useful Techniques
=======================

* You can execute a shell command and use the result of that command
  as a variable with `$(shell *command*)`
* I often use this is conjunction with substitution.  For example
<pre>
HTML = $(shell ls *.html)
PS = $(subst .html,.ps,$(HTML))
</pre>
* I suppose that you might also use shell variableswith `find`,
  `which`, `whereis`, or something similar to 
  identify locations of files that you plan to use.

Miscellaneous tools and topics
==============================

* You may find it helpful to look at the list of all of the built-in
  rules.  You get them with `make -p`
* No one wants to type in all of the header dependencies.  
  `makedepend` does that for you.
* Packages can be installed in multiple locations.
  `pkg-config` helps you figure out whre.
  + `pkg-config --cflags *package*` computes the
    C flags.
  + `pkg-config --libs *package*` computes the flags
    for the linker.

