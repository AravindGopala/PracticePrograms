#include "ISerialFilterService.h"
#include <stdio.h>

extern void initialize(struct SerialFilterService*, void(*)(char*));

void gmail(char* Message)
{
    printf("%s", Message);
}


int main()
{
    struct SerialFilterService S1;
    initialize(&S1, &gmail);
    struct message M1={0x07,0x08};
    struct message M3={0x03,0x08};
    struct message M2={0x08,0x07};
    S1.registerMessage(&S1,&M1);
    S1.registerMessage(&S1,&M3);
    S1.update(&S1, &M2);
}
