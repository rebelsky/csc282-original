CSC282 2015S, Class 12: Testing
===============================

_Overview_

* Preliminaries.
* An introduction to testing.
* An introduction to unit testing.
* Thinking about unit testing in C.
* Exercise, part 1: Write binary search.
* Exercise, part 2: Test binary search.

Preliminaries
-------------

### Homework

* Think about how you would test binary search!

### Admin

* If you are not a senior and you have not registered, do so ASAP!
    * There will be cuts.
    * Poeple who do not pre-register will not get slots.
* Town-hall today!
* Cool talk today!
* Pub night tonight!
* No class next week!
* Exclamation points!

### Questions

An introduction to testing
--------------------------

* We have a responsibility to write correct software (or at least do
  our best to write correct software).
* Gold standard: Formal proof. 
    * Difficult
    * Error prone
* Experimentation / testing
* Good programmers test
* Better programmers write tests before they write code
    * Less bias from/toward the code you write
    * Helps you think more carefully about the code you're going
      to write.
    * Make programming a (really bad) video game: "Look, I'm down
      to 10 failed tests".  "Measurable" evidence of progress.
    * Tests document.

An introduction to unit testing
-------------------------------

* Test smaller units of the program individually
* Test using a framework in which you get a report of either
  "all tests successful" or failures.  (The computer, rather than
  a human, makes sure that the output of each procedure is right.)
* Modern languages include test frameworks - Java - JUnit
* There is no standard for C.

What do we do when we have to unit test our C programs?  (You want
the computer to read the output!)

* Write code by hand

        if (fun(input) != expected_value)
          fprintf (stderr, "Test case 43.1 failed!");

* Write an interactive tester (`tester`)
    * Write a textual input file, (`inputs`)
    * Write a list of expected outpus (`outputs`)
    * `tester < inputs > new-outputs; diff outputs new-output"

* Write a generalized testing framework.  (Using Macros?)

* Find an existing testing framework.  Just because there's no standard,
  it doesn't mean there isn't one.
    * Variant: Stackoverflow  "My annoying CS Prof expects us to do
      unit testing in C.  What would you recommend, other than 
      switching classes?"
    * Note: A good testing framework influences how you test.

* Tradition in C: Use `assert`

Exercise, part 1: Write binary search
-------------------------------------

    /home/rebelsky/Web/Courses/CSC282/2015S/examples/binary-search
    <http://www.cs.grinnell.edu/~rebesky/Courses/CSC282/2015S/examples/binary-search>

Exercise, part 2: Test binary search
------------------------------------




