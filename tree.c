/*
 * Tree Sort Operations
 * By: Liam P. Walsh
 * Tree uses AVL method (Balances after append and remove)
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define size 10

// Declares tree node struct.
typedef struct tree_node_ {
  // Data of tree node
  int number;
  // Pointers to nodes
  struct tree_node_ * right;
	struct tree_node_ * left;
  struct tree_node_ * parent;
} tree_node;

// Declares tree struct. (hold root)
typedef struct tree_ {
  // The root node of the tree
  tree_node * root;
} tree;

// Allocates node with the given data, and returns address.
tree_node * create_node(int number) {
	// Allocate data for node, setting values to NULL/0.
	tree_node * node = calloc(1, sizeof(tree_node));
	// Set the node's data
	node->number = number;
	return node;
}

// Allocates tree with the given root, and returns address.
tree * create_list() {
	// Allocate list.
	tree * tree_struct = calloc(1, sizeof(tree));
	return tree_struct;
}

// Recursively frees nodes called by the node pointer.
void free_node(tree_node * node, tree * list) {
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
int empty_list(tree * list) {
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
int count_level(tree_node * root) {
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


// Swap/Rotate nodes
tree_node * swap_node(tree_node * root, int left) {
  // Makes sure there is a list and node.
  tree_node * tmp = root;
  if (root && left) {
    if (root->left->right)
    {
      root->left = swap_node(root->left, 0);
    }
    tmp = root->left;
    tmp->parent = root->parent;
    root->parent = tmp;
    root->left = tmp->right;
    tmp->right = root;
  }
  else if (root && !left) {
    if (root->right->left)
    {
      root->right = swap_node(root->right, 1);
    }
    tmp = root->right;
    tmp->parent = root->parent;
    root->parent = tmp;
    root->right = tmp->left;
    tmp->left = root;
  }
  return tmp;
}

// Recursively balances nodes by checking the node's left and right levels.
void balance_sub_tree(tree_node * parent, tree_node * node, int left_node) {
  // Makes sure there is a list and node to append.
	if (!node || !parent) {
		return;
	}
	// Checks balance of tree, and swaps if needed.
  int left = 0;
  int right = 0;
  balance_sub_tree(node, node->left, 1);
  balance_sub_tree(node, node->right, 0);
  left = count_level(node->left);
  right = count_level(node->right);
  while (left+1 < right || right+1 < left) {
    if (left+1 < right) {
      node = swap_node(node, 0);
    }
    else {
      node = swap_node(node, 1);
    }
    if (left_node) {
      parent->left = node;
    }
    else {
      parent->right = node;
    }
    left = count_level(node->left);
    right = count_level(node->right);
  }
}

// Balances tree by calling balance_sub_tree, and swap_node.
void balance_tree(tree * list) {
  // Makes sure there is a list and node to append.
	if (!list || !list->root) {
		return;
	}
	// Checks balance of tree, and swaps if needed.
  int left = 0;
  int right = 0;
  balance_sub_tree(list->root, list->root->left, 1);
  balance_sub_tree(list->root, list->root->right, 0);
  left = count_level(list->root->left);
  right = count_level(list->root->right);
  while (left+1 < right || right+1 < left) {
    if (left+1 < right) {
      list->root = swap_node(list->root, 0);
    }
    else {
      list->root = swap_node(list->root, 1);
    }
    left = count_level(list->root->left);
    right = count_level(list->root->right);
  }
}

// Append node to front of list. (Replaces head node)
int append_node(tree_node * new, tree * list) {
  // Makes sure there is a list and node to append.
	if (!list || !new) {
		return 0;
	}
	// If the list is empty, sets the node as root.
	if (!list->root) {
		list->root = new;
	}
	// Finds the end of the list, and appends to the end.
	else {
    tree_node * iter = list->root;
    int left = 1;
    while (iter) {
      if (new->number <= iter->number) {
				new->parent = iter;
        iter = iter->left;
        left = 1;
      }
      else {
				new->parent = iter;
        iter = iter->right;
        left = 0;
      }
    }
    iter = new->parent;
    if (left) {
      iter->left = new;
    }
    else {
      iter->right = new;
    }
	}
  balance_tree(list);
	return 1;
}

// Parses list and prints node data.
int sub_tree_fill(tree_node * node, int tree_array[], int i) {
	if (!node) {
		return 0;
	}
  if (node->left) {
    i = sub_tree_fill(node->left, tree_array, i);
  }
  tree_array[i++] = node->number;
  if (node->right) {
    i = sub_tree_fill(node->right, tree_array, i);
  }
  return i;
}

// Heap Sort - Max Heap notation
void sort_list(int tree_array[], tree * tree_list) {
  // Verify there's a list
	if (!tree_list || !tree_array) {
		return;
	}
  sub_tree_fill(tree_list->root, tree_array, 0);
}

// Fills list with random numbers.
int fill_lists(int list[], tree * tree_list) {
  srand(time(0));
	// Verify there's a list
	if (!list) {
		return 0;
	}
	for (int i = 0; i < size; ++i ) {
    list[i] = rand()%100;
    append_node(create_node(list[i]), tree_list);
  }

	return 1;
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
