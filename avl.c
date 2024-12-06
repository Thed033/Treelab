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
	if(T==NULL)
		return new_BT(val);
	
	if(get_val(T) < val)
	{
		set_RC(T,avl_add(get_RC(T), val));
	}
	else if(get_val(T) > val)
	{
		set_LC(T,avl_add(get_LC(T), val));
	}
	else
	{
		return T;
	}

	int balanceVal = getBalance(T);

	if(abs(balanceVal) >= 2){
		T = balance(T);
	}

	return T;
}




//-----------------------------------------------------------------------------
// avl_rem: removes the value val from AVL T in a balanced fashion
//-----------------------------------------------------------------------------
AVL avl_rem(AVL T, int val)
{
	if(T==NULL)
		// node not found
		return T;
	
	if(val > get_val(T))
	{
		// traverse right-downward
		set_RC(T, avl_rem(get_RC(T), val));
	}
	else if(val < get_val(T))
	{
		// traverse left-downward
		set_LC(T, avl_rem(get_LC(T), val));
	}
	else
	{
		// node found

		if(get_LC(T) == NULL && get_RC(T) == NULL)
		{
			// node with no child
			free(T);
			return NULL;
		}

		else if(get_LC(T) == NULL || get_RC(T) == NULL)
		{
			// node with one child
			if(get_LC(T) == NULL)
			{
				set_val(T, get_val(get_RC(T)));
				free(get_RC(T));
				set_RC(T, NULL);
			}
			else
			{
				set_val(T, get_val(get_LC(T)));
				free(get_LC(T));
				set_LC(T, NULL);
			}
		}
		
		else
		{
			// node with both children

			if (height(get_RC(T)) > height(get_LC(T))) {
       			// Right subtree is bigger
        		AVL replace  = find_min(get_RC(T)); 				// Find smallest in right subtree
        		set_val(T, get_val(replace));            			// Copy successor's value to T
        		set_RC(T,avl_rem(get_RC(T), get_val(replace)));
    		} 
			else 
			{
        		// Left subtree is bigger
        		AVL replace = find_max(get_LC(T)); 					// Find largest in left subtree
       			set_val(T,get_val(replace));            			// Copy predecessor's value to T
        		set_LC(T,avl_rem(get_LC(T), get_val(replace)));
    		}

		}
		
	}

	int balanceVal = getBalance(T);
	if(abs(balanceVal) > 1){
		// should only execute one time in recursion
		T= balance(T);
	}

	return T;

}




//-----------------------------------------------------------------------------
// balance: balances the AVL tree T if needed
//-----------------------------------------------------------------------------
AVL balance(AVL T)
{
	printf("STARTING BALANCING AT NODE %d!!\n", get_val(T));
	int root_balance = getBalance(T);
	if(abs(root_balance) < 2 || T==NULL)
		return T;

	if(root_balance > 1)
	{	
		// tree is left-heavy

		if(getBalance(get_LC(T)) > 0)
		{
			// child is left-heavy
			printf("SRR!\n");
			T = srr(T);
		}
		else
		{
			// child is right-heavy
			printf("DRR!\n");
			T = drr(T);
		}
		
	}
	else if(root_balance < -1)
	{
		// tree is right-heavy
		
		if(getBalance(get_RC(T)) > 0)
		{
			// child is left-heavy
			printf("DLR!\n");
			T = dlr(T);
		}
		else
		{
			// child is right-heavy
			printf("SLR!\n");
			T = slr(T);
		}

	}
	printf("SHOULD BE BALANCED!!!\n");
	return T;
}




//=============================================================================
// Private functions, for local use only
//----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
// srr: single right rotation
//-----------------------------------------------------------------------------
static AVL srr(AVL T)
{
	AVL temp = get_LC(T);
	set_LC(T, get_RC(temp));
	set_RC(temp, T);
	return temp;
}


//-----------------------------------------------------------------------------
// slr: single left rotation
//-----------------------------------------------------------------------------
static AVL slr(AVL T)
{
	AVL temp = get_RC(T);
	set_RC(T, get_LC(temp));
	set_LC(temp, T);
	return temp;
}


//-----------------------------------------------------------------------------
// drr: double left-right rotation
//-----------------------------------------------------------------------------
static AVL drr(AVL T)
{
	set_LC(T, slr(get_LC(T)));
	return srr(T);
}


//-----------------------------------------------------------------------------
// drr: double right-left rotation
//-----------------------------------------------------------------------------
static AVL dlr(AVL T)
{
	set_RC(T, srr(get_RC(T)));
	return slr(T);
}


//-----------------------------------------------------------------------------
// getBalance: get balance of node
//-----------------------------------------------------------------------------
int getBalance(AVL T){
	//TODO: check edge cases of this badboy
	return (T == NULL) ? 0 : height(get_LC(T)) - height(get_RC(T));
}


