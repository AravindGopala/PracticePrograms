#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

int main()
{
//	int i{10.1};
//	int i1 = int{10.23};
	int i2 = 10;
	int i3 = int(10);
	int* i4= new int[10];
	int k[10][10];
	int i5[2] = {10,2};
	int i6[]{1,2};
	const char* c=static_cast<const char*>("Datla");
	std::string str[]{"Aravind", "Datla"};
	const char* str1 = str[0].c_str();
//	std::vector<int> v(10);
//	std::vector<int> v1{10};
	cout << "V1!" <<'\n'<<c[5]<<'\n';
//	for(int t=0; t<300 ; t++)
//	{
//	cout << "Hello World!" <<'\n'<<i5[t]<<'\n';
//	}
//	for(const int t : i5)
//	{
//	cout << "Hello World!" <<'\n'<<t<<'\n';
//	}
	for(int t=0; t<strlen(str1) ; t++)
		{
		cout << "Hello World!" <<'\n'<<str1[t]<<'\n';
		}
	for(const std::string t : str)
		{
		cout << "Hello World!" <<'\n'<<t<<'\n';
		}
	return 0;
}
