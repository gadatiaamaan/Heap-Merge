# Heap Merging Program

## Description

Welcome to my Heap Merging Program! This program merges two heaps represented as arrays using a binary heap data structure. It implements heap merging through the use of a binary tree and the merging of individual nodes while maintaining the heap property.

## Input

The program takes two input arrays representing two separate heaps:

Heap A: 4, 19, 8, 27, 20, 12, 43, 15, 25

Heap B: 6, 8, 7, 14

## Output

The output of the program is the merged heap represented as an array, displaying the elements in ascending order according to the heap property.

## Usage

To compile and run the program, execute the following commands in the terminal:

```
make
./heap_merge
```

After execution, the merged heap will be displayed in the terminal.

## Cleanup

To clean up generated files after running the program, you can use the command:

```
make clean
```

This will remove any generated executable or object files.

## Technologies, Algorithms, and Concepts Used

### Technologies:

- **C++**: The primary programming language used for implementing the heap merging program. C++ provides robust support for data structures and algorithms necessary for efficient heap manipulation.

### Data Structures:

- **Binary Tree**: Implemented using the Node class to represent elements in the heap. The binary tree structure facilitates the merging of heaps by providing a hierarchical organization of elements.

- **Binary Heap**: Utilized to maintain the heap property and perform operations such as insertion, merging, and extraction of the minimum element efficiently.

### Algorithms:

- **Heap Merging**: Implemented recursively to merge two heaps while preserving the heap property. The merging process involves comparing the root nodes of the two heaps and recursively merging their respective subtrees.

### Concepts:

- **Binary Heap Property**: Maintained throughout the merging process to ensure that the resulting heap remains a valid binary heap. The property states that for a min-heap, the value of each node is less than or equal to the values of its children.

- **Recursion**: Employed to traverse and merge the subtrees of the two heaps in a systematic manner. Recursion simplifies the merging process by breaking it down into smaller subproblems.

- **Memory Management**: Implemented proper memory management techniques to prevent memory leaks and ensure efficient utilization of memory resources during heap merging and node creation.

Enjoy exploring the Heap Merging Program!