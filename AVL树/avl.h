#ifndef  _AVL_H
#define _AVL_H

template <class T>
struct AVLTreeNode {
	T data;
	int height;
	AVLTreeNode* Left;
	AVLTreeNode* Right;

	AVLTreeNode(T v, AVLTreeNode* l, AVLTreeNode* r) :data(v), height(0), Left(l), Right(r) {}
};
/*
数据解释：
data用来储存节点值
height储存的是几点的高度
Left是左儿子
Right是右儿子
最后一项是构造函数
*/


template <class T>
class AVLTree {
private:
	//根节点
	AVLTreeNode<T>* Root;
public:
	AVLTree() :Root(NULL) {}//构造函数

	void add(T data);//添加节点的外部接口
	int height();//查询高度的外部接口
	int max(int a, int b);//比较两个数据的大小
private:
	AVLTreeNode<T>* add(AVLTreeNode<T>*& tree, T data);//添加节点的内部接口
	int height(AVLTreeNode<T>* tree);//查询高度的内部接口
	AVLTreeNode<T>* LL_Rotation(AVLTreeNode<T>* k2);//左左旋转的具体实现
	AVLTreeNode<T>* RR_Rotation(AVLTreeNode<T>* k1);//右右旋转的具体实现
	AVLTreeNode<T>* LR_Rotation(AVLTreeNode<T>* k3);//左右旋转的具体实现
	AVLTreeNode<T>* RL_Rotation(AVLTreeNode<T>* k1);//右左旋转的具体实现

};

/*
高度
作用：获取树的高度
*/
template <class T>
int AVLTree<T>::height(AVLTreeNode<T>* tree)
{
	if (tree != NULL)
		return tree->height;

	return 0;
}

template <class T>
int AVLTree<T>::height() {
	return height(Root);
}

/* 模板类改造比较两个值的大小*/
template <class T>
int AVLTree<T>::max(int a, int b) {
	return a > b ? a : b;
}

/*
LL
在左左旋转中，一共涉及到三代节点，我们把爷爷节点命名为K2，K2的左儿子命名为K1。
问题出现的原因是K1的左儿子增加了一个节点导致平衡树失衡
解决思路：
	让K1成为爷爷节点，K2成为K1的右儿子，并且将K1的右儿子接为K2的左儿子，然后返回爷爷节点K1取代原来K2的位置
*/
template <class T>
AVLTreeNode<T>* AVLTree<T>::LL_Rotation(AVLTreeNode<T>* k2) {
	AVLTreeNode<T>* k1;

	k1 = k2->Left;
	k2->Left = k1->Right;
	k1->Right = k2;

	k2->height = max(height(k2->Left), height(k2->Right)) + 1;
	k1->height = max(height(k1->Left), k2->height) + 1;

	return k1;
}

/*
RR
在右右旋转中，一共涉及到三代节点，我们把爷爷节点命名为K1，K1的右儿子命名为K2。
问题出现的原因是K2的右儿子增加了一个节点导致平衡树失衡
解决思路：
	让K2成为爷爷节点，K1成为K2的左儿子，并且将K2的左儿子接为K1的右儿子，然后返回爷爷节点K2取代原来K1的位置
*/
template <class T>
AVLTreeNode<T>* AVLTree<T>::RR_Rotation(AVLTreeNode<T>* k1) {
	AVLTreeNode<T>* k2;

	k2 = k1->Right;
	k1->Right = k2->Left;
	k2->Left = k1;

	k1->height = max(height(k1->Left), height(k1->Right)) + 1;
	k2->height = max(height(k2->Right), k1->height) + 1;

	return k2;
}

/*
LR
在左右旋转中，一共涉及到四代节点，我们把做根本的节点成为K3（曾爷爷节点），K3的左儿子称为K1（爷爷节点），K1的右儿子称为K2
问题出现的原因时K2的右儿子增加了一个节点之后导致树的失衡
解决思路：
	因为涉及到四代节点，所以需要两次旋转，
	首先对K1，K2进行一次右右旋转 =》 K2成为爷爷节点（即K3的左儿子），k2原本的左儿子称为K1的右儿子，K1成为K2的左儿子
	接下来对K2，K3进行一次左左旋转 =》K2称为曾爷爷节点，K2原本的右儿子成为K3的左儿子，K3成为K2的右儿子
*/
template <class T>
AVLTreeNode<T>* AVLTree<T>::LR_Rotation(AVLTreeNode<T>* k3) {
	k3->Left = RR_Rotation(k3->Left);

	return LL_Rotation(k3);
}

/*
RL
在右左旋转中，一共涉及到四代节点，我们把做根本的节点成为K1（曾爷爷节点），K1的右儿子称为K3（爷爷节点），K3的左儿子称为K2
问题出现的原因时K2的左儿子增加了一个节点之后导致树的失衡
解决思路：
	因为涉及到四代节点，所以需要两次旋转，
	首先对K2，K3进行一次左左旋转 =》 K2成为爷爷节点（即K1的右儿子），k2原本的右儿子称为K3的左儿子，K3成为K2的右儿子
	接下来对K1，K2进行一次右右旋转 =》K2称为曾爷爷节点，K2原本的左儿子成为K1的右儿子，K1成为K2的左儿子
*/
template <class T>
AVLTreeNode<T>* AVLTree<T>::RL_Rotation(AVLTreeNode<T>* k1) {
	k1->Right = LL_Rotation(k1->Right);

	return RR_Rotation(k1);
}

template <class T>
AVLTreeNode<T>* AVLTree<T>::add(AVLTreeNode<T>*& tree, T data) {
	if (tree == NULL) {
		tree = new AVLTreeNode<T>(data, NULL, NULL);
	}
	else if (data < tree->data) {
		//将新加入的节点插入左子树 
		tree->Left = add(tree->Left, data);
		//检查加入新的结点之后树是否失去平衡 
		if (height(tree->Left) - height(tree->Right) == 2)
		{
			if (data < tree->Left->data)
				tree = LL_Rotation(tree);//左左，新加入之后左儿子的左儿子深了  
			else
				tree = LR_Rotation(tree);//左右，新加入之后左儿子的右儿子深了
		}
	}
	//将新加入的节点插入右子树 
	else if (data > tree->data) {
		tree->Right = add(tree->Right, data);
		//检查加入新的结点之后树是否失去平衡 
		if (height(tree->Right) - height(tree->Left) == 2)
		{
			if (data > tree->Right->data)
				tree = RR_Rotation(tree);//右右，新加入之后右儿子的右儿子深了  
			else
				tree = RL_Rotation(tree);//右左，新加入之后右儿子的左儿子深了  
		}
	}
	else //该节点已经在树中 
	{
		std::cout << "该节点已经存在树中" << std::endl;
	}
	//更新更前当前节点的高度 
	tree->height = max(height(tree->Left), height(tree->Right)) + 1;

	return tree;
}

template <class T>
void AVLTree<T>::add(T data) {
	add(Root, data);
}




#endif // ! _AVL_H
