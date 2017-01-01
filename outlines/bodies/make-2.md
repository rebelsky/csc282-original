Review
------

* Make makes it easier to build programs.
* You describe dependencies and instructions, it figures out which
  instructions to carry out (and carries them out).

Variables in Make
-----------------

* Define with `NAME = ...`.
* In most cases, use with $(NAME)

Standard Variables for C
------------------------

These get used with the default rules for C.

* `CC` - the C compiler
* `CFLAGS` - flags for the C compiler
* `CPPFLAGS` - flags for the C preproccesor
* `LDFLAGS` - flags for the loader
* `LINK.o` - The thing that links .o files
* ...

Example: Document Development
-----------------------------

* Make isn't just for C programs.
    * We'll look at a sample ecosystem for simple document development.
    * The inspiration for the ecosystem is my typical Web site development
      strategy.
* It's easy to write in Markdown (.md), and it's what I regularly use.
* Markdown produces incomplete HTML (.htm); just the body, no outer tags.
* We wrap that incomplete HTML in appropriate wrapper text (.html)
* We might want to convert to Postscript or PDF.
* ...

Automatic Variables
-------------------

* The developers and users of make quickly found that it was useful
  to refer to certain portions of the rule, particularly
  + The target
  + The things the target depends upon
* For example, suppose we have
        foo: foo.o bar.o baz.o
                $(CC) -o foo foo.o bar.o baz.o
* We are duplicating a lot of text here.  And, if we decide to add
  a file to the list of sources, we need to make updates in at least
  two separate places (the dependency and the instruction)
* We can avoid some duplication by creating our own variables.
        FOO_OBJECTS = foo.o bar.o baz.o
        foo: $(FOO_OBJECTS)
                $(CC) -o foo $(FOO_OBJECTS)
* However, it seems to be a bit time consuming to do that for every rule.
* What we'd really like to say is
        foo: foo.o bar.o baz.o
                $(CC) -o *target* *prerequisites*
* Conveniently, Make provides "automatic variables" for just this
  purpose.
    * `$@` is "the target"
    * `$^` is "the prerequisites"
* And so we would write
        foo: foo.o bar.o baz.o
                $(CC) -o $@ $^
* Isn't that nice and readable?  Well, at least it's short to type.
* There are a few other automatic variables, including
  + `$&lt;` is "the first prerequisite" (why might that
    be useful?)
  + `$?` is "the newer prerequisites"
  + `$*` is "the stem of the target"

Generic Rules
-------------

* While there are many reasons to create rules for specific targets, it
  can be equally useful to create generic rules.
* For example, the instructions for creating a `.o` file from a `.c` file 
  should work no matter what the name of the `.c` file is.
* There are two models of generic rules.  We'll consider the newer one,
  which may only work with GNU make.
* For generic rules, we usually have some common part (e.g., the stuff to 
  the left of theperiod).  We call that "the stem".
* We represent the stem with a percent sign.
* So
        %.o: %.c
                $(CC) -o $@ $&lt;
* Or, if we've decided to do a funky organization to our code
        objects/%.o: src:/%.c
                $(CC) -o $@ $&lt;

Default Rules
-------------

* As you've discovered, Make comes with a huge array of built-in rules.
* How do you figure out which ones are available?  Make has a useful
  command for printing out all of the rules: `make -p`.

Other Useful Techniques
-----------------------

* In the version of Make we use, you can execute a shell command and use 
  the result of that command as a variable with `$(shell *command*)`
* I often use this is conjunction with substitution.  For example
<pre>
HTML = $(shell ls *.html)
PS = $(subst .html,.ps,$(HTML))
</pre>
* I suppose that you might also use shell variables with `find`,
  `which`, `whereis`, or something similar to 
  identify locations of files that you plan to use.

Miscellaneous tools and topics
------------------------------

* No one wants to type in all of the header dependencies.  
  `makedepend` does that for you.
* Packages can be installed in multiple locations.
  `pkg-config` helps you figure out where.
  + `pkg-config --cflags *package*` computes the
    C flags.
  + `pkg-config --libs *package*` computes the flags
    for the linker.
* Modern Make files are sufficiently complex that there are now programs
  (particularly `automake`) that make them for you.
