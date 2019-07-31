#include <iostream>
#include "avl.h"


using namespace std;
int main()
{

	cout << "AVLÊ÷²âÊÔ£º" << endl;

	int num;
	AVLTree<int>* tree = new AVLTree<int>();
	cin >> num;
	for (int i = 0; i < num; i++) {
		int x;
		cin >> x;
		tree->add(x);
	}
	cout << "¸ß¶ÈÎª£º" << tree->height() << endl;
	return 0;
}