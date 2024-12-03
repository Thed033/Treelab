//=============================================================================
// bst.c - binary search tree, based on binary tree (bt.h/bt.c)
//=============================================================================
#include "global.h"
#include "bst.h"

//-----------------------------------------------------------------------------
// local function prototypes
//-----------------------------------------------------------------------------
static void _preorder(BST T, int* pos, int* a);
static void _inorder(BST T, int* pos, int* a);
static void _postorder(BST T, int* pos, int* a);
static void _bfs(BST T, int* pos, int* a, int max);
static BST _remove(BST T);
static BST get_right(BST T);
static BST get_left(BST T);
static BST _remove_both(BST T);
static BST NULL_right(BST T);
static BST NULL_left(BST T);

static BST find_min(BST T);
static BST find_max(BST T);

//-----------------------------------------------------------------------------
// public functions, exported through bst.h
//-----------------------------------------------------------------------------
// new_BST: creates a new BST
BST new_BST(int val)
{
	return new_BT(val);
}
//-----------------------------------------------------------------------------
// bst_add: adds the value v to the BST T (unless duplicate)
//-----------------------------------------------------------------------------
BST bst_add(BST T, int v)
{


	printf("hej");
	return	!T            	?	new_BST(v)                            :
		v < get_val(T)	?	cons(add(get_LC(T), v), T, get_RC(T)) :
		v > get_val(T)	?	cons(get_LC(T), T, add(get_RC(T), v)) :
		/* duplicate */		T;
}
//-----------------------------------------------------------------------------
// bst_rem: removes the value val from the BST (if it exists)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// preorder: puts the BST T values into array a in preorder
//-----------------------------------------------------------------------------
//   2                    2
//  / \	--> [2,1,3]      / \  --> [2,3]
// 1  3                 *  3
//-----------------------------------------------------------------------------
void preorder(BST T, int* a)
{

	int pos = 0;
	_preorder(T, &pos, a);

}
//-----------------------------------------------------------------------------
// inorder: puts the BST T values into array a in inorder
//-----------------------------------------------------------------------------
//   2                    2
//  / \	--> [1,2,3]      / \  --> [2,3]
// 1  3                 *  3
//-----------------------------------------------------------------------------
void inorder(BST T, int* a)
{
	int pos = 0; 
	_inorder(T, &pos, a);
}
//-----------------------------------------------------------------------------
// postorder: puts the BST T values into array a in postorder
//-----------------------------------------------------------------------------
//   2                    2
//  / \	--> [1,3,2]      / \  --> [3,2]
// 1  3                 *  3
//-----------------------------------------------------------------------------
void postorder(BST T, int* a)
{
	int pos = 0; 
	_postorder(T, &pos, a);
}
//-----------------------------------------------------------------------------
// bfs: puts the BST T values into array a in bfs-order, non-nodes
// are indicated by X, as defined in global.h
//-----------------------------------------------------------------------------
//   2                    2
//  / \	--> [2,1,3]      / \  --> [2,X,3]
// 1  3                 *  3
//-----------------------------------------------------------------------------
void bfs(BST T, int* a, int max) {
	int pos = 1; 
	for (int i = 0; i < max; i++) {
        a[i] = X; // Initialize the array with placeholders
    }
	_bfs(T, &pos, a, max);
}
//-----------------------------------------------------------------------------
// is_member: checks if value val is member of BST T
//-----------------------------------------------------------------------------
bool is_member(BST T, int val)
{
	if (T == NULL) {
    return false;
    }
	if( is_member(get_LC(T), val) == true || is_member(get_RC(T), val) == true ){
		return true;
	}
	if(T->val == val){
		return(true); 
	}
	return false;
}
//-----------------------------------------------------------------------------
// height: returns height of BST T
//-----------------------------------------------------------------------------
int height(BST T)
{
// if tree is emty return 0
	if(T == NULL){
		return 0;
	}
	if (height(get_LC(T)) > height(get_RC(T))){
		return 1 + (height(get_LC(T)));
	}
	else{
		return 1 + (height(get_RC(T)));
	}
	// TODO
	return 0;
}

int size(BST T)
{
	// if tree is emty return 0
	if(T == NULL){
		return 0;
	}
	// recursive call to calculate cirent node + left tree + right tree
	return 1 + size(get_LC(T)) + size(get_RC(T));


}
//-----------------------------------------------------------------------------
// private helper functions, not exported
//-----------------------------------------------------------------------------




static void _preorder(BST T, int* pos, int* a)
{
	if (T)
	{
		a[(*pos)++] = get_val(T);
		_preorder(get_LC(T), pos, a);
		_preorder(get_RC(T), pos, a);
	}
}

static void _inorder(BST T, int* pos, int* a)
{
	if(T == NULL){
		return;
	}
	_inorder(get_LC(T), pos, a);   
		a[(*pos)++] = T->val;
	_inorder(get_RC(T),pos, a); 

}

static void _postorder(BST T, int* pos, int* a)
{

	if(T == NULL){
		return;
	}

	_postorder(get_LC(T), pos, a);
	_postorder(get_RC(T),pos, a);

	a[(*pos)++] = T->val;
}

static void _bfs(BST T, int* pos, int* a, int max)
{


	// array full or node = NULL
	if (*pos >= max || T == NULL) {
        return;
    }

	a[*pos - 1] = T->val; // root position

	int left = 2 * (*pos);    		// left index in (binary) heap
    int right = 2 * (*pos) + 1;		// right index in (binary) heap
	

	if (get_LC(T) != NULL && left <= max) {
        _bfs(get_LC(T), &left, a, max);   // left tree recursive call with left ass pos varible
	}
	
	if (get_RC(T) != NULL && right <= max) {
        _bfs(get_RC(T), &right, a, max);     // right tree recursive call with left ass pos varible
	}

	
		
		



	

}




BST bst_rem(BST T, int val) {
    // Base case: Tree is empty ore value not existing
    if (T == NULL || is_member(T, val) == false) {
        printf("Value not existing\n");
        return T; // Return the tree unchanged
    }
    // Search for the node to remove
    if (val < T->val) {
        T->LC = bst_rem(T->LC, val);
    } else if (val > T->val) {
        T->RC = bst_rem(T->RC, val);
    } else {
        // Node to be removed is found
        T = _remove(T);
    }

    return T;
}

static BST _remove(BST T) {
    if (T == NULL) return NULL;

   	//leaf node
    if (T->LC == NULL && T->RC == NULL) {
        free(T);
        return NULL;
    }

    //only right child
    if (T->LC == NULL) {
        BST temp = T->RC;
        free(T);
        return temp;
    }

    //only left child
    if (T->RC == NULL) {
        BST temp = T->LC;
        free(T);
        return temp;
    }

    // Case 4: Node has two children
    return _remove_both(T);
}

static BST _remove_both(BST T) {
    if (T == NULL) return NULL;

    // Decide based on the size of subtrees
    if (size(get_RC(T)) > size(get_LC(T))) {
        // Right subtree is bigger: Replace with in-order successor
        BST replace  = find_min(get_RC(T)); // Find smallest in right subtree
        T->val = replace->val;            // Copy successor's value to T
        T->RC = bst_rem(T->RC, replace->val); // Remove successor node
    } else {
        // Left subtree is bigger: Replace with in-order predecessor
        BST replace = find_max(get_LC(T)); // Find largest in left subtree
        T->val = replace->val;            // Copy predecessor's value to T
        T->LC = bst_rem(T->LC, replace->val); // Remove predecessor node
    }

    return T;
}

static BST find_min(BST T) {
    while (T->LC != NULL) {
        T = T->LC;
    }
    return T;
}

static BST find_max(BST T) {
    while (T->RC != NULL) {
        T = T->RC;
    }
    return T;
}



