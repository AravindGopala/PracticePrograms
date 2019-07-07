#include <stdio.h>
union endian{
	int i;
    char c[2];
};

int main()
{
    printf("Hello World!\n");
int i=0x7875;
char c1=(char)i;
union endian e;
e.i = 0x7875;
//	e.c=0x75;
    printf("%ld\n", sizeof(char));
    printf("%x\n", e.c[0]);
//	e.c=0x78;
    printf("%x\n", e.c[1]);
    e.i=0x7875;
    printf("%c\n", c1);
}
