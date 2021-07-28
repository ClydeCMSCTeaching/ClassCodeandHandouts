## Week 1 Class 1

In general, I will add a readme to the class files with a general outline of what we discussed. You ought to watch the lectures or attend however. 

Additional readings (not required):
https://publications.gbdirect.co.uk//c_book/ Chapter 1 and 2

## Lecture 1
Overview of c.  A few first programs.

#### hello world
Take a look at `helloworld.c`. To compile the program, which is to go from human readable code to machine code executable by a computer, run `clang helloworld.c`. To run the program, `./a.out`. To rename the executable from `./a.out` use the `-o` flag for clang. i.e. `clang helloworld.c -o myprogram` then run `./myprogram`. 

#### basic program 
Take a look at `singlemaintemp.c`. This program converts a user specified temperature in Celsisus to Fahr. This program only utilizes code in the main function. In general, we want to abstract out general routines which could be reused later on (or as part of a library of routines). In `functiontemp.c`, we abstract out the `convert_celsisus_to_fahr` routine as a function. This is better style than `singlemaintemp.c`. 


#### bug analysis
Can you spot all the bugs in `buggy_functiontemp.c`?

#### Variables
    - A variable is a named storage location. All variables have types which specify how to interperate the data inside the storage location.
    - There are rules for variables names though generally just name your variables meaningfully ()


## Lecture 2
Splitting into header and code files and basic conditionals. 
