/*
 * Tree Sort Operations
 * By: Liam P. Walsh
 * Tree uses AVL method (Balances after append and remove)
*/

#include "tree.h"

int main()
{
  printf("Unsorted Array:\n");
	tree * tree_list = create_list();
  int tree_array[size] = {0};
  fill_lists(tree_array, tree_list);
  print_array(tree_array);

  sort_list(tree_array, tree_list);

  empty_list(tree_list);
  free(tree_list);
  printf("Sorted Array:\n");
	print_array(tree_array);
  return 0;
}
