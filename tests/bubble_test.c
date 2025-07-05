/*
 * Bubble Sort: Iterates through list, and makes individual swaps within list.
 * Modified to 1 For loop. Backsteps when swap is made.
 * By: Liam P. Walsh
*/

#include "bubble.h"

int main()
{
  printf("Sorting with Bubble Sort:\n");
  int list_array[size] = {0};
  if (!fill_list(list_array)) {
    printf("Failed to create list\n");
    return 0;
  }
  print_list(list_array);
  if (!sort_list(list_array)) {
    printf("Failed to sort list\n");
    return 0;
  }
  print_list(list_array);

  return 0;
}
