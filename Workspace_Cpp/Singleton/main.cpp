#include "Singleton.h"

int main()
{
	auto instance=Singleton::getInstance();
	auto instance2=Singleton::getInstance();
	auto instance3=Singleton::getInstance();
	(void)instance;
	(void)instance2;
	(void)instance3;
}
