This file will show you exactly how to run and execute my program!

Welcome to my Heap Merging Program!

Overview:
The overall goal of this assignment is to take two input arrays that are left heavy when inputed into a heap and merge them using a stack. The implementation of this is a lot more complex than it sounds.
In order to do this, you must first compare the root of each of the trees and put the smaller root into the stack and move to its right child. You must then recursively compare each value and keep pushingthe smaller of the two values into the stack. Once a NULL value is reached, take the last value and make it the right child of the root and switch the heap to being left heavy. Keep on doing this as the 
values wil continue to be the right child of the root.

Input: 
There is no user input in this program but the given arrays from the slides are the "inputs" that are already coded in

Output:
The output of this program will be the the arrays that were given through the slides and the array format of the merged heap

make run:
In order to run this program, simple type "make run" into the terminal and the program will execute.
The output of the two heaps that were merged will then be outputted.

make clean:
After running the program input "make clean" to get rid of the junk files that result from the program.

HAVE FUN!!
