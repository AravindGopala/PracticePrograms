#include "QuackBehavior.h"
#include <iostream>

using namespace std;
class Quack final: public QuackBehavior
{
	void Sound() override
	{
		cout<<"Quack Quacks"<<endl;
	}
};
