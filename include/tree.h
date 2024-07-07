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
tree_node * create_node(int number);

// Allocates tree with the given root, and returns address.
tree * create_list();

// Recursively frees nodes called by the node pointer.
void free_node(tree_node * node, tree * list);

// Frees nodes and sets head to NULL.
int empty_list(tree * list);

// Counts the furthest level of child nodes.
int count_level(tree_node * root);

// Swap/Rotate nodes
tree_node * swap_node(tree_node * root, int left);

// Recursively balances nodes by checking the node's left and right levels.
void balance_sub_tree(tree_node * parent, tree_node * node, int left_node);

// Balances tree by calling balance_sub_tree, and swap_node.
void balance_tree(tree * list);

// Append node to front of list. (Replaces head node)
int append_node(tree_node * new, tree * list);

// Parses list and prints node data.
int sub_tree_fill(tree_node * node, int tree_array[], int i);

// Heap Sort - Max Heap notation
void sort_list(int tree_array[], tree * tree_list);

// Fills list with random numbers.
int fill_lists(int list[], tree * tree_list);

// Prints the array list.
void print_array(int list[]);
