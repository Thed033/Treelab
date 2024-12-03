// BT.h
#ifndef BT_H
#define BT_H
typedef struct BT{
	int val;
	struct BT* LC;
	struct BT* RC;
}BT;
BT* new_BT(int val);
BT* set_val(BT* T, int val);
BT* set_LC(BT* T, BT* LC);
BT* set_RC(BT* T, BT* RC);
int get_val(BT* T);
BT* get_LC(BT* T);
BT* get_RC(BT* T);
BT* cons(BT* LC, BT* T, BT* RC);
#endif
