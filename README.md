# Dining Philosophers Problem

The Dining Philosophers Problem is a classic synchronization problem in computer science. In this project, a group of philosophers are seated around a table, each thinking and eating spaghetti. There are as many forks as there are philosophers, with one fork between each pair of philosophers. The goal is to avoid deadlock while allowing each philosopher to eat when they are hungry.

## Table of Contents

- [Installation](#features)
- [How to Run](#how-to-run)
- [Contributing](#usage)


## Features

Implements the Dining Philosophers Problem in C++.
Uses threads and mutexes to control access to forks.
Demonstrates the potential for deadlock and how it can be avoided.

## How to Run

Compile the program using a C++ compiler.
Run the compiled executable.

## Usage

Watch as the philosophers alternate between thinking and eating.
Observe how the program avoids deadlock by ensuring that philosophers always pick up the fork to their right before the fork to their left.
