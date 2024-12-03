// global.h
#ifndef GLOBAL_H
#define GLOBAL_H
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
#include "bst.h"
#define MAX 128			// max size of bfs_order_star
#define X -42			// "non-value" in trees
typedef BST (*tree_func)(BST, int);	// function pointer definition
extern tree_func add;	// "polymorphic" function pointer
extern tree_func rem;	// "polymorphic" function pointer
						// add = bst_add; rem = bst_rem for BST
						// add = avl_add; rem = avl_add for AVL
#endif
