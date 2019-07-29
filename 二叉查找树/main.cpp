#include <iostream> 
#include "BinarySearchTree.h"


using namespace std;
int main()
{
	BST<int> bst;
	Element<int> a, b, c, d, e, f, g, h, i, j, k, l;
	a.key = 5;
	b.key = 3;
	c.key = 11;
	d.key = 3;
	e.key = 15;
	f.key = 2;
	g.key = 8;
	h.key = 22;
	i.key = 20;
	j.key = 9;
	cout << endl << bst.Insert(a);
	cout << endl << bst.Insert(b);
	cout << endl << bst.Insert(c);
	cout << endl << bst.Insert(d);
	cout << endl << bst.Insert(e);
	cout << endl << bst.Insert(f);
	cout << endl << bst.Insert(g);
	cout << endl << bst.Insert(h);
	cout << endl << bst.Insert(i);
	cout << endl << bst.Insert(j);
	bst.display();

	BstNode<int>* p = bst.Search(b);
	cout << p->data.key << endl;
	cout << "µü´ú²éÕÒ£º" << endl;
	p = bst.IterSearch(b);
	cout << p->data.key << endl;

	cout << "¶ş²æ²éÕÒÊ÷²âÊÔ£º" << endl;
	return 0;
}