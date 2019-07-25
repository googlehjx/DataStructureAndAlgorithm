#ifndef _����_H
#define _����_H

template <class T> class List;
template <class T>
class ListNode
{
	friend class List<T>;

private:
	T data;
	ListNode* link;
	ListNode(T);  //˽�й��캯������Ա List����
};

template<class T>
ListNode<T>::ListNode(T item)
{
	data = item;
	link = 0;
}

template <class T>
class List
{
public:
	List()
	{
		first = 0;
	}
	void Insert(T);
	void Delete(T);
	void Invert();
	void Concatenate(List<T> ls);
	void show();
private:
	ListNode<T>* first;

};

template <class T>
void List<T>::Insert(T item)
{
	ListNode<T>* newnode = new ListNode<T>(item);
	newnode->link = first; //��ǰ����룬����ԭ����first->A������B�󣬱��first->B -> A;
	first = newnode;
}

template <class T>
void List<T>::show()
{
	for (ListNode<T>* current = first; current; current = current->link)
	{
		std::cout << current->data;
		if (current->link) std::cout << " -> ";
	}
	std::cout << std::endl;
}

template <class T>
void List<T>::Delete(T item)
{
	ListNode<T>* previous = 0;
	ListNode<T>* current = 0;
	for (current = first; current && current->data != item;
		previous = current, current = current->link)
	{
		; //��ѭ��
	}
	if (current)
	{   // �ҵ�Ҫ��ɾ���Ľڵ�
		if (previous) { //���ǵ�һ���ڵ�
			previous->link = current->link;
		}
		else
		{
			first = first->link;
		}
		delete current;
	}
	std::cout << "No such element." << std::endl;

}

template <class T>
void List<T>::Invert()
{
	ListNode<T>* p = first;
	ListNode<T>* q = 0;
	while (p)
	{
		ListNode<T>* tmp = q;
		q = p;
		p = p->link;
		q->link = tmp;
	}
	first = q;
}

template <class T>
void List<T>::Concatenate(List<T> l2)
{
	if (!first) {
		first = l2.first;
		return;
	}
	if (l2.first)
	{
		ListNode<T>* p;
		for (p = first; p->link; p = p->link);
		p->link = l2.first;
	}
}

#endif