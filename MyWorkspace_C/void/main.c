#include <stdio.h>
#define cal(trq) (int)((void*)&((*Sp).c)-((void*)Sp))

struct Structp
{
	int a;
	int p;
	char c;
}tr;

int main()
{
	printf("Hello World!\n");
	struct Structp* Sp = &tr;
	int  diff = cal(Sp);
	printf("Offset %x\n", Sp);
	printf("Offset %d", (diff));

	return 0;
}
