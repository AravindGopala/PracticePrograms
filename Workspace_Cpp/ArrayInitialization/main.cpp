#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int myNumbers[100]={10};
	for(int temp: myNumbers)
	{
		//std::cout<<temp<<'\n';
	}
	char hj[]{'w','\0','e','\0'};
		std::cout<<hj<<'\n';
//		std::cout<<strlen(hj)<<'\n';
		std::string df{"Aravind"};
		std::cout<<df<<'\n';
	 char* gh = (char*) "Aravind Datla";
	// char gh[]="Aravind Datla";
	std::cout<<gh<<'\n';
	//(*gh)[2]=10;//cannot assign to a string literal as it is assigned in the .data section of the elf binary
	int** arr = new int*[10];
	int* ari = new int[10]{};
	//int[] foo =new int[100];
	for(int i=0; i<=9;i++)
	{
		arr[i]=new int[10];
	}
//		int* xc[10] = new int[10];
	for(int j=0; j<=9;j++)
	{
	ari[j]=20;
	std::cout<<j<<ari[j]<<'\n';
	}
	for(int i=0; i<=9;i++)
	{
		for(int j=0; j<=9;j++)
		{
		arr[i][j]=20;
		//std::cout<<i<<j<<arr[i][j]<<'\n';
		}
	}
	return 0;
}
