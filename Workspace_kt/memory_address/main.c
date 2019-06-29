#include <stdio.h>

typedef struct{
int a;
char *c;
//char d;
//char f;
//char g;
}alpha;


//print offset of each struct member;
int main()
{
    alpha one={10,"c"};
    printf("%d\n",one.a);
    printf("%s\n",one.c);
alpha* two= malloc(sizeof (alpha));
two->a=20;
two->c="c";
char *j = "Aravind";
char l[]="Aravind";
printf("%c\n",j[6]);
printf("print string %d\n",strlen(l));
printf("print string %d\n",sizeof(j) / sizeof(j[0]));
printf("%d\n",two->a);
printf("%s\n",two->c);
printf("%x\n",(two));
printf("%d\n",(void*)&(two->c)-(void*)&(two->a));
printf("%x\n",sizeof(two->a)/sizeof (char));
printf("%x\n",&(two->c));
printf("%x\n",sizeof(alpha)/sizeof(char));
//printf("%x\n",&(two));
    return 0;
}
