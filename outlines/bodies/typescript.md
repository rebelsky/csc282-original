Background
----------

*Why did Sam give you this assignment?*

* To help you think about dealing with funky characters in input.
* To help you think about dealing with real input.  For example,
  how do you decide how long lines should be?
* To help you think about writing small programs that cooperate with
  others.
* To encourage you to look at tools that let you analyze text files.

Reflection
----------

* What are the complexities of input?
    * We'll look at the question in two ways.
* *What are the things the user does that will cause complexity in the shell?*
    * Arrow keys
    * Backspace
    * Ctrl-U
    * What else?
* *What do you see in the file that corresponds to these actions?*
    * A lot of backspace characters
    * The weird triplet of `esc [ K`
    * What else?
* *How can you tell what characters are in the typescript?*
    * `od -a typescript`
* *How do you figure out what characters those are?*
    * `man ascii`
* *What should should you do with each of those?*
    * Backspace: Have a buffer that you remove characters from.
    * Weird triplet: Remove (?)
    * What else?
* *How big should the buffer be?*
    * Determine empirically?
    * `LINE_MAX` is supposed to be in `<limits.h>` (see examples/linemax.c)
        * It's really in `/usr/include/x86_64-linux-gnu/bits/posix2_lim.h`
        * I think lines can be longer than that.
    * Use dynamic arrays.  (Okay, use malloced arrays and expand if you
      need more characters.)
* *What complications are we ignoring?*
    * Interactive things in the terminal, such as a `vi` session.
    * And yes, it's okay to ignore those.
    * (But if you have time, you should think about it.)

Algorithm
---------

*Given that analysis, what should our algorithm look like?*

    while input characters remain
        ch = next character
        switch ch
          case backspace:
              remove the last character in the buffer
          case 'n':
              print the buffer, reset
          case '\r'
              ignore the character
          case escape
              read two more characters, which will almost be [ and something
              ignore them
          default
              add the character to the buffer
    print whatever remains in the buffer

Build Inputs
------------

* Work in groups of three or four or so students.
* Create a few typescripts that you think will be challenging to 
  a program.
    * Challenging should not be "use vi".
    * Try long lines, lots of erased text (through different forms),
      partial erasures, more.
* See how well any submitted programs work on your inputs.
* Upload them to the repo for further testing.

Write Programs
--------------

* Work in whatever group size you think is reasonable.  I'd recommend
  three, but you can choose.
* Now that you've thought about the general algorithm
