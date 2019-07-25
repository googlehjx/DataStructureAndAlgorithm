#ifndef _����_H
#define _����_H

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
	ListNode(T);  //˽�й��캯������Ա List����
	ListNode(){}
};


template <class T>
class List
{
	friend class ListIterator<T>;
public:
	List() { first = new ListNode<T>; first->link = first; }// first�Ǳ�ͷ��û�����ݣ�linkָ���Լ�
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
	T* First(); //��������ĵ�һ���ڵ��ָ��
	T* Next(); //���ص�ǰ�ڵ����һ���ڵ��ָ��
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
	if (current == lst.first) current = current->link; //�������first�ձ�ͷ���������ƶ�һ��
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
	newnode->link = first->link; //��ǰ����룬����ԭ����first->A������B�󣬱��first->B -> A;
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
		; //��ѭ��
	}
	if (current != first)
	{   // �ҵ�Ҫ��ɾ���Ľڵ�
		
		previous->link = current->link;	
		delete current;
	}
	std::cout << "No such element." << std::endl;

}


#endif