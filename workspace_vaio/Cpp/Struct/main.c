#include <stdio.h>
#include <stdint.h>
union Endianess
{
    int i;
    char c;
};

int main()
{
  //Determine if a Machine is big Endian or a little Endian
    union Endianess One;
    One.i = 0x1221;
    if(One.c == 0x21)
    {
        printf("little Endian\n");
    }
    else
    {
        printf("Big Endian\n");
    }
    printf(" Hi %d", sizeof(char));

}
