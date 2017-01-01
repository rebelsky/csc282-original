CSC282 2015S, Class 08: Using Macros for Logging
================================================

_Overview_

* Preliminaries.
    * Admin.
    * Upcoming Work.
    * Extra Credit.
    * Questions.
* Interesting macro examples.
* Requirements for a debugging/logging system.
* Implementation details.

Review
------

* Macros in C: Look like functions or values, but implemented as textual
  substitution during preprocessing stage.
* Examples (defining a single value):

        #define ARRAY_SIZE 1000
        int values[ARRAY_SIZE];

    * Let's us give names to "magic numbers"
    * Makes it easier for us to change those magic numbers

* Examples (defining something function-like)

        #define SQUARE(X) X*X

        printf("%d squared is %d\n", i, SQUARE(i));

* Why use #define rather than constant?
    * Constant didn't exist in early C.
    * You can change #defines when you compile.
        -DNAME=VAL
* Why use #define rather than a function call?
    * The #define is more general: It will work with doubles as well
      as integers.
    * Eliminate the overhead of a function call.  In Java, we saw
      a factor of eight difference for including a function call 
      to `swap`.

Macros are dangerous
--------------------
        
        printf("%d\n", SQUARE(2+3));
        int x = 3;
        printf("%d\n", SQUARE(x++);
        printf("x= %d\n", x);

We should have defined it as

        #define SQUARE(X) ((X)*(X))

Interesting macro examples
--------------------------

* printf-style debugging
* Generic code in C

Problems with Printf-Style Debugging
------------------------------------

* Add them, then comment them out later.  Lots of effort.

Solving with Macros

* Strategy 1

        #define LOG(message) printf("%s\n", message);
        #define LOG(message)

* A cool thing you can do with modern macros (e.g., in GNU CC)

        #PARAM gives you a parameter as a string

* Strategy 2

        #ifdef DEBUG
        #define LOG(message) fprintf(stderr, "*** %s ***\n", message);
        #define LOGI(i) fprintf(stderr, " *** %s = %d ***\n", #i, i);
        #else
        #define LOG(message)
        #define LOGI(i)
        #endif

Using Macros for Generics
-------------------------

* Another cool thing with modern macros `PARAM ## text`
  substitutes and then concatenates.
* In C, when we want linked lists for different types, we generally
  copy-paste-change.  Let's think about generalizing that code.
