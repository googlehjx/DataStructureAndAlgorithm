#ifndef _链表_H
#define _链表_H

template <class T> class List;
template <class T> class ListIterator;
template <class T>
class ListNode
{
	friend class List<T>;
	friend class ListIterator<T>;

private:
	T data;
	ListNode* link;
	ListNode(T);  //私有构造函数，友员 List调用
	ListNode(){}
};


template <class T>
class List
{
	friend class ListIterator<T>;
public:
	List() { first = new ListNode<T>; first->link = first; }// first是表头，没有数据，link指向自己
	void Insert(T);
	void Delete(T);

private:
	ListNode<T>* first;
};

template <class T>
class ListIterator
{
public:
	ListIterator(const List<T>& ls) :lst(ls), current(ls.first->link) {};
	bool NotNull();
	bool NextNotNull();
	T* First(); //返回链表的第一个节点的指针
	T* Next(); //返回当前节点的下一个节点的指针
private:
	const List<T>& lst;
	ListNode<T>* current;
};

template <class T>
bool ListIterator<T>::NotNull()
{
	if (current != lst.first) return true;
	else return false;
}

template <class T>
bool ListIterator<T>::NextNotNull()
{
	if (current->link != lst.first) return true;
	else return false;
}

template <class T>
T* ListIterator<T>::First()
{
	if (current != lst.first) return &current->data;
	else return 0;
}

template <class T>
T* ListIterator<T>::Next()
{
	current = current->link;
	if (current == lst.first) current = current->link; //如果遇到first空表头，再向下移动一次
	return &(current->data);

}
template<class T>
ListNode<T>::ListNode(T item)
{
	data = item;
	link = 0;
}

template <class T>
void List<T>::Insert(T item)
{
	ListNode<T>* newnode = new ListNode<T>(item);
	newnode->link = first->link; //在前面插入，假设原链表first->A，插入B后，变成first->B -> A;
	first->link = newnode;
}

template <class T>
void List<T>::Delete(T item)
{
	ListNode<T>* previous = first;
	ListNode<T>* current ;
	for (current = first->link; (current != first) && current->data != item;
		previous = current, current = current->link)
	{
		; //空循环
	}
	if (current != first)
	{   // 找到要被删除的节点
		
		previous->link = current->link;	
		delete current;
	}
	std::cout << "No such element." << std::endl;

}


#endif