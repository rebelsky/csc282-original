CSC282 2015S, Class 02: Some Basic Tasks and Corresponding Tools
================================================================

_Overview_

* Preliminaries.
    * Admin.
    * Upcoming Work.
    * Questions.
* Fun with GitHub.
* Go over homework.
* Extended example.
* Raymond, chapter 1.
* Thinking about basic tools.
* Next homework.

Preliminaries
-------------

### Admin

* I encourage you to attend CS table on Friday and talk about RAID.
* Status check 1: How many of you know the C bitwise operations?
  (`&`, `|`, etc.)

### Questions

_Are your questions intended to be as open-ended as they seem?_

> Yes.  I look forward to discussing interesting answers.  We won't
  discuss all of them, though.

Fun with GitHub
---------------

Problems

* Sam forgot to give me edit permissions / I forget to accept the
  invitation to have such permissions.
* Sometimes git gives incomprehensible errors.

Go over homework
----------------

Given a DOS-formatted text file (lines end with \r\n rather than just
\n), convert it to a standard text file.

* Strategy 1: Write a C program.  Try to remember the wonders of C I/O.

        int c;
        while ((c = getchar()) != EOF)
          {
            if (c != '\r')
              putchar (c);
          } // while

    * Question: Why an int not a character?
    * Because `getchar` needs to be able to signal a special status,
      and returns a value outside the normal range of characters to
      signal those special statuses.  EOF is outside the normal range.
    * Question: How can we compare an integer to a character?
    * `char` is an 8-bit integer, C promotes (converts) types as
      necessary.

* Observation: Overwriting the file is difficult.
* Observation: Doesn't quite meet the spec.  If there's an `\r` somewhere
  else, it still deletes it.  (Sam thinks that's okay.)

Strategy two: Use `tr` (translate).  Traditionally used to translate
one character to another.  Can also delete characters if you use the
-d flag.

        tr -d '\r' < original.dos > fixed.txt

* Observation: Since we're doing single-character processing, it has
  the same problem as the C program.

Strategy 3: Use `dos2unix`, which is not a standard program.  Five minutes.

Strategy 4: Find a more sophisticated text translation tool and translate
"\r\n" to "\n".  The `sed` program is great for this

        sed -e 's/\r\n/\n/g' < original.dos > fixed.txt

* Warning!  The following is a bad idea!

        command < file.txt > file.txt

* Observation: There are lots of flags of sed.

Given a standard text file, convert all uppercase letters to lowercase.

Given a standard text file, remove all blank spaces at the end of lines.  

* Don't write this in C if you want to support arbitrary line lengths.
* Too much context to use tr
* Sed is your friend.

        sed -e 's/ *$//g' < infile.txt > outfile.txt

* The '/g' is not necessary here, but is generally useful.

        $ sed -e 's/a/A/'
        Eh, I wish I were a canadian so that I could say eh.
        Eh, I wish I were A canadian so that I could say eh.
        $ sed -e 's/a/A/g'
        Eh, I wish I were a canadian so that I could say eh.
        Eh, I wish I were A cAnAdiAn so thAt I could sAy eh.

Make a list of all misspelled words in a text file.

        aspell list < file
        aspell list < file | uniq
        aspell list < file | sort | uniq
        spell file | sort -u

Given a CSV file in which each line has the form
`LastName,FirstName,Assignment,NumericGrade`
find the the five highest grades on homework 2.

        Hint: cut, sort, head

Given an HTML file, find the URLs of all images.  In case you don't know
HTML, those will typically look like `<img ... src="*URL*" ...>` The
`img` can have any capitalization (`img`, `IMG`, `Img`,  `iMg`, etc.)
There can be other text between the `img` and the `src`.  (That text
cannot include a greater than sign.)

Raymond, chapter 1
------------------

* Bad puns and too few characters are hallmarks of *nix
* *nix has lots of tools
* Combine small tools into big solutions using a simple communication
  mechanism
* Quick hacks are a good start
* Keep it simple, smartie!

Thinking about basic tools
--------------------------

* A good *nix programmer knows about some set of tools that are available.
* The tools you know about govern how well and how quickly you solve
  problems.
* Good basic tools to know: sed, tr, sort, uniq, grep, head, tail
* Scripting languages are good: Perl, Bash, Awk
* The basics of the system: cat, pipes, <, >, more, less, ...
* Good *nix programmers can write things in C.

Homework
--------

0. Learn Markdown so that we can use it for these assignments.

1. Learn about how you set and get environment variables.  Put your
explanations in your personal directory for the assignment.

    * Command line
    * Bash
    * C (get only)

2. Come up with two or three tasks, similar to those we did for assignment
1, and put notes about them in the tasks directory.  (You can include
some sample solutions in your file.)

3. Read the first chapter of the Make book.

Sam's Fun Programming Problem
-----------------------------
