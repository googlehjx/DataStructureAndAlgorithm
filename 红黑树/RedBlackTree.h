#ifndef _REDBLACKTREE_H
#define _REDBLACKTREE_H

template<class T>
class Element
{
	T key;
};

template <class T>
class TreeNode
{
private:
	Element<T> data;
	bool color; // 1表示红， 0表示黑色
	TreeNode<T>* LeftChild;
	TreeNode<T>* RightChild;
};

template <class T>
class RBTree
{
public:
	TreeNode<T>* Search(T item);
	TreeNode<T>* Search(TreeNode<T>*, T);
	TreeNode<T>* findPlace(T item);
	TreeNode<T>* findPlace(TreeNode<T>*, T, TreeNode<T>*);
	void Insert(T item);
private:
	TreeNode<T>* root;
};

template <class T>
TreeNode<T>* RBTree<T>::findPlace(T item)
{
	return findPlace(root, item, nullptr);
}

template <class T>
TreeNode<T>* RBTree<T>::findPlace(TreeNode<T>* current, T item, TreeNode<T>* p)
{
	//当前节点保存 p为父节点
	if (current == nullptr) return p;
	else 
	{
		if (item < current->data.key)
			return findPlace(current->LeftChild, item, current);
		else if (item > current->data.key)
			return findPlace(current->RightChild, item, current);
		else
			return nullptr; //待插入的数据已经存在树中，无法插入
	}
}


template <class T>
TreeNode<T>* RBTree<T>::Search(TreeNode<T>* current, T item)
{
	if (current == nullptr) return nullptr;
	else
	{
		if (item < current->data.key) return Search(current->LeftChild, item);
		else if (item > current->data.key) return Search(current->RightChild, item);
		else return current;
	}
}

template <class T>
TreeNode<T>* RBTree<T>::Search(T item) 
{
	return Search(root, item);
}

#endif // !_REDBLACKTREE_H
