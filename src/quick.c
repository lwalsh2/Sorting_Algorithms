/*
 * Quick Sort: Partitions through Hoare method.
 * https://en.wikipedia.org/wiki/Quicksort#Hoare_partition_scheme
 * By: Liam P. Walsh
*/

#include <quick.h>

// Prints the list.
void print_list(int list[], int start, int end) {
	printf("Printing list: ");
	if (!list) {
		printf("No list\n");
		return;
	}
  for (int i = start; i < end+1; ++i ) {
    printf("%d ", list[i]);
  }
  printf("\n");
}

// Partitions and swaps through the Hoare method
int hoare_partition(int list[], int start, int end) {
	printf(" Partition: %d - %d\n", start, end);
	int temp = 0;
	int right_bound = start-1;
	int left_bound = end+1;
	while (1) {
		while (right_bound < end && list[++right_bound] < list[start]) {}
		while (left_bound > start && list[--left_bound] > list[start]) {}
	  if (right_bound < left_bound) {
	    temp = list[right_bound];
	    list[right_bound] = list[left_bound];
	    list[left_bound] = temp;
	  }
		else {
			return left_bound;
		}
	}
}

// Quick Sort - Hoare Partition
int sort_list(int list[], int start, int end) {
  // Verify there's a list
	if (!list) {
		return 0;
	}
	if (start < end) {
		// declare/define partition/seperator, and split list
		int part = hoare_partition(list, start, end);
		sort_list(list, start, part);
		sort_list(list, part+1, end);
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
