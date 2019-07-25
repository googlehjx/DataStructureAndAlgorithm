#include <iostream>

using namespace std;

template <class T>
void InsertSort(T* a, int n);

int main()
{

	int a[] = { 0,2,4,6,8,1,3,5,7,9 };
	InsertSort(a, 10);
	cout << "�����" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}

template <class T>
void InsertSort(T* a, int n)
{
	int in, out;
	// out=0�ѳ�ȥ��in-1��ʾ���ź���ĸ���
	for (out = 1; out < n; out++)
	{
		T tmp = a[out];
		in = out;
		while (in>0 && a[in-1]>=tmp)
		{
			a[in] = a[in-1];
			--in;
		}
		a[in] = tmp;
	}
}