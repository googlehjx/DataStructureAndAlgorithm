#include <iostream>
#include "binaryTree.h"

using namespace std;

int main()
{
	BinaryTree<char> tree;

	TreeNode<char> add, sub, multi, devid, a, b, c, d, e;
	add.data = '+';
	sub.data = '-';
	multi.data = '*';
	devid.data = '/';
	a.data = 'A';
	b.data = 'B';
	c.data = 'C';
	d.data = 'D';
	e.data = 'E';

	tree.root = &add;
	add.leftchild = &sub;
	add.rightchild = &e;
	sub.leftchild = &multi;
	sub.rightchild = &d;
	multi.leftchild = &devid;
	multi.rightchild = &c;
	devid.leftchild = &a;
	devid.rightchild = &b;

	cout << "中序遍历：" << endl;
	tree.InOrder();
	cout << endl;

	cout << "前序遍历：" << endl;
	tree.PreOrder();
	cout << endl;
	cout << "后序遍历：" << endl;
	tree.PostOrder();
	cout << endl;

	cout << "层序遍历：" << endl;
	tree.LevelOrder();
	cout << endl;

	BinaryTree<int> bt;
	TreeNode<int> ai;
	ai.data = 3;
	bt.root = &ai;
	bt.InOrder();
	bt.PostOrder();
	bt.PreOrder();
	bt.LevelOrder();
	return 0;
}