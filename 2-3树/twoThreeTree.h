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
	// ������Ӹ�������
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
	{   // ��ǰ�ڵ���2�ڵ� �����µ�Keyֵ���������
		itemNumber++;
		isTwo = false;
		Key[1] = item;
		sort(Key,2);
	}
	else
	{  // ��ǰ�ڵ���3�ڵ�, Key[0] < Key[1],����ʹ��itme���м�ֵ
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
			// �ҵ���ӵ�λ�ã�pNode������Ӽ�ֵ������
			pNode->addKey(item);

			if (pNode->isFull()) {
				// ��3�ڵ�������һ�����ݣ���Ҫ���ѣ�Ҫ��ӵ����ݴ���Key�����У������ź���
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
	/*�ݹ�ѷ��Ѻ����������ȥ��node�ڵ�Ϊ4�ڵ㣬��������keyֵ���ֱ���Key[0], Key[1], Key[2];
	  pΪnode�ĸ��ڵ�;
	  1������node����Key[1]Ϊ���ڵ㣬Key[0] Key[2]�ֱ�Ϊ�����ӽڵ�

	*/	

	if (p == nullptr) {
		root = _newTree(node);
		return;
	}
	if (p->isTwo) {
		// ���ڵ�Ϊ2�ڵ㣬
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
	{   //�����ѵ��������丸�ڵ�Ҳ�������漰���ڵ�ĸ��ڵ㡣
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
			//�м��С
			p->extra = p->rSon;
			p->rSon = newNode->rSon;
			p->rSon->father = p;
			p->mSon = newNode->lSon;
			p->mSon->father = p;
		}
		p->addKey(newNode->Key[0]);
		delete newNode;
		// ���ڵ���3��Ԫ�أ��ֱ��С����ָ��lSon, mSon, rSon, extra�ֱ�ָ�����Ƕ�Ӧ�����䡣
		
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
		// 2�ڵ�
		if (node->Key[0].key == item.key) 
			return nullptr; // �Ѿ����룬�����ظ�
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
		// 3�ڵ�
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
