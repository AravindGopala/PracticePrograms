#pragma once
#include <iostream>
class Singleton{
private:
	Singleton(){}
	static Singleton* Instance;
public:
	~Singleton(){}
	static const Singleton* getInstance(){
		if(Singleton::Instance==nullptr)
		{
			Singleton::Instance= new Singleton();
			return Singleton::Instance;
		}
		else{
			std::cout<<"I am a singleton"<<std::endl;
			return nullptr;
		}
	}
};

Singleton* Singleton::Instance=nullptr;
