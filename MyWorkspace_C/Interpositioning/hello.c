#include <stdio.h> 
#include <stdlib.h> 
#include <malloc.h> 
  
int main(void) 
{ 
    // Call to user defined malloc 
    void *ptr = malloc(4); 
      
    printf("Hello World\n"); 
    return 0; 
} 
