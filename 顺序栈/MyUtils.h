#ifndef _MYUTILS_H
#define _MYUTILS_H
template <class T>
void ChangeSize1D(T* &a, const int oldSize, const int newSize)
{
	// 指针变量本身必须为引用传递，因为在函数内需要修改原stack
	if (newSize < 0) throw "New length must be > 0";
	T* temp = new T[newSize];
	std::copy(a, a + oldSize, temp);
	delete[] a;
	a = temp;
}


#endif