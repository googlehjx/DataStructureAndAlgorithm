#include <iostream>



using namespace std;

class DbList;
class DbListNode
{
	friend class DbList;
public:
	int data;
	DbListNode* llink, * rlink;
};

class DbList
{
public:
	DbList()
	{
		first = new DbListNode();
		first->llink = first->rlink = first;
	}
	void Insert(DbListNode*, DbListNode*);
	void Delete(DbListNode*);
//private:
	DbListNode* first;
};

void DbList::Insert(DbListNode* p, DbListNode* x)
{
	if (x->rlink == first)
	{ // ¿ÕÁ´±í
		p->rlink = 0;
		p->llink = first;
		x->rlink = p;
	}
	else 
	{
		p->rlink = x->rlink;
		x->rlink = p;
		p->llink = x;
		p->rlink->llink = p;
	}
	
}

void DbList::Delete(DbListNode* x)
{
	if (x == first) throw "Deltion of head not permitted.";
	else
	{
		x->llink->rlink = x->rlink;
		x->rlink->llink = x->llink;
		//delete x;
	}
}




int main()
{
	cout << "Ë«ÏòÑ­»·Á´±í²âÊÔ£º" << endl;
	DbList intList;
	DbListNode node1, node2, node3;
	node1.data = 10;
	node2.data = 20;
	node3.data = 30;

	intList.Insert(&node1, intList.first);
	intList.Insert(&node2, intList.first);
	intList.Insert(&node3, intList.first);

	cout << intList.first->rlink->data << endl;
	cout << intList.first->rlink->rlink->data << endl;
	cout << intList.first->rlink->rlink->rlink->data << endl;
	//cout << intList.first->rlink->rlink->rlink->rlink->data << endl;
	//cout << intList.first->rlink->rlink->rlink->rlink->rlink->rlink->data << endl;
	//cout << intList.first->rlink->rlink->rlink->rlink->rlink->rlink->rlink->data << endl;
	//cout << intList.first->rlink->rlink->rlink->rlink->rlink->rlink->rlink->rlink->data << endl;

	intList.Delete(&node2);
	cout << intList.first->rlink->data << endl;
	cout << intList.first->rlink->rlink->data << endl;

}