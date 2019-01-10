Lyman Shen
10/2/18

Task 1

Description

This is a simple shell program that takes text input

Logic

When the user types in any string, a Hello World program is run
When the user types in "exit", the program will exit

How I tested

This shell program is tested by compiling the Hello World program in the same directory,
then compiling this shell program, and then executing the shell program.

Task 2

Description

This is program that arbitarily creates 8 child processes, 
where no process has more than 2 children

Logic

I designed this program so each process has at most one children,
and with 8 total parent processes, there are 8 children processes.
It works by forking each process, than looping to make sure only
the children created from the fork runs fork the next time.

How I tested

I tested the solution by printing the process id of the original program,
then print the process id and the parent's process id for each child process.
This lets me count that there are 8 child processes and no more than 2 processes
share the same parent.

Task 3

Description

Write a program that launches 12 process, where each parent process
has 2 or 3 children.

Logic

My solution takes advantage of the fact that having 3 children process
that each have 3 children process will create 12 children processes.
This allows me to write a loop where each time it is run, the newest
children processes create 3 more children process. With this only needed
to be done two times, I created a counter to make sure the loop runs
only two times.

How I tested

To test that each process that is a parent process has at most 3 children,
I printed the process id of the original and the process id with the parent's
process id for each child process for each run. To make sure the parent processes don't die,
waitpid is used in a loop so all children need to have exited before the parent
exits.

Task 4

Description

Create a program that launches 17 children process where each parent process has 2 or 3 children

Logic

In my implementation, the main part of the program has the original process having 2 children
processes, and subsequently each new children process also have 2 new children process. Doing
this for 3 times creates 14 children processes. For the last 3 processes, I added a third
child process to the original process, and let that child process have 2 more child processes.

How I tested

I tested the code by printing the process id of the original process, then printing the process id and the parent's process id for each child process created.
