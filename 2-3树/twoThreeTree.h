#pragma once
#ifndef _TWOTHREETREE_H
#define _TWOTHREETREE_H
#include<iostream>
#include<array>
#include<deque>

template <class T>
class Element
{
public:
	T key;
	// 可以添加更多数据
};

template <class T>
class TreeNode {
public:
	TreeNode(Element<T> &itme);
	TreeNode(Element<T>&item, TreeNode*, TreeNode*, TreeNode*);
	void addKey(Element<T> itme);
	bool isLeaves();
	bool isFull();
	Element<T>  Key[3];
	TreeNode<T> *father;
	TreeNode<T> *lSon, *mSon, *rSon, *extra;
	bool isTwo;
	int itemNumber; //1,2,3
	bool hasKey(Element<T> itme);
	TreeNode* getChild(Element<T> itme);
	void sort(Element<T>[], int);

};
template < class T>
void TreeNode<T>::sort(Element<T> a[], int x)
{
	if (x == 2) {
		if (a[0].key > a[1].key) std::swap(a[0], a[1]);
	}
	if (x == 3) {
		if (a[0].key > a[1].key) std::swap(a[0], a[1]);
		if (a[1].key > a[2].key) std::swap(a[1], a[2]);
	}
}
template <class T>
bool TreeNode<T>::isFull()
{
	return itemNumber == 3;
}
template <class T>
bool TreeNode<T>::isLeaves()
{
	return (lSon == nullptr) && (rSon == nullptr) && (mSon == nullptr);
}
template <class T>
TreeNode<T>::TreeNode(Element<T>& itme) {
	itemNumber = 1;
	Key[0] = itme;
	isTwo = true;
	father = lSon = rSon = mSon = extra = nullptr;
}

template <class T>
TreeNode<T>::TreeNode(Element<T>& item, TreeNode* _father, TreeNode* _lSon, TreeNode* _rSon)
{
	itemNumber = 1;
	Key[0] = item;
	isTwo = true;
	father = _father;
	lSon = _lSon;
	rSon = _rSon;
	mSon = extra = nullptr;
}

template <class T>
void TreeNode<T>::addKey(Element<T> item)
{
	if (isTwo)
	{   // 当前节点是2节点 加入新的Key值，无需分裂
		itemNumber++;
		isTwo = false;
		Key[1] = item;
		sort(Key,2);
	}
	else
	{  // 当前节点是3节点, Key[0] < Key[1],排序使得itme是中间值
		itemNumber++;
		Key[2] = item;
		sort(Key,3);
	}
}

template <class T>
class Tree
{
public:
	TreeNode<T>* get(Element<T> item);
	void Insert(Element<T> itme);
	void Insert(TreeNode<T>* node, Element<T> item);
	void addNode(int);
	void isEmpty();
	void spliteNode(TreeNode<T>*);
	void _spliteNode(TreeNode<T>* node, TreeNode<T>* p);
	TreeNode<T>* _newTree(TreeNode<T>*);
	void InOrder();
	void InOrder(TreeNode<T>* current);
private:
	TreeNode<T>* findPlace(TreeNode<T>*, const Element<T>&);
	void display();
	TreeNode<T> *root = nullptr;
};

template <class T>
void Tree<T>::InOrder()
{
	InOrder(root);
}

template <class T>
void Tree<T>::InOrder(TreeNode<T>* current)
{
	if (current != nullptr) {
		if (current->itemNumber == 1) {
			InOrder(current->lSon);
			std::cout << current->Key[0].key << std::endl;			
			InOrder(current->rSon);
		}
		if (current->itemNumber == 2) {
			InOrder(current->lSon);
			std::cout << current->Key[0].key << std::endl;
			InOrder(current->mSon);
			std::cout << current->Key[1].key << std::endl;
			InOrder(current->rSon);			
		}
	}
}
template <class T>
void Tree<T>::Insert(Element<T> item)
{
	TreeNode<T>* pNode;
	if (root == nullptr)
	{
		root = new TreeNode<T>(item);		
		root->father = nullptr;
		return;
	}
	else
	{
		pNode = findPlace(root, item);
		if (pNode == nullptr)
		{
			std::cout << "This item alread exists" << std::endl;			
		}
		else
		{
			// 找到添加的位置，pNode。并添加键值和排序。
			pNode->addKey(item);

			if (pNode->isFull()) {
				// 在3节点上增加一个数据，需要分裂；要添加的数据存在Key数组中，并已排好序
				spliteNode(pNode);

			}
		}
	}
		
	
}
template <class T>
void Tree<T>::spliteNode(TreeNode<T>* node) {
	_spliteNode(node, node->father);
}

template <class T>
TreeNode<T>* Tree<T>::_newTree(TreeNode<T>* p)
{
	TreeNode<T>* newNode2 = new TreeNode<T>(p->Key[1]);
	TreeNode<T>* pLchild = new TreeNode<T>(p->Key[0]);
	pLchild->lSon = p->lSon;
	if(pLchild->lSon!=nullptr)
		pLchild->lSon->father = pLchild;
	pLchild->rSon = p->mSon;
	if(pLchild->rSon!=nullptr)
		pLchild->rSon->father = pLchild;
	TreeNode<T>* pRchild = new TreeNode<T>(p->Key[2]);
	pRchild->lSon = p->rSon;
	if(pRchild->lSon!=nullptr)
		pRchild->lSon->father = pRchild;
	pRchild->rSon = p->extra;
	if(pRchild->rSon!=nullptr)
		pRchild->rSon->father = pRchild;

	newNode2->lSon = pLchild;
	newNode2->rSon = pRchild;
	pLchild->father = newNode2;
	pRchild->father = newNode2;
	return newNode2;
}
template <class T>
void Tree<T>::_spliteNode(TreeNode<T>* node, TreeNode<T>* p)
{
	/*递归把分裂后的子树推上去，node节点为4节点，包括三个key值，分别是Key[0], Key[1], Key[2];
	  p为node的父节点;
	  1，分裂node，以Key[1]为父节点，Key[0] Key[2]分别为左右子节点

	*/	

	if (p == nullptr) {
		root = _newTree(node);
		return;
	}
	if (p->isTwo) {
		// 父节点为2节点，
		TreeNode<T>* newNode = _newTree(node);
		(p->itemNumber)++;
		if (newNode->Key[0].key < p->Key[0].key) {
			p->Key[1] = p->Key[0];
			p->Key[0] = newNode->Key[0];
			p->lSon = newNode->lSon;
			p->lSon->father = p;
			p->mSon = newNode->rSon;
			p->mSon->father = p;
		}
		else
		{
			p->Key[1] = newNode ->Key[0];
			p->mSon = newNode->lSon;
			p->mSon->father = p;
			p->rSon = newNode->rSon;
			p->rSon->father = p;
		}		
		p->isTwo = false;
		delete newNode;
		return;
	}
	if (p->itemNumber == 2) 
	{   //待分裂的子树，其父节点也已满。涉及父节点的父节点。
		TreeNode<T>* newNode = _newTree(node);

		if (newNode->Key[0].key > p->Key[1].key) {
			p->rSon = newNode->lSon;
			p->rSon->father = p;
			p->extra = newNode->rSon;
			p->extra->father = p;
		}
		else if(newNode->Key[0].key < p->Key[0].key)
		{
			p->extra = p->rSon;
			p->rSon = p->mSon;
			p->mSon = newNode->rSon;
			p->mSon->father = p;
			p->lSon = newNode->lSon;
			p->lSon->father = p;
		}
		else
		{
			//中间大小
			p->extra = p->rSon;
			p->rSon = newNode->rSon;
			p->rSon->father = p;
			p->mSon = newNode->lSon;
			p->mSon->father = p;
		}
		p->addKey(newNode->Key[0]);
		delete newNode;
		// 父节点有3个元素，分别从小到大，指针lSon, mSon, rSon, extra分别指向它们对应的区间。
		
		TreeNode<T>* pf = p->father;
		_spliteNode(p, pf);
	}


}

template <class T>
TreeNode<T>* Tree<T>::findPlace(TreeNode<T>* node, const Element<T>& item)
{
	if (node == nullptr) return node;
	if (node->isTwo)
	{
		// 2节点
		if (node->Key[0].key == item.key) 
			return nullptr; // 已经插入，不能重复
		if (item.key < node->Key[0].key) {
			if (node->isLeaves()) return node;
			else return findPlace(node->lSon, item);
		}
		if(item.key > node->Key[0].key){
			if (node->isLeaves()) return node;
			else return findPlace(node->rSon, item);
		}
	}
	else
	{
		// 3节点
		if ((node->Key[0].key == item.key) or (node->Key[1].key == item.key)) return nullptr;
		if (item.key < node->Key[0].key) {
			if (node->isLeaves()) return node;
			else
				return findPlace(node->lSon, item);
		}
		if (item.key < node->Key[1].key) {
			if (node->isLeaves())return node;
			else return findPlace(node->mSon, item);
		}
		if (item.key > node->Key[1].key) {
			if (node->isLeaves()) return node;
			else return findPlace(node->rSon, item);
		}

	}
}



#endif // !_TWOTHREETREE_H
