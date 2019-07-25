#include <iostream>
#include "List.h"
#include <list>



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


	cout << "C++标准库中的list链表：" << endl;
	list<char> lc;
	lc.push_back('a');
	lc.push_back('b');
	lc.push_back('c');
	
	list<char>::iterator lcit = lc.begin();

	while (lcit != lc.end())
	{
		cout << *lcit;
		lcit++;
		if (lcit != lc.end())
			cout << " -> ";
		
	}
	cout << endl;
	return 0;
}