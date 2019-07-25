#ifndef _MYSTACKT_H
#define _MYSTACK_H
#include "MyUtils.h"
template <class T>
class MyStack
{
public:
	MyStack(int stackCapacity = 10);
	~MyStack();
	bool IsEmpty() const;
	T& Top() const;
	void Push(const T& item);
	void Pop();

private:
	T* stack; //指向数组
	int top;  // 栈顶的位置
	int capacity; //栈大小

};
template <class T>
void MyStack<T>::Pop()
{
	if (IsEmpty()) throw "Stack is empty! Cannot delete.";
	// 如果栈里保存的是对象，需要调用析构函数,然后top减一
	stack[top--].~T();
}

template <class T>
T& MyStack<T>::Top() const
{
	if (IsEmpty()) throw "Stack is empty!";
	return stack[top];
}

template <class T>
MyStack<T>::MyStack(int stackCapacity) :capacity(stackCapacity)
{
	if (capacity < 1) throw "Stack capacity must be > 0";
	stack = new T[capacity];
	top = -1;
}

template <class T>
MyStack<T>::~MyStack()
{
	delete[] stack;
}

template <class T>
void MyStack<T>::Push(const T& item)
{
	if (top == capacity - 1) {
		ChangeSize1D(stack, capacity, 2 * capacity);
	}
	stack[++top] = item;
}
template <class T>
inline bool MyStack<T>::IsEmpty() const
{
	return top == -1;
}

#endif
