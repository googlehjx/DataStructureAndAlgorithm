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
���ݽ��ͣ�
data��������ڵ�ֵ
height������Ǽ���ĸ߶�
Left�������
Right���Ҷ���
���һ���ǹ��캯��
*/


template <class T>
class AVLTree {
private:
	//���ڵ�
	AVLTreeNode<T>* Root;
public:
	AVLTree() :Root(NULL) {}//���캯��

	void add(T data);//��ӽڵ���ⲿ�ӿ�
	int height();//��ѯ�߶ȵ��ⲿ�ӿ�
	int max(int a, int b);//�Ƚ��������ݵĴ�С
private:
	AVLTreeNode<T>* add(AVLTreeNode<T>*& tree, T data);//��ӽڵ���ڲ��ӿ�
	int height(AVLTreeNode<T>* tree);//��ѯ�߶ȵ��ڲ��ӿ�
	AVLTreeNode<T>* LL_Rotation(AVLTreeNode<T>* k2);//������ת�ľ���ʵ��
	AVLTreeNode<T>* RR_Rotation(AVLTreeNode<T>* k1);//������ת�ľ���ʵ��
	AVLTreeNode<T>* LR_Rotation(AVLTreeNode<T>* k3);//������ת�ľ���ʵ��
	AVLTreeNode<T>* RL_Rotation(AVLTreeNode<T>* k1);//������ת�ľ���ʵ��

};

/*
�߶�
���ã���ȡ���ĸ߶�
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

/* ģ�������Ƚ�����ֵ�Ĵ�С*/
template <class T>
int AVLTree<T>::max(int a, int b) {
	return a > b ? a : b;
}

/*
LL
��������ת�У�һ���漰�������ڵ㣬���ǰ�үү�ڵ�����ΪK2��K2�����������ΪK1��
������ֵ�ԭ����K1�������������һ���ڵ㵼��ƽ����ʧ��
���˼·��
	��K1��Ϊүү�ڵ㣬K2��ΪK1���Ҷ��ӣ����ҽ�K1���Ҷ��ӽ�ΪK2������ӣ�Ȼ�󷵻�үү�ڵ�K1ȡ��ԭ��K2��λ��
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
��������ת�У�һ���漰�������ڵ㣬���ǰ�үү�ڵ�����ΪK1��K1���Ҷ�������ΪK2��
������ֵ�ԭ����K2���Ҷ���������һ���ڵ㵼��ƽ����ʧ��
���˼·��
	��K2��Ϊүү�ڵ㣬K1��ΪK2������ӣ����ҽ�K2������ӽ�ΪK1���Ҷ��ӣ�Ȼ�󷵻�үү�ڵ�K2ȡ��ԭ��K1��λ��
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
��������ת�У�һ���漰���Ĵ��ڵ㣬���ǰ��������Ľڵ��ΪK3����үү�ڵ㣩��K3������ӳ�ΪK1��үү�ڵ㣩��K1���Ҷ��ӳ�ΪK2
������ֵ�ԭ��ʱK2���Ҷ���������һ���ڵ�֮��������ʧ��
���˼·��
	��Ϊ�漰���Ĵ��ڵ㣬������Ҫ������ת��
	���ȶ�K1��K2����һ��������ת =�� K2��Ϊүү�ڵ㣨��K3������ӣ���k2ԭ��������ӳ�ΪK1���Ҷ��ӣ�K1��ΪK2�������
	��������K2��K3����һ��������ת =��K2��Ϊ��үү�ڵ㣬K2ԭ�����Ҷ��ӳ�ΪK3������ӣ�K3��ΪK2���Ҷ���
*/
template <class T>
AVLTreeNode<T>* AVLTree<T>::LR_Rotation(AVLTreeNode<T>* k3) {
	k3->Left = RR_Rotation(k3->Left);

	return LL_Rotation(k3);
}

/*
RL
��������ת�У�һ���漰���Ĵ��ڵ㣬���ǰ��������Ľڵ��ΪK1����үү�ڵ㣩��K1���Ҷ��ӳ�ΪK3��үү�ڵ㣩��K3������ӳ�ΪK2
������ֵ�ԭ��ʱK2�������������һ���ڵ�֮��������ʧ��
���˼·��
	��Ϊ�漰���Ĵ��ڵ㣬������Ҫ������ת��
	���ȶ�K2��K3����һ��������ת =�� K2��Ϊүү�ڵ㣨��K1���Ҷ��ӣ���k2ԭ�����Ҷ��ӳ�ΪK3������ӣ�K3��ΪK2���Ҷ���
	��������K1��K2����һ��������ת =��K2��Ϊ��үү�ڵ㣬K2ԭ��������ӳ�ΪK1���Ҷ��ӣ�K1��ΪK2�������
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
		//���¼���Ľڵ���������� 
		tree->Left = add(tree->Left, data);
		//�������µĽ��֮�����Ƿ�ʧȥƽ�� 
		if (height(tree->Left) - height(tree->Right) == 2)
		{
			if (data < tree->Left->data)
				tree = LL_Rotation(tree);//�����¼���֮������ӵ����������  
			else
				tree = LR_Rotation(tree);//���ң��¼���֮������ӵ��Ҷ�������
		}
	}
	//���¼���Ľڵ���������� 
	else if (data > tree->data) {
		tree->Right = add(tree->Right, data);
		//�������µĽ��֮�����Ƿ�ʧȥƽ�� 
		if (height(tree->Right) - height(tree->Left) == 2)
		{
			if (data > tree->Right->data)
				tree = RR_Rotation(tree);//���ң��¼���֮���Ҷ��ӵ��Ҷ�������  
			else
				tree = RL_Rotation(tree);//�����¼���֮���Ҷ��ӵ����������  
		}
	}
	else //�ýڵ��Ѿ������� 
	{
		std::cout << "�ýڵ��Ѿ���������" << std::endl;
	}
	//���¸�ǰ��ǰ�ڵ�ĸ߶� 
	tree->height = max(height(tree->Left), height(tree->Right)) + 1;

	return tree;
}

template <class T>
void AVLTree<T>::add(T data) {
	add(Root, data);
}




#endif // ! _AVL_H
