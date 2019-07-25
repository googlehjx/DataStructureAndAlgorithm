#include <iostream>
#include "顺序队列.h"


using namespace std;
int main()
{
	Queue<char> q(9);
	q.Push('A');
	q.Push('B');
	q.Push('C');
	cout << q.Front() << endl;
	cout << q.Rear() << endl;
	cout << "调用pop之后：" << endl;
	q.Pop();
	cout << q.Front() << endl;
	cout << q.Rear() << endl;
	cout << "测试顺序队列:" << endl;
	return 0;
}