#include <iostream>
#include "MyStack.h"

using namespace std;
int main()
{
	MyStack<int> sk(10);
	sk.Push(10);
	cout << sk.Top()<< endl;
	sk.Pop();
	cout << sk.Top() << endl;
	cout << "hello" << endl;
}