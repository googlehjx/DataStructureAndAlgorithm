#include <iostream>

using namespace std;

template <class T>
void QuickSort(T* a, const int left, const int right)
{
	if (left < right) 
	{
		// 选数轴划分
		int i = left;
		int j = right+1;
		int pivot = a[left]; // 选取数轴， 每次递归已第一个数为比较标准
		                    // 比它小的在左边，比它大的放右边
		do {
			do i++; while (a[i] < pivot);
			do j--; while (a[j] > pivot);
			if (i < j) swap(a[i], a[j]);
		} while (i < j);
		swap(a[left], a[j]);

		QuickSort(a, left, j - 1);
		QuickSort(a, j + 1, right);
	}
}
int main()
{
	int a[] = { 0,2,4,6,8,1,3,5,7,9 };
	QuickSort(a, 0, 9);
	cout << "快速排序后：" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}

	cout << endl;
	return 0;
}