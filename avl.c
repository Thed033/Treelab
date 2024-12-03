//=============================================================================
// avl.c - AVL-tree based on binary search tree (bst.h/bst.c)
//=============================================================================
#include "avl.h"
#define DEBUG 0
//=============================================================================
// local prototypes
//-----------------------------------------------------------------------------
static AVL srr(AVL T);
static AVL slr(AVL T);
static AVL drr(AVL T);
static AVL dlr(AVL T);
//=============================================================================
// Public functions, exported via .h-file
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// avl_add: adds the value val to AVL T in a balanced fashion
//-----------------------------------------------------------------------------
AVL avl_add(AVL T, int val)
{
	if(DEBUG)printf("avl_add (%d)\n",val);
	// TODO
	return T;
}
//-----------------------------------------------------------------------------
// avl_rem: removes the value val from AVL T in a balanced fashion
//-----------------------------------------------------------------------------
AVL avl_rem(AVL T, int val)
{
	if(DEBUG)printf("avl_rem (%d)\n",val);
	// TODO
	return T;
}
//-----------------------------------------------------------------------------
// balance: balances the AVL tree T if needed
//-----------------------------------------------------------------------------
AVL balance(AVL T)
{
	// TODO
	return srr(slr(drr(dlr(T))));
}
//=============================================================================
// Private functions, for local use only
//-----------------------------------------------------------------------------
static AVL srr(AVL T)
{
	if(DEBUG)printf("srr\n");
	// TODO
	return T;
}
static AVL slr(AVL T)
{
	if(DEBUG)printf("slr\n");
	// TODO
	return T;
}
static AVL drr(AVL T)
{
	if(DEBUG)printf("drr\n");
	// TODO
	return T;
}
static AVL dlr(AVL T)
{
	if(DEBUG)printf("drr\n");
	// TODO
	return T;
}
