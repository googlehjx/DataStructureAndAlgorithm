#include <iostream>


using namespace std;
void BubbleSort(int arr[], int n);
int main()
{
	int a[] = { 2, 4, 6, 1, 3, 9, 5 };
	cout << "排序前：" << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	BubbleSort(a, 7);
	cout << "排序后：" << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

}

void BubbleSort(int arr[], int n)
{
	// n是数组元素个数
	// 两层循环，第一层是循环次数为n-1；第二层为每一次循环比较次数
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}