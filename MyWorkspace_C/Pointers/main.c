#include <stdio.h>
#include <string.h>
struct One{
int i;
};

int main()
{
char y_name[5]= {'a','b','c','e','f'};
char my_name[]= "Datla";
 char* name="Aravind";
 char *uht=y_name;
 printf("%s", y_name );
 //printf("%c", *(++uht));
 printf("%p\n", uht);
 printf("%p\n", &my_name);
 struct One* one;
 struct One two;
 one = &two;
 one->i=10;
 (*one).i=20;
 printf("%d", one->i);

 return 0;
}
