#include"twoThreeTree.h"

void main() {
	Tree<int> TT;
	Element<int> e1, e2, e3, e4, e5, e6,e7;
	e1.key = 1;
	e2.key = 2;
	e3.key = 3;
	e4.key = 4;
	e5.key = 5; 
	e6.key = 6;
	e7.key = 7;
	TT.Insert(e1);
	TT.Insert(e2);
	TT.Insert(e3);
	TT.Insert(e4);
	TT.Insert(e5);
	TT.Insert(e6);
	TT.Insert(e7);
	TT.InOrder();
	

}