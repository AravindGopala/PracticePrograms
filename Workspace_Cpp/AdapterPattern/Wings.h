#include "FlyBehavior.h"
#include <iostream>

using namespace std;
class Wings: public FlyBehavior
{
	void fly() override
	{
		cout<<"flying with wings"<<endl;
	}
};
