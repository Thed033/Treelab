#include <stdio.h>
#include <stdlib.h>
#include "bt.h"
BT* new_BT(int val)
{
	BT* nu = (BT*)malloc(sizeof(BT));
	nu->val = val;
	nu->LC = NULL;
	nu->RC = NULL;
	return nu;
}
int get_val(BT* T)
{
	return T ? T->val: 0;
}
BT* get_LC(BT* T)
{
	return T ? T->LC : NULL;
}
BT* get_RC(BT* T)
{
	return T ? T->RC : NULL;
}
BT* set_LC(BT* T, BT* LC)
{
	if(!T)return NULL;
	T->LC = LC;
	return T;
}
BT* set_RC(BT* T, BT* RC)
{
	if(!T)return NULL;
	T->RC = RC;
	return T;
}
BT* set_val(BT* T, int val)
{
	if(!T)return NULL;
	T->val = val;
	return T;
}
BT* cons(BT* LC, BT* T, BT* RC)
{
	if(!T)return NULL;
	T = set_LC(T, LC);
	T = set_RC(T, RC);
	return T;
}
