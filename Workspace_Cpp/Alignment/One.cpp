#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
   //cout << "Hello World" << endl; 
   char *c= (char*)"HelloWorld";
  // std::cout<<c<<'\n';
printf("%p\n", c);
   c++;
printf("%p\n", c);
//   std::cout<<*c<<'\n';
   
   return 0;
}
