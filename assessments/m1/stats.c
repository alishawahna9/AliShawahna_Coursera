/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief Implementation of basic statistics utilities on byte arrays.
 *
 * This file implements functions to compute and display statistics 
 * (minimum, maximum, mean, median), sort arrays in descending order, 
 * and print arrays to stdout. A small test array is used in main() 
 * to demonstrate the functionality.
 *
 * Author: Ali Shawahna
 * Date:   2025-09-17
 */

#include <stdio.h>
#include <stdlib.h>
#include "stats.h"

/* ---------- Internal helper (QuickSort in descending order) ---------- */
static void quicksort_desc(unsigned char *arr, int left, int right) {
    if (left >= right) return;

    int i = left, j = right;
    unsigned char pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] > pivot) i++;   // larger values first
        while (arr[j] < pivot) j--;   // smaller values last
        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++; j--;
        }
    }
    if (left < j)  quicksort_desc(arr, left, j);
    if (i < right) quicksort_desc(arr, i, right);
}

/* ---------- Main entry point ---------- */
int main(void) {

  unsigned char test[40] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114,  88,  45,  76, 123,  87,  25,  23,
                              200, 122, 150,  90,  92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  printf("Original array:\n");
  print_array(test, 40);

  printf("\nStatistics:\n");
  print_statistics(test, 40);

  sort_array(test, 40);
  printf("\nSorted array (descending):\n");
  print_array(test, 40);

  return 0;
}

/* ---------- Function Implementations ---------- */

/**
 * @brief Prints all elements of an array separated by spaces.
 */
void print_array(const unsigned char *arr, unsigned int len) {
    for (unsigned int i = 0; i < len; i++) {
        printf("%u ", arr[i]);
    }
    printf("\n");
}

/**
 * @brief Computes and prints min, max, mean, and median of an array.
 *
 * A temporary copy of the array is created to calculate the median,
 * so that the original array remains unchanged.
 */
void print_statistics(const unsigned char *arr, unsigned int len) {
    unsigned char min   = find_minimum(arr, len);
    unsigned char max   = find_maximum(arr, len);
    unsigned char mean  = find_mean(arr, len);

    // Create a temporary copy for median calculation
    unsigned char *tmp = NULL;
    unsigned char median = 0;
    if (len > 0) {
        tmp = (unsigned char*)malloc(len * sizeof(unsigned char));
        if (tmp != NULL) {
            for (unsigned int i = 0; i < len; ++i) tmp[i] = arr[i];
            median = find_median(tmp, len);
            free(tmp);
        }
    }

    printf("Minimum: %u\n", min);
    printf("Maximum: %u\n", max);
    printf("Mean:    %u\n", mean);
    printf("Median:  %u\n", median);
}

/**
 * @brief Finds the median of an array.
 *
 * Sorts the given array in descending order and returns the middle element 
 * (or the average of the two middle elements if the size is even).
 * NOTE: This function modifies the input array.
 */
unsigned char find_median(unsigned char *arr, unsigned int len) {
    if (len == 0) return 0;

    sort_array(arr, len);  // descending order
    if (len & 1u) {
        return arr[len / 2];
    } else {
        unsigned int mid = len / 2;
        return (unsigned char)((arr[mid - 1] + arr[mid]) / 2);
    }
}

/**
 * @brief Computes the mean (average) of an array, truncated down.
 */
unsigned char find_mean(const unsigned char *arr, unsigned int len) {
    if (len == 0) return 0;

    unsigned int sum = 0;
    for (unsigned int i = 0; i < len; i++) {
        sum += arr[i];
    }
    return (unsigned char)(sum / len); // integer division rounds down
}

/**
 * @brief Finds the maximum element in an array.
 */
unsigned char find_maximum(const unsigned char *arr, unsigned int len) {
    if (len == 0) return 0;

    unsigned char max = arr[0];
    for (unsigned int i = 1; i < len; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

/**
 * @brief Finds the minimum element in an array.
 */
unsigned char find_minimum(const unsigned char *arr, unsigned int len) {
    if (len == 0) return 0;

    unsigned char min = arr[0];
    for (unsigned int i = 1; i < len; i++) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}

/**
 * @brief Sorts an array in descending order (largest to smallest).
 */
void sort_array(unsigned char *arr, unsigned int len) {
    if (len < 2) return;
    quicksort_desc(arr, 0, (int)len - 1);
}

/**
 * @brief Swaps the values of two unsigned chars.
 */
void swap(unsigned char *a, unsigned char *b) {
    unsigned char t = *a;
    *a = *b;
    *b = t;
}
