#include <iostream>
#include "List.h"

using namespace std;
int main()
{
	cout << "Á´±í²âÊÔ:" << endl;

	List<int> l;
	l.Insert(1);
	l.Insert(2);
	l.Insert(3);
	l.show();
	l.Delete(4);
	l.Invert();
	l.show();

	List<int> l2;
	l2.Insert(5);
	l2.Insert(6);
	l2.Invert();
	l.Concatenate(l2);
	l.show();
	
	
	return 0;
}