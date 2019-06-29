
#include<stdio.h>
typedef struct
{
	int a;
	int b;
} new_type;

void f1(void *in);
void gh()
{
	printf("Hello\t");
}
typedef struct ty{
	int a;
	int b;
}jk;
int main()
{
	new_type mine = {0,1};
	printf("%d %d\n",mine.a,mine.b);
	f1((void*)&mine);
	int a=100;
	int *i=&a;
	void(*f)();
	jk* ui;
	jk fg;
	ui = &fg;
	ui->a=20;
	ui->b=30;
	f=gh;
	f();
	printf("0x%x",ui);
	return 0;
}

void f1(void *in)
{
	new_type *blah =(new_type*)in;               ;
	printf("-%d %d-\n",blah->a,blah->b);
	blah->a = 1;
}
