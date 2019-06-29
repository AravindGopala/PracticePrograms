#include <iostream>
#include <string>
using namespace std;

int main()
{
	int** p= new int*[10];
	string** tr= new string*[3];
//	char *c = (char*)"Aravind Datla";
//	char *c1=(char*)"Aravind Datla Gopala";
		string c = "Aravind Datla";
		string c1="Aravind Datla Gopala";
	tr[0]=&c;
	tr[1]=&c1;
	cout << tr[0][0] << endl;
	cout << tr[0][1] << endl;
	return 0;
}
