#include <stdio.h>
union{
	int i;
	char c;
}e;

int main()
{
	printf("Hello World!\n");
int i=0x7875;
char c1=(char)i;
	e.c=0x75;
	printf("%ld", sizeof(char));
	printf("%c", e.c);
	e.c=0x78;
	printf("%c", e.c);
	e.i=0x7875;
	printf("%c", c1);
}
