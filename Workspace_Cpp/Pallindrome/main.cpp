#include <iostream>

using namespace std;

bool pallindrome(int i)
{
	int sum =0;
	int pal=i;
while (i>0)
{
	int quotient = i%10;
	sum = sum*10 + quotient;
	i =i/10;
}
	return sum==pal;
}
int fibnocci(int i)
{
	int result=0;

	if(i==0)
	{
		return 1;
	}
	if(i==1)
	{
		return 1;
	}
	if (i>1)
	{
		return fibnocci(i-1)+fibnocci(i-2);
	}

}

double factorial(int i)
{

	if(i==0)
	{
		return 1;
	}
	if (i>0)
	{
		return i*factorial(i-1);
	}

}

int main()
{
	cout << pallindrome(1220) <<'\n';
	cout <<scientific<<factorial(10)<<'\n';
	cout<<fibnocci(10)<<endl;
	return 0;
}
