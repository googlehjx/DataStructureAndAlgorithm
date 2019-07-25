#ifndef _顺序队列_H
#define _顺序队列_H

//使用模板类
#include <iostream>


template <class T>
class Queue
{
public:
	Queue(int QueueCapacity = 10);
	~Queue();
	bool IsEmpty() const;
	T& Front() const;
	T& Rear() const;
	void Push(const T& item);
	void Pop();
private :
	T* queue;
	int front; //队首的位置
	int rear; // 队尾的位置
	int capacity;
};

template <class T>
inline bool Queue<T>::IsEmpty() const
{
	return front == rear;
}

template <class T>
void Queue<T>::Push(const T& item)
{
	/*if (rear == capacity - 1)
		rear = 0;
	else
	{
		rear++;
	}*/
	if ((rear + 1) % capacity == front) {
		//队列已满,加倍
		T* newQueue = new T[2 * capacity];
		int start = (front + 1) % capacity;
		if (start < 2) // 没有回转 no wrap
		{
			std::copy(queue + start, queue + start + capacity - 1, newQueue);
		}
		else
		{
			std::copy(queue + start, queue + capacity, newQueue);
			std::copy(queue, queue + rear + 1, newQueue + capacity - start);
		}
		front = 2 * capacity - 1;
		rear = capacity - 2;
		capacity *= 2;
		delete[] queue;
		queue = newQueue;

	}
	rear = (rear + 1) % capacity;
	
	queue[rear] = item;
}

template <class T>
void Queue<T>::Pop()
{
	if (IsEmpty()) throw "Queue is empyt. No element to pop";
	front = (front + 1) % capacity;
	queue[front].~T();
}
template <class T>
inline T& Queue<T>::Front() const
{
	if (IsEmpty()) throw "Queue is empty. No front element";
	return queue[(front+1) % capacity];
}

template <class T>
inline T& Queue<T>::Rear() const
{
	if (IsEmpty()) throw "Queue is empty. No rear element";
	return queue[rear];
}

template <class T>
Queue<T>::Queue(int queueCapacity) :capacity(queueCapacity)
{
	if (capacity < 1) throw "Queue capacity must be >1";
	queue = new T[capacity];
	front = rear = 0;
}

template <class T>
Queue<T>::~Queue() {
	delete[] queue;
}

#endif