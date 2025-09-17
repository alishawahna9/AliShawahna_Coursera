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
 * @file stats.h
 * @brief Declarations for basic statistics utilities on byte arrays.
 *
 * This header file provides function prototypes for analyzing arrays of 
 * unsigned char data: printing arrays, computing and printing statistics, 
 * and sorting arrays in descending order. 
 *
 * Author: Ali Shawahna
 * Date:   2025-09-17
 */

#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Print all elements of an array to stdout.
 *
 * @param arr Pointer to the array (read-only).
 * @param len Number of elements in the array.
 */
void print_array(const unsigned char *arr, unsigned int len);

/**
 * @brief Compute and print statistics (minimum, maximum, mean, median).
 *
 * This function computes the statistics using helper functions 
 * and prints them in a formatted manner.
 *
 * @param arr Pointer to the array (read-only).
 * @param len Number of elements in the array.
 */
void print_statistics(const unsigned char *arr, unsigned int len);

/**
 * @brief Find the median value of an array.
 *
 * Sorts the input array in descending order and returns the middle element 
 * (or average of the two middle elements for even length).
 * NOTE: This function modifies the input array.
 *
 * @param arr Pointer to the array (will be modified by sorting).
 * @param len Number of elements in the array.
 * @return Median value (0 if len == 0).
 */
unsigned char find_median(unsigned char *arr, unsigned int len);

/**
 * @brief Compute the mean (average) of an array.
 *
 * The sum of all elements is divided by the number of elements.
 * Integer division truncates toward zero (rounds down).
 *
 * @param arr Pointer to the array (read-only).
 * @param len Number of elements in the array.
 * @return Mean value (0 if len == 0).
 */
unsigned char find_mean(const unsigned char *arr, unsigned int len);

/**
 * @brief Find the maximum element in an array.
 *
 * @param arr Pointer to the array (read-only).
 * @param len Number of elements in the array.
 * @return Maximum value (0 if len == 0).
 */
unsigned char find_maximum(const unsigned char *arr, unsigned int len);

/**
 * @brief Find the minimum element in an array.
 *
 * @param arr Pointer to the array (read-only).
 * @param len Number of elements in the array.
 * @return Minimum value (0 if len == 0).
 */
unsigned char find_minimum(const unsigned char *arr, unsigned int len);

/**
 * @brief Sort an array in descending order (largest to smallest).
 *
 * @param arr Pointer to the array (will be modified in-place).
 * @param len Number of elements in the array.
 */
void sort_array(unsigned char *arr, unsigned int len);

/**
 * @brief Swap the values of two unsigned char variables.
 *
 * @param a Pointer to the first variable.
 * @param b Pointer to the second variable.
 */
void swap(unsigned char *a, unsigned char *b);

#endif /* __STATS_H__ */
