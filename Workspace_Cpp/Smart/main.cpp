#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
#include <stdlib.h>
#include <string.h>

using namespace std;
class complex{
	int real;
	int img;
public:
	complex(int real, int complex)
		:real(real),
		img(complex){}
	complex(const complex& other)
	{
		cout<<"copy constructor called"<<endl;
		this->real=other.real;
		this->img=other.img;
	}
//complex operator + (const& complex obj)
//{

//}
};
struct A{
		int a;
		double b;
		char c;
	};

int main(int argc, char** argv, char** env)
{
	cout<<"arguments are "<<argc<<'\n';
	string** array=new string*[10];
	array[0]=new string("Aravind Datla");
	array[1]=new string("Aravind Gopala");
	string wow="Datla";
	string ar{};
	int i=0;
	A* e=new A();
	e->a=10;
	e->b=20;
	//int address_offset= (&((*e).c) - (char*)&(e->a));
//	cout<<sizeof(char)<<"struct a is at offset "<<address_offset<<'\n';
	cout<<sizeof(char)<<"struct a is at address"<<&((*e).a)<<'\n';
	cout<<sizeof(char)<<"struct a is at address"<<&((*e).b)<<'\n';
	cout<<"struct A is at address"<<oct<<e<<'\n';
	for_each(wow.cbegin(),wow.cend(),[&wow](char c){
	cout<<c<<'\n';
	//ar.append("tr");
	});
	size_t size=wow.find('a');
	for(auto a: wow)
	{
		cout<<a<<'\n';
	}

	cout<<"position of "<<size<<'\n';
	array[4]=&wow;
	complex tr(10,20);
	unique_ptr<complex> up = make_unique<complex>(10,20);
	shared_ptr<complex> sp = make_shared<complex>(10,20);
	complex rt(tr);
	cout << *array[0] << endl;
	cout << *array[1] << endl;
	cout << *array[4] << endl;

	int y;
	int n;
	int** cv = (int**)(calloc(10,sizeof(int)));
	//cv[0]=(int*)(calloc(10,sizeof(int)));
	//y=(int*)malloc(sizeof(int));
	int *arr;
	arr=(int*)calloc(10, sizeof(int));
	int (*arr1)[10];
	int (*arr2)[10][2];
	arr1=(int(*)[10])calloc(10, sizeof(int));
	arr2=(int(*)[10][2])calloc(20, sizeof(int));
	//int roll[10]={10,20,30,40,50,60,70,80,90,100};
	//arr1=&roll;
	for (n=0;n<10;n++)
	{
	 (*arr1)[n]=35;
	 arr[n]=121;
	}

	for (n=0;n<10;n++)
	{
	for (y=0;y<2;y++)
	{
	(*arr2)[n][y]=38;
	}
	}
	for (n=0;n<10;n++)
	{
	for (y=0;y<2;y++)
	{
	printf("%d,%d\n",(*arr2)[n][y],n);
	}
	}
	for (n=0;n<10;n++)
	{
		printf("%d\n",(*arr1)[n]);

		printf("%d\n",arr[n]);
	}
	printf("%ld\n",sizeof((*arr1)));
	printf("%ld\n",sizeof((*arr1)));

	char* re=(char*)"Aravind Datla";
	int ip[]={1,2,3,4,5,6};
	int* te=ip;
	size_t tty= sizeof(int*);
	printf("%d\n",strlen(re));
	cout<<tty<<'\n';
		cout<<"size of character pointer is "<<dec<<strlen(re)<<'\n';
	cout<<"size of character pointer is "<<re<<'\n';
	i=0;
	while(env[i]!=NULL)
	{
	//cout<<env[i]<<'\n';
	i++;
	}
	return 0;
}
