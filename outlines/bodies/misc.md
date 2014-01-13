assert - simple program checking
================================

* As you've seen, there are a variety of approaches to testing C programs.
* A *very* common approach (one that is included in every C implementation
  I know) is to use *program assertions*.
* An assertion is essentially a statement that "I expect this condition
  to hold at this point in the program".
  + It's like a test, but at a finer grain.
* For example
<pre>
  i = 5;
  // I assume i is 5
  foo (i);
  // I assume i is still 5, since C is a pass-by-value language
</pre>
* The `assert` macro takes as parameter a Boolean expression,
  executes the expression, and, if it fails, terminates the program and
  reports the line at which it terminated.
* You can turn off the assert macro with the -DNDEBUG flag.
* *Don't call assert with operations that have side effects!*
  It often leads to Heisenbugs.

Memory Issues in C Programs
===========================

* One of the benefits and hazards of working with C is that you have
  direct access to memory.
* There are a host of problems that people encounter when working with
  memory.
* I'll make you list yours.
* Here are some of mine:
  + Memory leaks: Failing to free memory that you've allocated.
  + Invalid references: Continuing to use memory after it's been freed.
  + Invalid array indices: Referencing outside the bounds of the array.
* Many of these errors are subtle.  They don't cause problems at the time
  you make the error, they cause problems elsewhere in the program.
* Tracking them down is important!

Valgrind: Tracking memory issues
================================

* Valgrind is a swiss-army-knife of program analysis, but I use it primarily
  for its memory checking features.
* You run valgrind on a program you've compiled.
* It runs the program a bit more slowly, and reports on all of the memory
  issues it's encountered.  
  + It even reports on errors that it hasn't encountered.
* We'll take a look at a variety of programs.  The errors in these programs
  are all fairly explicit, but are the kinds of things that often happen
  inadvertently.
  + One that runs correctly.
  + An out-of-bounds index accompanied by a failure to free memory.
  + Inadvertent reuse of stack memory.  (In two forms.)
  * Inadvertent reuse of heap memory.  (IN two forms.)

Sorting
=======

* Suppose we have the following function
<pre>
/**
* Sort an array of strings alphabetically.
 */
int strings_sort (int n, char *strings[])
</pre>
* Now, suppose you want to sort arrays of strings by length.  How would
  you build the new function?
* Option 1 - Copy, paste, change
  + But that should set off red flags.
* Option 2 - Factor out the common code with macros
  + E.g., write a macro that generates the body of the sort routine,
    but takes the comparator as a parameter
  + Leads to name expansion!
* Option 3 - Pass in the comparator as a parameter
<pre>
/**
* Sort an array of strings using comparator.
 */
int strings_sort (int n, char *strings[], "*something-that-compares-strings*" compare)
</pre>

Function Pointers
=================

* But how do you pass a function as a parameter in C?
  + In C, we say that you pass in a `function pointer`
* Basically, we write a declaration of the variable as a function, but
  also add a star (it's a pointer) and parenthesize (for clarity)
<pre>
int strings_sort (int n, char *strings[],
                  int (*compare)(char *str1, char *str2));
</pre>
* You can declare variables of this type, too
<pre>
int (*binary_integer_function)(int x1, int x2);
</pre>
* But many people find these declarations.  And so they define types
  instead, (e.g., `StringComparator`)
* You declare function pointer types much like you declare function pointers.  
  The only real difference is that you use `typedef` before the
  declaration.  (Yeah, that's how typedef always seems to work.)
* For example,
<pre>
typedef int (*StringComparator)(char *str1, char *str2);
</pre>
* And now, we can write
<pre>
int strings_sort (int n, char *strings[], StringComparator compare);
</pre>
* There are two ways to call the function.
* You can write
<pre>
(*compare)(str1, str2)
</pre>
* But you can also write
<pre>
compare (str1, str2);
</pre>

