#include "QuackBehavior.h"
#include <iostream>

using namespace std;
class Squeak final: public QuackBehavior
{
	void Sound() override
	{
		cout<<"Squeak Squeak"<<endl;
	}
};
