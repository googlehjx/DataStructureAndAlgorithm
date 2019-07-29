#ifndef  binaryTree_H
#define  binaryTree_H
#include <iostream>
#include <queue>
template <class T> class BinaryTree;
template <class T>
class TreeNode
{
public:
	TreeNode<T>()
	{
		leftchild = NULL;
		rightchild = NULL;
	}
	T data;
	TreeNode<T>* leftchild;
	TreeNode<T>* rightchild;
};

template <class T>
class BinaryTree
{

public:
	//二叉树操作
	BinaryTree<T>() {
		root = NULL;
	}
	void InOrder();
	void InOrder(TreeNode<T>* currentNode);
	void PreOrder();
	void PreOrder(TreeNode<T>* currentNode);
	void PostOrder();
	void PostOrder(TreeNode<T>* currentNode);
	void LevelOrder();
	void Visit(TreeNode<T>* currentNode);
public:
	TreeNode<T>* root;
};

template< class T>
void BinaryTree<T>::Visit(TreeNode<T>* currentNode)
{
	std::cout << currentNode->data;
}

template <class T>
void BinaryTree<T>::InOrder()
{
	InOrder(root);
}

template <class T>
void BinaryTree<T>::InOrder(TreeNode<T>* currentNode)
{
	if (currentNode)
	{
		InOrder(currentNode->leftchild);
		//显示当前节点
		Visit(currentNode);
		InOrder(currentNode->rightchild);
	}
}

template <class T>
void BinaryTree<T>::PreOrder()
{
	PreOrder(root);
}

template <class T>
void BinaryTree<T>::PreOrder(TreeNode<T>* currentNode)
{
	if (currentNode)
	{
		Visit(currentNode);
		PreOrder(currentNode->leftchild);
		PreOrder(currentNode->rightchild);
	}
}

template <class T>
void BinaryTree<T>::PostOrder()
{
	PostOrder(root);
}

template <class T>
void BinaryTree<T>::PostOrder(TreeNode<T>* currentNode)
{
	if (currentNode)
	{
		PostOrder(currentNode->leftchild);
		PostOrder(currentNode->rightchild);
		Visit(currentNode);
	}
}

template <class T>
void BinaryTree<T>::LevelOrder()
{
	std::queue<TreeNode<T>*> q;
	TreeNode<T>* currentNode = root;
	//while (currentNode)
	//{
	//	Visit(currentNode);
	//	if (currentNode->leftchild) q.push(currentNode->leftchild);
	//	if (currentNode->rightchild) q.push(currentNode->rightchild);
	//	if (q.empty()) return;
	//	currentNode = q.front();
	//	q.pop();
	//}
	q.push(currentNode);
	while (true)
	{
		if (currentNode) 
			Visit(currentNode);
		else return;
		if (currentNode->leftchild) q.push(currentNode->leftchild);
		if (currentNode->rightchild) q.push(currentNode->rightchild);
		q.pop();
		if (!q.empty()) currentNode = q.front();
		else return;
	}
}

#endif // ! binaryTree_H
