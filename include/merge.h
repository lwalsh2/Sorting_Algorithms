/*
 * Merge Sort
 * By: Liam P. Walsh
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define size 10

// Prints the list.
void print_list(int list[]);

// Merge Sort
int sort_list(int list[], int start, int end);

// Fills list with random numbers.
int fill_list(int list[]);
