#include <iostream>

using namespace std;
template <class T> void myswap(T& x, T& y);
void swap(int* px, int* py);

int main()
{


	int a = 1;
	int b = 10;

	cout << "交换前：" << endl;
	cout << "a = " << a << " , b = " << b << endl;
	int tmp;


	myswap(a, b);
	cout << "交换后：" << endl;

	cout << "a = " << a << " , b = " << b << endl;

}

template <class T>
void myswap(T& x, T& y)
{
	T tmp;
	tmp = x;
	x = y;
	y = tmp;
}

void swap(int* px, int* py)
{
	int tmp;
	tmp = *px;
	*px = *py;
	*py = tmp;
}