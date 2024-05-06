# Search Algorithms in C

This repository contains implementations of various search algorithms in C.

![search algo banner](./banner.jpg)

## Contents

1. [Linear Search](#linear-search)
2. [Binary Search](#binary-search)
3. [Advanced Binary Search](#advanced-binary-search)
4. [Jump Search](#jump-search)
5. [Interpolation Search](#interpolation-search)
6. [Exponential Search](#exponential-search)

## Linear Search

Linear search is the simplest search algorithm. It works by sequentially checking each element of the list until a match is found or the whole list has been searched.

## Binary Search

Binary search works on sorted arrays. The algorithm compares the key value with the middle element of the array; if they are unequal, the half in which the key cannot be present is eliminated, and the search continues on the remaining half until it succeeds.

## Advanced Binary Search

Advanced binary search is an extension of the binary search algorithm that handles duplicates. In a sorted array with duplicates, the advanced binary search can be used to find the first or last occurrence of a number.

## Jump Search

Jump search is a search algorithm for sorted arrays. The basic idea is to check fewer elements by jumping ahead by fixed steps or skipping some elements instead of searching all elements.

## Interpolation Search

Interpolation search is an improved variant of binary search. This search algorithm works on the probing position of the required value. For this algorithm to work properly, the data collection should be in a sorted form and equally distributed.

## Exponential Search

Exponential search involves two steps:

1. Find range where element is present
2. Do Binary Search in above found range.

## Running the Code

To compile any C file, use the following command:

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 main.c <input_file>.c -o <output_file>.c
```

To run the compiled file, use the following command:

```bash
./output_file
```
