#include <iostream>
#include "ListIterator.h"


using namespace std;
int main()
{

	cout << "Á´±íµü´úÆ÷²âÊÔ£º" << endl;
	List<int> l;
	l.Insert(1);
	l.Insert(2);
	l.Insert(3);
	l.Invert();

	ListIterator<int> it(l);
	if (it.NotNull())
	{
		cout << *it.First();
		while (it.NextNotNull())
			cout << " -> " << *it.Next();
		cout << endl;
	}

	return 0;
}