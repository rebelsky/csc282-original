Some Simple Shell Stuff
-----------------------

* To use *nix, you need to be proficient in the basics of shell usage.
  + I'll focus on bash, the Bourne-again shell
* What do I consider "the basics"?
* You should know how to make and use *files and directories*.
* You should know about *file permissions* (and how to set them 
  numerically or mnemonically)
* You should understand basic ways to deal with *redirecting program I/O*
    * You should know how to redirect the output of a program.
        * To a file
        * To another program
    * You should know how to redirect the input of a program.
        * From a file
        * From another program
    * You should know about the differences between stdout and stderr and how
      to take advantage of those differences.
* You should know about *command-line patterns*
* You should know how to set and get *normal shell and environment 
  variables* (and why you how might do so).
* You should know how to take advantage of the *shell history*.

Files and Directories
---------------------

* `ls`
    *  And its flags.
* `mkdir`
* `rmdir`
* `rm`
    *  Exercise: Remove the file named `-f`, remove the file named `*`.
* `cd` vs `pushd`
* Links, soft and hard
    *  Activity: We'll explore effects of deleting files with the different 
       kinds of links.
* `du`

Command-Line Patterns
---------------------

* `*` - everything
* `*.jpg` - all the files that end with .jpg
* `{alpha,beta}.jpg` - alpha.jpg and beta.jpg
* `e?.jpg` - e1.jpg and e2.jpg but not echo.jpq

File and Directory Permissions
------------------------------

* Three parts: User, group, other
* Each part has three settings: Read (4), Write (2), Execute (1)
* Question: What do the parts mean?
* Question: What do the parts mean for directories?
* Special thing: The setuid bit.  What do you think it does?

I/O Redirection
---------------

* Why?
* Files vs. Pipes
* Stdout vs. Stderr
    * How do you combine them.

Variables
---------

* Two kinds: Standard environment variables and user-defined variables.
* Used like all variables: To give a name to information that may vary
  (e.g., from user to user).
* Generally set with a command like <br>
   `*var*=*value*`
     *  No spaces are allowed in the value, so when you need spaces, put 
        the value in quotation marks.
* Access variables as `$*var*`
* Environment variables are shared from program to program.
* May need to export enviornment variables. <br>
  `export *VAR*="*value*"` <br>
  or <br>
  `export *VAR*`
* List all current environment variables with `printenv`

Command-Line History
--------------------

* Bash (and the *nix shells) keeps a history of the commands you've typed.
* You can repeat a command with an exclamation point and command number,
  such as `!10`.
* You can repeat the previous command with `!!`.
* You can repeat a command that begins with a particular string with
  `!*str*`.  I use `!make` a lot.
* You can extract the last "word" on the previous line with !$.
  + I might write `*program* &gt; *file*` and then
    `less !$`, particularly if the file has a long pathname.
  + I might use `cp *file* *dir*` followed by a
    `cd !$`.
* Command-line history is also useful with the command line browser
  (up and down arrows, plus editing).

The `script` Command
-------------------------------

* Sometimes you want a record of what you've done.
* The `script` command starts a new shell and records input, output,
  and more.
* Finish with <ctrl>-D.
* But leaves "garbage" in the file (see example).

Bash Control
------------

* Bash is a programming language.  At times, you'll want to write
  scripts to do useful tasks.
* Examples
    * Rename all the files that end with .jpeg to .jpg
