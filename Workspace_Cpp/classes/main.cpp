#include <iostream>

using namespace std;

class node{
public:
	int data;
	node* p;
	node(int d){
		p=NULL;
		data=d;
	}
};

class linkedList : private node
{
	node* Head;
	node* tail;
public:
	linkedList():node(0){
Head = new node(0);
tail = Head;
	}

	void Addnode(int);
	void printlist();
};
void linkedList::Addnode(int r)
{
	tail->p = new node(10);
	tail=tail->p;
	tail->data=r;
}
void linkedList::printlist()
{
	node* next=Head->p;
while(1)
{
if(next!=tail)
{
	cout<<next->data<<endl;
	next=next->p;
}
else
{
	cout<<next->data<<endl;
	return;
 }
}
}

int main()
{
	linkedList* tom = new linkedList();
	tom->Addnode(10);
	tom->Addnode(20);
	tom->Addnode(30);
	tom->printlist();
	cout << "Hello World!" << endl;
	return 0;
}
