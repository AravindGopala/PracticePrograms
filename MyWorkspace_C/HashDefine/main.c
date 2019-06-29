#include <stdio.h>
#define MAX(A,B) ((A>B?A:B))
typedef int Datla;
int main()
{
	int i=21,j=32;
	int* r=i;
	Datla result =MAX(21,32);
	printf("The maximum value is %d!\n", result);
	return 0;
}
