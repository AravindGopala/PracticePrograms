#include <cstddef>
#include <iostream>

class node{
public:
    void addnode(int value);
    void printallelements();
    node()
    {
        next = nullptr;
    }
    int getValue()
    {
        return Value;
    }

  private:
    int Value;
    node* next;
    static node* head;
    static node* tail;
    void updatetail(node*);
    void updatehead(node*);
};
