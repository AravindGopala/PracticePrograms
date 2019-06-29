#include <iostream>
#include <sstream>
#include <memory>
#include <stdint.h>

using namespace std;
struct endianess{
	double square(double x);
	double (*manipulate)(double x);
private:
	char tr;
	int face;
	double rt;
};

double endianess::square(double x){
	return x*x;
}

double cube(double x){
	return (x*x*x);
}

int main()
{
	uint16_t i =0x2054;
	uint16_t j =2;
	char little_endian = (char)i;
	cout<<std::hex<<(int)little_endian<<'\n';
	endianess one;
	cout<<one.square(j)<<std::endl;
	one.manipulate=cube;
	cout<<	one.manipulate(10)<<std::endl;
	endianess *ty = new endianess();
	cout<<ty->square(10)<<std::endl;
	ty->manipulate=cube;
	cout<<ty->manipulate(10)<<std::endl;
	endianess two;
	//int h[][3]={{1,2,3},{3,2,4}};
	int** array;
	int* p;
	char* c="Aravind Datla";
	char* d="Aravind Gopala";
	char** cc=new char*[10];
	++cc=&d;
	cout<<(char)d[8]<<endl;
	cout<<*cc[1]<<endl;
	int** integer=new int*[10];
	for(int i=0; i<=9;i++)
	{
		integer[i]=new int[10];
	}

	array =&p;
	return 0;
}
