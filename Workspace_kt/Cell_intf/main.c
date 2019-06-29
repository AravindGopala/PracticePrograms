#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct b{
   int e;
   int f;
}insider;

typedef struct a1{
    int a;
    int b;
    int c;
    int d;
    insider insideStruct;
}OutsideStruct;

void func1()
{
    int i[4000]={1};
    memset(&i, 0xFF, sizeof(i));
}

void func2()
{
    OutsideStruct outside;
    insider one = {
        .e=1,
    };
    memset(&outside, 0, sizeof(OutsideStruct));
    memcpy(&outside.insideStruct, &one, sizeof(insider));
    printf("e: %d\n", outside.insideStruct.e);
    printf("f: %d\n", outside.insideStruct.f);
}


int main()
{
    printf("Hello World!\n");
    func1();
    func2();
    return 0;
}
