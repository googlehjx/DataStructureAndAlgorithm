#include <iostream>
#include "˳�����.h"


using namespace std;
int main()
{
	Queue<char> q(9);
	q.Push('A');
	q.Push('B');
	q.Push('C');
	cout << q.Front() << endl;
	cout << q.Rear() << endl;
	cout << "����pop֮��" << endl;
	q.Pop();
	cout << q.Front() << endl;
	cout << q.Rear() << endl;
	cout << "����˳�����:" << endl;
	return 0;
}