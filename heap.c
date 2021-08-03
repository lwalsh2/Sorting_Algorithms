/*
 * Heap Sort Operations
 * By: Liam P. Walsh
 * heap uses AVL method (Balances after append and remove)
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define size 10

// Declares heap node struct.
typedef struct heap_node_ {
  // Data of heap node
  int number;
  // Pointers to nodes
  struct heap_node_ * right;
	struct heap_node_ * left;
  struct heap_node_ * parent;
} heap_node;

// Declares heap struct. (hold root)
typedef struct heap_ {
  // The root node of the heap
  heap_node * root;
  heap_node * tail;
} heap;

// Allocates node with the given data, and returns address.
heap_node * create_node(int number) {
	// Allocate data for node, setting values to NULL/0.
	heap_node * node = calloc(1, sizeof(heap_node));
	// Set the node's data
	node->number = number;
	return node;
}

// Allocates heap with the given max, and returns address.
heap * create_list() {
	// Allocate list.
	heap * heap_struct = calloc(1, sizeof(heap));

	return heap_struct;
}

// Recursively frees nodes called by the node pointer.
void free_node(heap_node * node, heap * list) {
	if (!node) {
		return;
	}
	// Recursively calls to the end of the list.
	if (node->left) {
		free_node(node->left, list);
	}
  if (node->right) {
    free_node(node->right, list);
	}
	// Frees nodes, starting from the end of the list.
	free(node);
}

// Frees nodes and sets head to NULL.
int empty_list(heap * list) {
	// Verify there's a list
	if (!list) {
		return 0;
	}
	// Free any nodes attached to the list.
	if (list->root) {
		free_node(list->root, list);
	}
	// Empties list by setting to NULL.
	list->root = NULL;
	return 1;
}

// Counts the furthest level of child nodes.
int count_level(heap_node * root) {
  // Makes sure there is a  node.
	if (!root) {
		return 0;
	}
	// Finds the end of the list, and returns count.
  int cL = count_level(root->left);
  int cR = count_level(root->right);
  if (cL > cR) {
    return cL + 1;
  }
	return cR + 1;
}

// Counts the furthest level of child nodes.
int count_full_left(heap_node * root) {
  // Makes sure there is a  node.
	if (!root) {
		return 0;
	}
	// Finds the end of the list, and returns count.
	return 1 + count_level(root->left);
}

// Counts the furthest level of child nodes.
int count_full_right(heap_node * root) {
  // Makes sure there is a  node.
	if (!root) {
		return 0;
	}
	// Finds the end of the list, and returns count.
  return 1 + count_level(root->right);
}

// Swaps as needed until max heap is valid.
void balance_up_heap(heap_node * node, heap * list) {
  // Makes sure there is a list and node to append.
	if (!node || !list) {
		return;
	}
  int tmp_number = 0;
  while (node->parent != NULL && node->number > node->parent->number) {
    tmp_number = node->number;
    node->number = node->parent->number;
    node->parent->number = tmp_number;
    node = node->parent;
  }
}

// Swaps as needed until max heap is valid.
void balance_down_heap(heap * list) {
  // Makes sure there is a list and node to append.
	if (!list || !list->root) {
		return;
	}
  heap_node * node = list->root;
  int tmp_number = 0;
  // If child is greater, swap data of nodes.
  while (node->left || node->right) {
    if (node->right && node->left) {
      if (node->left > node->right && node->number < node->right->number) {
        tmp_number = node->number;
        node->number = node->right->number;
        node->right->number = tmp_number;
        node = node->right;
      }
      else if (node->number < node->left->number) {
        tmp_number = node->number;
        node->number = node->left->number;
        node->left->number = tmp_number;
        node = node->left;
      }
      else if (node->number < node->right->number) {
        tmp_number = node->number;
        node->number = node->right->number;
        node->right->number = tmp_number;
        node = node->right;
      }
      else {
        break;
      }
    }
    else if (!node->left && node->number < node->right->number) {
      tmp_number = node->number;
      node->number = node->right->number;
      node->right->number = tmp_number;
      node = node->right;
    }
    else if (node->left && node->number < node->left->number) {
      tmp_number = node->number;
      node->number = node->left->number;
      node->left->number = tmp_number;
      node = node->left;
    }
    else {
      break;
    }
  }
}

// Append node to front of list. (Replaces head node)
int append_node(heap_node * new, heap * list) {
  // Makes sure there is a list and node to append.
	if (!list || !new) {
		return 0;
	}
  list->tail = new;
	// If the list is empty, sets the node as root.
	if (!list->root) {
		list->root = new;
	}
	// Finds the end of the list, and appends to the end.
	else {
    heap_node * iter = list->root;
    int parent = 0; // 0 - L, 1 - R
    int cL = 0;
    int cLL = 0;
    int cR = 0;
    int cRL = 0;
    while (iter) {
      cL = count_full_left(iter);
      cLL = count_full_left(iter->left);
      cR = count_full_right(iter);
      cRL = count_full_right(iter->left);
      if (cL <= cR+1 && cLL != cRL) {
				new->parent = iter;
        iter = iter->left;
        parent = 0;
      }
      else if (cL <= cR && cLL == cRL) {
				new->parent = iter;
        iter = iter->left;
        parent = 0;
      }
      else {
				new->parent = iter;
        iter = iter->right;
        parent = 1;
      }
    }
    iter = new->parent;
    if (parent) {
      iter->right = new;
    }
    else {
      iter->left = new;
    }
    balance_up_heap(new, list);
	}
	return 1;
}

// Removes the root, and reorganizes
void remove_head(heap * heap_list) {
  // Makes sure there is a list and a root to remove.
	if (!heap_list || !heap_list->root) {
		return;
	}
  if (heap_list->tail->parent) {
    // Swap root with tail
    int tmp_number = heap_list->root->number;
    heap_list->root->number = heap_list->tail->number;
    heap_list->tail->number = tmp_number;

    // Set new tail, and balance down from the new root data.
    heap_node * new_tail = heap_list->tail->parent;
    if (heap_list->tail->parent->left != heap_list->tail) {
      new_tail = heap_list->tail->parent->left;
      heap_list->tail->parent->right = NULL;
    }
    else if (heap_list->tail->parent->right && heap_list->tail->parent->right != heap_list->tail) {
      new_tail = heap_list->tail->parent->right;
      heap_list->tail->parent->left = NULL;
    }
    else {
      heap_list->tail->parent->left = NULL;
    }
    while (new_tail->left || new_tail->right) {
      if (new_tail->right) {
        new_tail = new_tail->right;
      }
      else {
        new_tail = new_tail->left;
      }
    }
    free(heap_list->tail);
    heap_list->tail = new_tail;
    balance_down_heap(heap_list);
  }
  else {
    empty_list(heap_list);
  }
}

// Parses list and prints node data.
void print_sub_heap(heap_node * node) {
	if (!node) {
		return;
	}
	printf("\n   %d: ", node->number);
  if (node->left) {
    printf("Left: %d ", node->left->number);
  }
  if (node->right) {
    printf("Right: %d ", node->right->number);
  }
  if (node->left) {
    print_sub_heap(node->left);
  }
  if (node->right) {
    print_sub_heap(node->right);
  }
}

// Parses list and prints node data.
void print_heap(heap * list) {
	printf("\nPrinting heap: \n");
	if (!list || !list->root) {
		printf("   No heap, root empty\n");
		return;
	}
	printf("   Root %d ", list->root->number);
	if (list->root->left) {
    printf("Left: %d ", list->root->left->number);
  }
  if (list->root->right) {
    printf("Right: %d ", list->root->right->number);
  }
  if (list->root->left) {
    print_sub_heap(list->root->left);
  }
  if (list->root->right) {
    print_sub_heap(list->root->right);
  }
  printf("\n");
}

// Prints the array list.
void print_array(int list[]) {
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

// Heap Sort - Max Heap notation
int sort_list(int heap_array[], heap * heap_list) {
  // Verify there's a list
	if (!heap_list || !heap_array) {
		return 0;
	}
	for (int i = size-1; i > -1; --i) {
    heap_array[i] = heap_list->root->number;
    print_array(heap_array);
    remove_head(heap_list);
    print_heap(heap_list);
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
