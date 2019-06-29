#include "node.h"
  node* node::head = nullptr;
  node* node::tail = nullptr;
void node::addnode(int value)
{
    node* newnode = new node();
    newnode->Value = value;
    if(head == nullptr)
    {
        updatehead(newnode);
        updatetail(newnode);
    }

else{
        tail->next=newnode;
        updatetail(newnode);
    }

}

void node::updatehead(node* f)
{
        head = f;
}

void node::updatetail(node* f)
{
        tail = f;
}

void node::printallelements()
{
       for(node* i= head; i!=nullptr; i=i->next)
       {
           std::cout<<i->getValue()<<std::endl;

       }

}
