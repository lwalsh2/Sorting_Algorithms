/*
 * Bubble Sort: Iterates through list, and makes individual swaps within list.
 * Modified to 1 For loop. Backsteps when swap is made.
 * By: Liam P. Walsh
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define size 10

// Bubble Sort
int sort_list(int list[]);

// Fills list with random numbers.
int fill_list(int list[]);

// Prints the list.
void print_list(int list[]);
