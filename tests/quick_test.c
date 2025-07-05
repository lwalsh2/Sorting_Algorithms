/*
 * Quick Sort: Partitions through Hoare method.
 * https://en.wikipedia.org/wiki/Quicksort#Hoare_partition_scheme
 * By: Liam P. Walsh
*/

#include <quick.h>

int main()
{
  printf("Sorting with Quick Sort:\n");
  int list_array[size] = {0};
  if (!fill_list(list_array)) {
    printf("Failed to create list\n");
    return 0;
  }
  print_list(list_array, 0, size-1);
  if (!sort_list(list_array, 0, size-1)) {
    printf("Failed to sort list\n");
    return 0;
  }
  print_list(list_array, 0, size-1);

  return 0;
}
