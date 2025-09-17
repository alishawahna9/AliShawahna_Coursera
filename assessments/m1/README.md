# Statistics Project – Coursera Embedded Systems (Course 1)

**Author:** Ali Shawahna  
**Date:** September 17, 2025  

## Project Description
This project implements basic statistics utilities in C for analyzing arrays 
of unsigned char data. The program computes and reports the **minimum**, 
**maximum**, **mean**, and **median** of a dataset, and reorders the data 
from largest to smallest.  

The implementation includes:
- `stats.c` – Function implementations and test `main()`.
- `stats.h` – Header file with function declarations.
- `README.md` – Project description and author details.

## Features
- Prints original and sorted arrays.
- Computes and prints min, max, mean, and median values.
- Sorting performed in descending order.
- Median calculation works for both odd and even-length arrays.

## Compilation
To compile and run the program on Linux:
```bash
gcc -Wall -Wextra -std=c11 -o stats stats.c
./stats

