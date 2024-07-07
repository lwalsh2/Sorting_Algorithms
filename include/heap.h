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
heap_node * create_node(int number);

// Allocates heap with the given max, and returns address.
heap * create_list();

// Recursively frees nodes called by the node pointer.
void free_node(heap_node * node, heap * list);

// Frees nodes and sets head to NULL.
int empty_list(heap * list);

// Counts the furthest level of child nodes.
int count_level(heap_node * root);

// Counts the furthest level of child nodes.
int count_full_left(heap_node * root);

// Counts the furthest level of child nodes.
int count_full_right(heap_node * root);

// Swaps as needed until max heap is valid.
void balance_up_heap(heap_node * node, heap * list);

// Swaps as needed until max heap is valid.
void balance_down_heap(heap * list);

// Append node to front of list. (Replaces head node)
int append_node(heap_node * new, heap * list);

// Removes the root, and reorganizes
void remove_head(heap * heap_list);

// Parses list and prints node data.
void print_sub_heap(heap_node * node);

// Parses list and prints node data.
void print_heap(heap * list);

// Prints the array list.
void print_array(int list[]);

// Heap Sort - Max Heap notation
int sort_list(int heap_array[], heap * heap_list);

// Fills list with random numbers.
int fill_list(int list[]);
