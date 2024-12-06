// BST.h
#ifndef BST_H
#define BST_H
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bt.h"
typedef BT* BST;
BST new_BST(int val);
BST bst_add(BST T, int v);
BST bst_rem(BST T, int val); // do
int height(BST T);
int size(BST T); 
bool is_member(BST T, int val); 
void preorder(BST node, int* a);
void inorder(BST node, int* a); 
void postorder(BST node, int* a); 
void bfs(BST T, int* a, int max); 
BST find_min(BST T);
BST find_max(BST T);
#endif
