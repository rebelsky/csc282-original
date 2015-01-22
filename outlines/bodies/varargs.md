Writing C Functions that Take Variable Numbers of Parameters
------------------------------------------------------------

* At times, it's helpful to write procedures that take varying numbers of
  parameters (or varying types of parameters).
* The most obvious one is `printf` and it's variants.
    * Side question: What are some alternatives to a variable-parameter printf 
      and why don't we use 
      them?
        * Append all of the strings, as in Python and Perl, and then print the
          appended strings. [Inefficient]
        * One procedure call per part of the output string. [Long, less clear]
        * ...
* What are some other instances?
    * Building an array (pass in all of the parameters)
    * Iterating over a sequence of values (shorter than a for loop, and 
      easier if your values aren't already in an array or other structure)
    *  Writing your own alternative to printf (e.g., to output somewhere else)
    * Writing a wrapper for printf
    * ...
* It's not a technique that most programmers use a lot, but it's an
  important tool to have in your toolbox.
* Languages treat variadic procedures in multiple ways
    * Some languages don't provide variable-parameter procedures at all.
    * Some provide them only for built-in procedures
    * Some provide them as a feature
    * SOme use variadic procedures as they primary model
* Fortunately, C not only provides built-in variable-parameter procedures,
  it lets you write your own.
    * You can write variable-parameter procedures
    * You can also write variable-parameter macros

C's "varargs" facility
----------------------

* In C, the library that permits you to write procedures with a variable
  number of procedures is called *varargs*
* To use varargs, you need the stdarg.h library
* To say that a procedure has a variable number of parameters, you need at
  least one named parameter and write a set of ellipses in the function 
  header for "the rest".
    * For example, the signature of `printf` is <br>
       `int printf (char *format, ...);`
    *  Something that builds an array of ints might have the signature <br>
       `int *iarray (int v0, ...);`
* In your code, you declare a variable of type `va_list` for 
  "the rest".
* You initialize `va_list` with `va_start (rest, prevparam)`
    *  `rest` is our variable of type `va_list`
    * `prevparam` is the name of the parameter that comes before
       the ellipses
* You get the next parameter with `va_arg (rest, type)`
    * `type` is the type of the parameter
    * This macro has the side effect of changing `rest`
* When you're done with a parameter list, you *must* call
  **va_end (rest)**.
* If you need a copy of a `va_list`, you create the copy with
  `va_copy (va_list dest, va_list src)`.
* *Warning!~*: Integers smaller than `int` are promoted
  to `int`; Floating point values are always `double`.

Some Examples
-------------

* Code should be in [the sample code directory(../examples/varargs/).
* `[simonsays.c](../examples/varargs/simonsays.c)` explores printing 
  multiple strings.
* `[sum.c](../examples/varargs/sum.c` explores summing floating point
  values.

Design Issues
-------------

* When you're iterating through the parameters, how do you know that you're
  done (or what the types of the parameters are)?   
* There are two typical strategies.
    * Your initial parameter tells you what the other parameters are.
    * You have a special sentinel that says you've reached the end of the
      parameters.
* We'll look at some simple printing examples to illustrate this concept.
* `[writer1.c](../examples/varargs/writer1.c)` uses a printf-style approach.
* `[writer2.c](../examples/varargs/writer2.c)` uses a "prefix with types" 
  approach.  (There's a particular type for "end of input".)

Variadic Macros
---------------

* Details in <http://gcc.gnu.org/onlinedocs/cpp/Variadic-Macros.html>
* You can use ellipses, much as you do in C functions.  However, in this 
  case, you just get to refer to "the rest" as `__VAR_ARGS__`.
* If you want to name the variable parameters, prefix the ellipses with a name,
  as in `#define myprint(stuff...) printf (stuff)`.
* I don't see variadic macros used much except as a wrapper for variadic
  functions.  
* I suppose you could use them for a form of higher-order programming
<pre>
#define CALL(fun, params...) fun (params)
</pre>

Behind the Scenes
-----------------

* So, how are the varargs macros implemented?  It depends on the particular
  compiler and architecture.
* However, if we deal only with a stack-based calling mechanism, it's 
  pretty straightforward.
  + `va_start` points immediately "after" it's parameter
  * `va_arg` advances the parameter
* Look a `[stack.c](../examples/varargs/stack.c)` for
  an exploration of the arrangement of the stack.
* Note that you should not rely on this arrangement: Smart compilers leave
  parameters in registers rather than putting them on the stack.

