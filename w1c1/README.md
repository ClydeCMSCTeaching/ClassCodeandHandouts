## Week 1 Class 1


#### hello world
Take a look at `helloworld.c`. To compile the program, which is to go from human readable code to machine code executable by a computer, run `clang helloworld.c`. To run the program, `./a.out`. To rename the executable from `./a.out` use the `-o` flag for clang. i.e. `clang helloworld.c -o myprogram` then run `./myprogram`. 

#### basic program 
Take a look at `singlemaintemp.c`. This program converts a user specified temperature in Celsisus to Fahr. This program only utilizes code in the main function. In general, we want to abstract out general routines which could be reused later on (or as part of a library of routines). In `functiontemp.c`, we abstract out the `convert_celsisus_to_fahr` routine as a function. This is better style than `singlemaintemp.c`. 


#### bug analysis
Can you spot all the bugs in `buggy_functiontemp.c`?