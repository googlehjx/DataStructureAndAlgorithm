#include <iostream>


using namespace std;
void BubbleSort(int arr[], int n);
int main()
{
	int a[] = { 2, 4, 6, 1, 3, 9, 5 };
	cout << "����ǰ��" << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	BubbleSort(a, 7);
	cout << "�����" << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

}

void BubbleSort(int arr[], int n)
{
	// n������Ԫ�ظ���
	// ����ѭ������һ����ѭ������Ϊn-1���ڶ���Ϊÿһ��ѭ���Ƚϴ���
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}