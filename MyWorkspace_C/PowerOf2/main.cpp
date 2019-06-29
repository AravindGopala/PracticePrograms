#include <iostream>

using namespace std;

 bool PowerOf2(int p)
 {
	cout<<(p&(p-1))<<endl;
		  return  (p &&!(p&(p-1)));
 }
int main()
{
	cout << "Hello World!" << endl;
	cout<<PowerOf2(3)<< endl;
	return 0;

}
