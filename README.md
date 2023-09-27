# C - Stacks, Queues - LIFO, FIFO (Monty Interpreter

<p align="center">
  <img src="monty_image.png" alt="Project Logo">
</p>

# Table of Contents

1. [Table of Contents](#table-of-contents)
2. [Introduction](#introduction)
3. [Project Overview](#project-overview)
4. [Project Background](#project-background)
5. [Prerequisites](#prerequisites)
6. [How to Run the Code](#how-to-run-the-code)
7. [Main Operations](#main-operations)
8. [Brainf\*ck](#brainfuck)
9. [Authors](#authors)

## Introduction

The Monty ByteCode Interpreter is a project aimed at creating an interpreter for Monty ByteCodes files. Monty 0.98 is a scripting language that is first compiled into Monty byte codes, similar to Python. It relies on a unique stack with specific instructions to manipulate it. This project focuses on implementing these instructions in C, allowing users to execute Monty scripts.

## Project Overview

This project involves implementing a series of tasks related to stack and queue operations in the Monty scripting language. Each task corresponds to a specific opcode that needs to be implemented. These opcodes include push, pall, pint, pop, swap, add, nop, sub, div, mul, mod, comments, pchar, pstr, rotl, rotr, stack, and queue.

## Project Background

This project is part of the group projects assigned during the ALX Software Engineering program.

## Prerequisites

To use the Monty ByteCode Interpreter, you will need:

- A C compiler (gcc recommended)
- Ubuntu 20.04 LTS or a compatible environment
- Basic knowledge of the Monty scripting language and its opcodes

## How to Run the Code

1. Clone the Monty ByteCode Interpreter repository:

```bash
git clone https://github.com/m-aishah/monty.git
```

2. Navigate to the project directory:

```bash
cd monty
```

3. Compile the code using the provided compilation command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```

4. Execute Monty scripts by running the `monty` program with the path to your Monty ByteCode file as an argument (You can use the scripts in the ./bytecodes directory):

```bash
./monty your_script.m
```

## Main Operations (Opcodes)

- **push, pall**: Pushes elements onto the stack and prints stack values.
- **pint**: Prints the value at the top of the stack.
- **pop**: Removes the top element of the stack.
- **swap**: Swaps the top two elements of the stack.
- **add**: Adds the top two elements of the stack.
- **nop**: Does nothing.
- **sub**: Subtracts the top element from the second top element of the stack.
- **div**: Divides the second top element by the top element of the stack.
- **mul**: Multiplies the second top element by the top element of the stack.
- **mod**: Computes the remainder of division between the second top element and the top element of the stack.
- **comments**: Treats lines starting with # as comments.
- **pchar**: Prints the character at the top of the stack.
- **pstr**: Prints the string starting at the top of the stack.
- **rotl**: Rotates the stack to the top.
- **rotr**: Rotates the stack to the bottom.
- **stack, queue**: Sets the format of the data to either stack (LIFO) or queue (FIFO).

## Brainf\*ck

The project includes a Brainf\*ck script that prints "School" followed by a new line.

## Authors

- **Aishah Ayomide Mabayoje**
- Email: maishah2540@gmail.com
- **Ezejanu Dike**
- Email: Ezejanu_nno@ymail.com

Feel free to reach out to the authors with any questions or feedback regarding this project.

---
