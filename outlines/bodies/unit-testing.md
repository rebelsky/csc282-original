Some Testing Basics
===================

* How do we know our programs work the way that they are supposed to? 
  + Formal proof (hard, may not be posssible, may not be reliable)
  + Test to see if it works on certain inputs
* Some barriers to formal proof:  It can be difficult to accommodate
  + Arbitrary memory accesses
  + Number representations
  + ...
* Testing applies the scientific method to program design (more or less): 
  Make a hypothesis about what your program should produce and check the result.
  + Typically done multiple times.
* Good testing takes advantages of the strengths of computers
  + Tests are cheap to run, so write lots of them and run them frequently
  + Computers are good at comparing things, so have them check the output,
    rather than checking it yourself.
* Two kinds of testing that we normally do:
  + Black-box testing: Assume we do not have access to the source code.
  + White-box testing: We have access to the source code, and so might
    think about tests that stress particular parts of the soruce code.
* Sam tends to contrast testing, which relies on the computer to check
  results, from experimentation, in which you look at the output yourself.

Some Basics of Unit Testing
===========================

* Unit Testing: An approach to testing your program
  in which we test each "logical unit" of the program separately.
* If the units don't work correctly, the whole won't work correctly.
* Each time you modify your code, rerun the tests to make sure you haven't
  broken anything.
* Auxiliary issue 1: *Test-driven development*: Write tests 
  *before* you write the code.
  + Tests remind you what you want your code to do.
  + You're more likely to write tests if you write them first.
* Auxiliary issue 2: *Test frameworks*: There are a number of
  systems out there to support unit testing.  **jUnit**
  is popular for Java.
  + We won't cover these frameworks today.

An Exercise
===========

* Here's a simple specification of binary search on arrays of integers.
<pre>
/**
* Search ordered array A (of length len) for v, returning the index of v.  
* Returns -1 for "not found".
 *
* Pre: A[i] &lt;= A[i+1] for 0 &lt;= i &lt; len-1
* Post: If for all i, A[i] != v, returns -1
*       Otherwise, returns i s.t., A[i] == v
 */
int ibs (int A[], int len, int v);
</pre>
* Implement it.
* You may find it useful to make copies of
  + [](../Examples/BinarySearch/ibs.h)`ibs.h`</a>
  + [](../Examples/BinarySearch/ibs-expt.c)`ibs-expt.c`</a> - a framework for experiments
  + [](../Examples/BinarySearch/ibs-utest.c)`ibs-utest.c`</a> - a very simple unit test suite
  + [](../Examples/BinarySearch/Makefile)`Makefile`</a>

An Exercise
===========

* So, how would you test your code?  That is, what would your unit
  test framework look like?
* We'll write one version live and then look at others.
* At the end, you should grab 
  [](../Examples/BinarySearch/Sam/ibs-utest.c)my unit test suite</a> 
  and try it on your code.

