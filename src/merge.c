/*
 * Merge Sort
 * By: Liam P. Walsh
*/

#include "merge.h"

int main()
{
  printf("Sorting with Merge Sort:\n");
  int list_array[size] = {0};
  if (!fill_list(list_array)) {
    printf("Failed to create list\n");
    return 0;
  }
	printf("Pre-sort: \n");
	print_list(list_array);
	// Merge sort until no swaps made.
  while(sort_list(list_array, 0, size-1)) {}
	printf("Post-sort: \n");
  print_list(list_array);
  return 0;
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

// Merge Sort
int sort_list(int list[], int start, int end) {
	// Define how many swaps are made.
	int swap_made = 0;
  // Verify there's a list
	if (!list) {
		return 0;
	}
	int tmp = 0;
	if (start < end) {
		int middle = start + (end - start) / 2;
		if (start < middle) {
			swap_made += sort_list(list, start, middle);
			if (list[start] > list[middle]) {
				tmp = list[start];
				list[start] = list[middle];
				list[middle] = tmp;
				++swap_made;
			}
			if (middle < end) {
				swap_made += sort_list(list, middle, end);
				if (list[middle] > list[end]) {
					tmp = list[middle];
					list[middle] = list[end];
					list[end] = tmp;
					++swap_made;
				}
			}
		}
		if (list[start] > list[end]) {
			tmp = list[start];
			list[start] = list[end];
			list[end] = tmp;
			++swap_made;
		}
	}
	return swap_made;
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
