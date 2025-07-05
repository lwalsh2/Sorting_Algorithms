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
