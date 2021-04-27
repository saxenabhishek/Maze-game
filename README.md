# Maze Solver

## Question

we are given a grid of 0’s and 1’s, 0’s corresponds to a place that can be traversed, and 1 corresponds to a place that cannot be traversed (i.e. a wall or barrier); the problem is to find a path from bottom left corner of grid to top right corner; immediate right, immediate left, immediate up and immediate down only are possible (no diagonal moves). The problem is to find a path of least cost through the maze.

## Our Solution

We made a small program first that generates problems for the question. Then we worked on using the Dijkstra algorithm to find the most efficient path in the maze.

## How to use:

1. Compile the programs in a C++ compiler. The project used MinGW, but it can be compiled with any other compiler.
2. To generate a question, run the problenGen.exe file and pass two integer arguments to it. This will create a file with the question in it. The spaces which can be walked on are given by ‘-’ and the blocked paths are provided by ‘O’
4. Then call the Solver file and pass the location of the problem text in it. This file will print the question in integer form and then print the solved version.

**Note:** In the solved version, the path is represented by ‘+’ symbols, from the top left to the bottom right.

## Example use

```shell
> ./path/to/ProblemGen.exe 4 4 ; cat ./problem/question.txt
> ./path/to/Solver.exe './problem/question.txt'
```

```
0 0 1 0
+ 0 0 1
+ + 1 0
1 + + +
```
