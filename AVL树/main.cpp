#include <iostream>
#include "avl.h"


using namespace std;
int main()
{

	cout << "AVL�����ԣ�" << endl;

	int num;
	AVLTree<int>* tree = new AVLTree<int>();
	cin >> num;
	for (int i = 0; i < num; i++) {
		int x;
		cin >> x;
		tree->add(x);
	}
	cout << "�߶�Ϊ��" << tree->height() << endl;
	return 0;
}