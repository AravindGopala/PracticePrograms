#include <iostream>
#include <utility>

using namespace std;

int main()
{
	auto lambda = [i=0,j=1]()mutable{
		i=std::exchange(j,j+i);
		cout<< i <<std::endl;
	};
	int k=0;
	while(k<10)
	{
	lambda();
	k++;
	}
}
