/*
 * Bubble Sort: Iterates through list, and makes individual swaps within list.
 * Modified to 1 For loop. Backsteps when swap is made.
 * By: Liam P. Walsh
*/

#include "bubble.h"

// Bubble Sort
int sort_list(int list[]) {
  // Verify there's a list
	if (!list) {
		return 0;
	}
  int temp = 0;
  for(int i = 0; i < size-1; ++i) {
    // Swap if current element is greater than the next.
    printf("  Compare: list[%d] (%d), list[%d] (%d)\n", i, list[i], i+1, list[i+1]);
    if (list[i] > list[i+1]) {
      printf("    Swap Made\n");
      temp = list[i];
      list[i] = list[i+1];
      list[i+1] = temp;
      // Backstep if not at first element
      if (i) {
        i -= 2;
      }
    }
  }
  return 1;
}

// Fills list with random numbers.
int fill_list(int list[]) {
  srand(time(0));
	// Verify there's a list
	if (!list) {
		return 0;
	}
	for (int i = 0; i < size; ++i ) {
    list[i] = rand()%100;
  }
	return 1;
}

// Prints the list.
void print_list(int list[]) {
	printf("Printing list: ");
	if (!list) {
		printf("No list\n");
		return;
	}
  for (int i = 0; i < size; ++i ) {
    printf("%d ", list[i]);
  }
  printf("\n");
}
