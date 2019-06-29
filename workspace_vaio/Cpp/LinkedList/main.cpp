#include <iostream>
#include "node.h"
#include <vector>

using namespace std;

int main()
{
    vector<int> i{0};
    node* LinkedList = new node();
    LinkedList->addnode(20);
    LinkedList->addnode(30);
    LinkedList->addnode(40);
    LinkedList->addnode(50);
    LinkedList->printallelements();
}
