/*
 * Quick Sort: Partitions through Hoare method.
 * https://en.wikipedia.org/wiki/Quicksort#Hoare_partition_scheme
 * By: Liam P. Walsh
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define size 10

// Prints the list.
void print_list(int list[], int start, int end);

// Partitions and swaps through the Hoare method
int hoare_partition(int list[], int start, int end);

// Quick Sort - Hoare Partition
int sort_list(int list[], int start, int end);

// Fills list with random numbers.
int fill_list(int list[]);
