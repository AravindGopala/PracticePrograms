#include "FlyBehavior.h"
#include <iostream>

using namespace std;
class NoWings final: public FlyBehavior
{
	void fly() override
	{
		cout<<"Does Not Fly"<<endl;
	}
};
