# 42 Push Swap

Welcome to 42 Push Swap! This project challenges you to sort a stack of integers using two stacks and a set of predefined operations. The goal is to implement an efficient algorithm to sort the stack with the least number of moves.

## Table of Contents

1. [Introduction](#introduction)
2. [Getting Started](#getting-started)
3. [Usage](#usage)
4. [Build Commands](#build-commands)
5. [Algorithm](#algorithm)
6. [Contributing](#contributing)
7. [License](#license)

## Introduction

The `push_swap` project requires you to implement a program that can sort a stack of integers using only a set of predefined operations on two stacks (`stack A` and `stack B`). The objective is to achieve the sorted order in `stack A` using the minimum number of moves.

## Getting Started

To get started with `push_swap`, simply clone this repository to your local machine:

```bash
git clone https://github.com/T-001v2r3/push_swap.git
```
Once you have the repository cloned, navigate to the project directory.
##Usage

To run the program, execute the following command:

```bash
./push_swap [list of integers]
```
For example:

```bash
./push_swap 4 2 9 5 1
```
The program will output a series of instructions to sort the stack.
## Build Commands

Use the following commands to build and clean your project:

```bash
make         # to build
make re      # to re-build the project
make clean   # to clean up object files
make fclean  # to clean up everything
```
## Algorithm

The push_swap project often involves implementing an efficient sorting algorithm. I used radix sort to achieve the minimum number of moves.
## Contributing

Contributions to push_swap are welcome! If you have ideas for improvements, bug fixes, or additional features, feel free to open an issue or submit a pull request.

Before submitting a pull request, please make sure your code follows the 42 Norm coding style.
## License

This project is licensed under the terms of the MIT license.