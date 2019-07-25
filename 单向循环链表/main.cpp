#include <iostream>
#include "List.h"


using namespace std;
int main()
{

	cout << "单向循环链表测试：" << endl;
	List<int> l;
	l.Insert(1);
	l.Insert(2);
	l.Insert(3);


	ListIterator<int> it(l);
	if (it.NotNull())
	{
		cout << *it.First();
		while (it.NextNotNull())
			cout << " -> " << *it.Next();
		cout << endl;
	}

	cout << *it.Next() << endl;
	cout << *it.Next() << endl;
	cout << *it.Next() << endl;
	cout << *it.Next() << endl;
	cout << *it.Next() << endl;
	cout << *it.Next() << endl;
	cout << *it.Next() << endl;

	return 0;
}