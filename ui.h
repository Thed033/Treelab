// ui.h
#include <stdio.h>
#include "bt.h"
#include "bst.h"
#include "avl.h"
#ifndef UI_H
#define UI_H
#define BUFSIZE 100
void print_tree(BST T);
void print_array(int* a, int size);
void print_2d(int* a, int maxnodes);
void run(char mode, bool echo);
#endif
