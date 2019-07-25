#include <iostream>

using namespace std;

template <class T>
void QuickSort(T* a, const int left, const int right)
{
	if (left < right) 
	{
		// ѡ���Ữ��
		int i = left;
		int j = right+1;
		int pivot = a[left]; // ѡȡ���ᣬ ÿ�εݹ��ѵ�һ����Ϊ�Ƚϱ�׼
		                    // ����С������ߣ�������ķ��ұ�
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
	cout << "���������" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}

	cout << endl;
	return 0;
}