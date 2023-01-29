<p align="center">
    <img src="https://user-images.githubusercontent.com/102881479/215293860-e27b9364-54db-40a7-acf8-691e7e7fe680.png">
</p>
<p align="center">
    <img src="https://img.shields.io/badge/OS-Linux-blue" alt="OS">
    <img src="https://img.shields.io/badge/Language-C%20%7C%20C%2B%2B-blue.svg" alt="Language">
    <img src="https://img.shields.io/badge/Grade-84%2F100-brightgreen.svg" alt="Grade">
    <img src="https://img.shields.io/badge/Status-Completed-brightgreen.svg" alt="Status">
</p>

## Introduction

This project is about sorting data on a stack with a limited set of instructions, using the lowest possible number of actions. It aims to teach students about how to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

There are two stacks `a` and `b`. At the beginning, stack `a` contains the numbers to be sorted and stack `b` is empty. Only eleven stack operations are allowed. All of them are listed below:

| Abbreviation | Stack operation | Description |
|:------|:------|:------|
| `sa` | swap a | Swap the first 2 elements at the top of stack `a`. |
| `sb` | swap b | Swap the first 2 elements at the top of stack `b`. |
| `ss` | swap both | `sa` and `sb` at the same time. |
| `pa` | push a | Take the first element at the top of `b` and put it at the top of `a`. |
| `pb` | push b | Take the first element at the top of `a` and put it at the top of `b`. |
| `ra` | rotate a | Shift up all elements of stack `a` by 1. |
| `rb` | rotate b | Shift up all elements of stack `b` by 1. |
| `rr` | rotate both | `ra` and `rb` at the same time.  |
| `rra` | reverse rotate a | Shift down all elements of stack `a` by 1. |
| `rrb` | reverse rotate b | Shift down all elements of stack `b` by 1. |
| `rrr` | reverse rotate both | `rra` and `rrb` at the same time. |

## Project performance

The algorithm implemented was radix sort with bitwise operations to make it possible to work with only two stacks. The table below lists the project's efficiency to sort 100 and 500 random numbers respectively from grade 5 (best performance) to grade 1 (lowest performance).

| Grade | Stack operations to sort 100 numbers | Stack operations to sort 500 numbers | Project performance for sorting 100 numbers | Project performance for  sorting 500 numbers |
|:------|:------|:------|:------|:------|
| 5 | less than 700 | less than 5500 | - | - |
| 4 | less than 900 | less than 7000 | - | 6756 |
| 3 | less than 1100 | less than 8500 | 1025 | - |
| 2 | less than 1300 | less than 10000 | - | - |
| 1 | less than 1500 | less than 11500 | - | - |
## How to compile and run the project


#### 1) Copy this repository to your local workstation

```html
git clone git@github.com:ygor-sena/42cursus-push-swap.git
```

#### 2) Compile the project with Makefile

```html
make
```

#### 3) To test the program with many numbers, create a local variable that generates random values:

```html
ARG=$(shuf -i 0-2000 -n 500)
```

This command generates 500 random numbers between 0 and 2000.

#### 4) Run the program

```html
./push_swap $ARG
```

If you want to run the program looking for memory leaks, just start it as follows:

```html
valgrind --leak-check=full --show-leak-kinds=all ./push_swap $ARG
```

#### 5) Output information and stack operations count

After a valid argument is received, the program will start to sort the given numbers and print to the standard output all stack operations executed in order to accomplish its task. To count the number of operations, just run the program as follows:

```html
./push_swap $ARG | wc -l
```

In this example, to sort 500 random numbers with radix sort, the output of the total stack operations done will be roughly 6756.

## References

- General reference books:

  - BHARGAVA, Aditya. _Grokking algorithms: an illustrated guide for programmers and other curious people_. 2016.
  - CORMEN et all. _Introduction to Algorithms_. 4th edition. 2022.
  - FEOFILOFF, Paulo. [Algoritmos em C](https://www.ime.usp.br/~pf/algoritmos-livro/downloads/Algoritmos-em-linguagem-C.pdf). 2009.
- Algorithm efficiency and visualization:
  - [Paula Hemsi's push_swap operations visualizer](https://phemsi-a.itch.io/push-swap) by [phemsi-a](https://github.com/paulahemsi).
  - [About sorting algorithms efficiency](https://lamfo-unb.github.io/2019/04/21/Sorting-algorithms/) Leonardo Galler and Matteo Kimura
- Tutorials by other 42's students:
  - [Sort visualizer](https://www.sortvisualizer.com/oddevensort/)
  - [Tutorial for push_swap](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e) by [LeoFu](https://github.com/LeoFu9487/).
  - [How to implement radix sort](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) by Jamie Dawson.
  - [VBrazhnik's algorithm solution](https://github.com/VBrazhnik/Push_swap/wiki/Algorithm) by [VBrazhnik](https://github.com/VBrazhnik/).
  - [Mcombeau's algorithm solution](https://github.com/mcombeau/push_swap) by [Mia Combeau](https://github.com/mcombeau).

