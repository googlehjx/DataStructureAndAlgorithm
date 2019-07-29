#ifndef _BinarySearchTree_H
#define _BinarySearchTree_H
#include <iostream>
template <class T>
class Element
{
public:
	T key;
	// 可以添加更多数据
};

template <class T> class BST; //前置声明

template <class T>
class BstNode  //树节点，节点里有数据，数据为Key，叫做键。
{
	friend class BST<T>;
//private:
public: // 测试所用
	Element<T> data;
	BstNode<T>* LeftChild;
	BstNode<T>* RightChild;
	void display(int i);
};

template <class T>
class BST
{
public:
	BST(BstNode<T>* init = 0) {
		root = init;
	}
	bool Insert(const Element<T>& x);
	// Delete
	// InOrder, PreOrder,PostOrder
	BstNode<T>* Search(const Element<T>& x);
	BstNode<T>* Search(BstNode<T>*, const Element<T>&);
	BstNode<T>* IterSearch(const Element<T>&);
	void display() {
		std::cout << std::endl;
		if (root)
			root->display(1);
		else
			std::cout << "这是一颗空树." << std::endl;
	}
private:
	BstNode<T>* root;
};

template <class T>
void BstNode<T>::display(int i)
{
	std::cout << "Position: " << i << ": data.key " << data.key << std::endl;
	if (LeftChild) LeftChild->display(i * 2);
	if (RightChild) RightChild->display(i * 2 + 1);
}

template <class T>
bool BST<T>::Insert(const Element<T>& x)
{
	BstNode<T>* p = root;
	BstNode<T>* q = 0; // q指向p的父节点
	//插入之前需要查找到合适的位置
	while (p)
	{
		q = p; //保存父节点
		if (x.key == p->data.key) return false; //发生重复，插入失败
		if (x.key < p->data.key) p = p->LeftChild;	
		else p = p->RightChild;
	}
	p = new BstNode<T>;
	p->LeftChild = p->RightChild = 0;
	p->data = x;
	if (!root) {
		root = p; 
		q = root;
	}
	else if (x.key < q->data.key) q->LeftChild = p;
	else q->RightChild = p;
	return true;
}

template <class T>
BstNode<T>* BST<T>::Search(const Element<T>& x)
{
	return Search(root, x);
}

template <class T>
BstNode<T>* BST<T>::Search(BstNode<T>* b, const Element<T>& x)
{
	if (!b) return 0;
	if (x.key == b->data.key) return b;
	if (x.key < b->data.key) return Search(b->LeftChild, x);
	else return Search(b->RightChild, x);
}

template <class T>
BstNode<T>* BST<T>::IterSearch(const Element<T>& x)
{
	for (BstNode<T>* t = root; t; )
	{
		if (x.key == t->data.key) return t;
		if (x.key < t->data.key)
			t = t->LeftChild;
		else
			t = t->RightChild;
	}
	return 0;
}
#endif // _BinarySearchTree_H
