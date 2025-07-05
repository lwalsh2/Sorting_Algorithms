/*
 * Heap Sort Operations
 * By: Liam P. Walsh
 * heap uses AVL method (Balances after append and remove)
*/

#include "heap.h"

int main()
{
  printf("Creating Heap:\n");
	heap * heap_list = create_list();
  int heap_array[size] = {0};
  fill_list(heap_array);
  print_array(heap_array);
	for (int i = 0; i < size; ++i) {
    append_node(create_node(heap_array[i]), heap_list);
  }
  print_heap(heap_list);
  sort_list(heap_array, heap_list);
  free(heap_list);
  printf("Sorted Array:\n");
	print_array(heap_array);
  return 0;
}
