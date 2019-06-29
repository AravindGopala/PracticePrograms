#include "Quack.h"
#include "Wings.h"
#include "Duck.h"
#include "memory"

using namespace std;
class MallardDuck : public Duck
{
public:
	MallardDuck():Duck(new Wings() , new Quack())
	{
	}

};
