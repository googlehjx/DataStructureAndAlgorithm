#include <iostream>

using namespace std;

void SelectSort(int a[], int n);

int main()
{
	int a[] = { 0, 2, 4, 6, 8, 1, 3, 5, 7, 9 };
	SelectSort(a, 10);
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}

void SelectSort(int a[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int min=i; //每次循环开始假定第一个数为最小，这个数的下标随着循环次数而增加
		           // 因为每循环一次，最左边都交换得到最小值
		for (int j = i+1; j < n; j++)
		{
			if (a[min] > a[j])
			{
				min = j;
			}
		}
		swap(a[min], a[i]);
		
	}
}