#include <iostream>
#include <list>
#include "List.h"

using namespace std;
int main()
{
	cout << "链表测试:" << endl;

	List<int> l;
	l.Insert(1);
	l.Insert(2);
	l.Insert(3);
	l.Invert();
	l.show();
	


	cout << "STL链表和迭代器：" << endl;

	std::list<int> listi;
	listi.push_front(1);
	listi.push_front(2);
	listi.push_front(4);
	listi.push_front(8);
	listi.push_front(16);

	std::list<int>::iterator it = listi.begin(); //返回一个迭代器指向链表中的第一个数据
	while (it != listi.end())
	{
		cout << *it << " -> ";
		++it;
	}
	cout << endl;

	
	return 0;
}