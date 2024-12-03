// avl.h
#ifndef AVL_H
#define AVL_H
#include "bst.h"
typedef BST AVL;
AVL avl_add(AVL T, int val);
AVL avl_rem(AVL T, int val);
AVL balance(AVL T);
#endif
