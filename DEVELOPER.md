Developer Notes
===============

This repository and its forks are designed as places for me to hold
the Web materials for my various courses.  I use a combination of 
Markdown and Docbook to manage my course webs.

Some information on the design of the sites is in the manfiest.

Directories
-----------

I try to have a different directory for each "section" of the site 
(assignments, readings, etc.).  Right now, I have a hack for getting
custom settings for each section - I link the main XSL stylesheets to
the current directory.  That way, we can load some files in the current
directory (e.g., the entities).

Forks and Branches
------------------

There is one main repository for the "generic" materials (the basic
structure, some of the software, documents that I tend to have in
every class, etc.).  Each class then has its own separate repository.
Why separate repositories, rather than branches?  Because each course
installation will have its own copy of this repository, and I don't want
too much baggage.

Within each course repository, there is a branch for each semester.
(Ideally, the master branch is the current semester and at the end 
of the semester I add a branch at the current position of the repo.)

Pulling Updates from the Generic Course
---------------------------------------

Just the normal instructions for pulling from an upstream source (plus
ensuring that we link to the upstream).

Approach 1:

    make generic
    git fetch generic master
    git merge upstream/master

Approach 2:

    make generic
    git pull generic master

Approach 3:

    make pull-generic

Pushing Updates to the Generic Course
-------------------------------------

My initial experiments at pushing a limited number of updates from a 
fork back to the main branch were not particularly successful.  For now,
the best strategy seems to be to make generic updates in the generic
course.   I've put some quick notes on the basic structure of what I've
tried at the end.

At the Beginning of the Semester
--------------------------------

### In The Generic Repository ###

1. Add the dates files (whatever form that takes)

### For An Individual Course ###

1. If you're starting a new course, follow the *Starting a New Course*
   instructions below.  (I usually do this in a sandbox.)

2. Clone the course repository into the directory you plan to use for the 
   course.  E.g.,

        cd /home/rebelsky/Web/Courses/CSC000/
        git clone https://github.com/rebelsky/csc000 2013F
        cd 2013F

   you may also want to use

        git clone git@github.com:rebelsky/csc.git 2013F

3. Edit `resources/course.ent`, which has the course-specific information.

        vi resources/course.ent

4. Edit `resources/links.xsl`, which contains the links to previous offerings
(among other things).

5. Make `resources/subjects.ent`, which is required by a bunch of other files.

        cd resources
        make subjects.ent

6. Edit `home/index.sect` or `home/index.md`, which contains the front
door for the course.

7. Set up the schedule files (some details in a section below)

a. Make the `overviews` directory and run `../tools/schedule-overviews`

b. Also make sure to check `handouts/Makefile`, since `schedule.html` and
`sched.html` are automatically generated from that file.

8. Clear out and rebuild the daily administrative notes.

        cd outlines
        rm admin/*
        ../tools/all-outline-parts 56
        
9. Run Make at the top level, just to make sure that things are okay

        make

10. Look at a page on the Web

11. Commit the changes that you've just made.

12. Start editing and creating!

At the End of the Semester
--------------------------

1. Make sure to commit or throw away any of the remaining changes you've
   made.  (In an ideal world, you've been doing this as you go.  In the
   real world, you've probably got a lot to do now.)

2. Push to the repository.

3. Since you're about to start a new version of the course, make a branch
   for this old version.

     git checkout -b 2014S
     git push origin 2014S

Starting a New Course
---------------------

To create a new course, I need to fork the generic course repo. 
Unfortunately, github is not particularly nice about letting you fork
your own repositories.  There's a nifty hack that I found at
<http://bitdrift.com/post/4534738938/fork-your-own-project-on-github>.

It goes something like this.

1. Create the repository for the new course on github.  For this example,
   I'm using csc000.  Do not add a README, LICENSE, or .gitignore.

2. Clone the original repository onto your local machine

        git clone http://github.com/rebelsky/generic-course csc000

   or

        git clone git@github.com:rebelsky/generic-course.git csc000

3. Edit the Git config file

        cd csc000
        vi .git/config
        :1,$s/generic-course/csc000/g
        :wq

4. Push the changes back to the repository

        git push -u origin master

5. Check on github to see that everything worked.

6. Update the generic site with a link to this fork.

7. Do the normal start of semester activities.

Working with the Outlines and Schedule
--------------------------------------

I've set up a slightly complex system for dealing with the course
schedule, the daily outlines (what I plan to talk about), and the daily
eboards (what I actually talk about).  When setting up a new course or
updating an existing course, it's important to do thinking in something
like the following order:

1. Update resources/subjects.var to list all of the daily subjects.

2. Create appropriate subdirectories of outlines.  (admin, bodies,
overviews, related, summaries)

3. Create all of the appropriate .md files.  You can use 
tools/outlines-parts-blank-md, tools/outline-parts-md, or
tools/all-outline-parts.  (tools/outline-parts-md copies files
from old Siteweaver courses, and needs to be configured appropriately.)

4. Create the directory handouts/overviews.

5. In the handouts directory, run the command `../tools/schedule-overviews`
to make XML equivalents to the `md` files.

An Incomplete Strategy for Pushing Updates from Forks
-----------------------------------------------------

The difficulty in pushing updates from forks is that you've usually
changed and added lots of files, but only a few of those changes really
need to be propagated back.  These are my quick notes on what should work.
I haven't gotten these instructions to work completely, and they are a
bit messy, so they need some more experimentation.

In the instructions below, code prefixed with `generic$` should be
done in the directory for the generic course and code prefixed with
`course$` should be done in the directory for the specific course
(the fork).

1. Make sure that everything from the generic repository has been pushed
   back to the server.

        generic$ git push

2. Make sure that you have the latest version of the generic course.

        course$ make generic
        course$ git fetch generic master
        course$ git merge generic/master

3. Create two branches, one immediately before the change that should
   be pushed, one immediately after.  We'll call them 'base' and 'update'.

        course$ git checkout -b base
        course$ git reset <commit>
        course$ git checkout -b update
        course$ git reset <commit>

4. Make sure that you're in the update branch

	course$ git checkout update

5. Stash changes (I don't know why this is necessary, but it seems to be).

        course$ git stash

6. Rebase onto the generic.  The -i lets you select which changes you want.
   (If you select only a few changes, git may need you to do some extra
   things other than just the stash above.)

	course$ git rebase -i --onto generic/master base update

7. Push this update to the generic-course repository.

	course$ git push generic update

8. In the generic directory pull the changes.  (I'm not sure if the 
   fetch is necessary.)

        generic$ git pull 
        generic$ git fetch origin update 

8. Rebase again.  (Yeah, this shouldn't be necessary.  But I can't get
   a fast-forward unless I do this.)

        generic$ git rebase --onto master origin/master origin/update

9. Name the new branch created by rebasing

        generic$ git checkout -b temp

10. Switch back to the master branch.

        generic$ git checkout master

11. Merge the temporary branch

        generic$ git merge temp

12. Get rid of the temporary branch

        generic$ git branch -d temp

13. Get rid of the update branch.  (Isn't this ugly?)

        generic$ git push origin --delete update

14. In the course repository, get rid of the update and base branches

        course$ git branch -d base update

