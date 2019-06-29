#include "FlyBehavior.h"
#include "QuackBehavior.h"
#include <iostream>

using namespace std;
class Duck
{
public:
Duck(FlyBehavior* fly_type, QuackBehavior* quack_type):
	flybehavior(fly_type),
	quackBehavior(quack_type)
{}
public:
	unique_ptr<FlyBehavior> flybehavior;
	unique_ptr<QuackBehavior> quackBehavior;
	void fly()
	{
		flybehavior->fly();
	}
	void Sound()
	{
		quackBehavior->Sound();
	}
};
