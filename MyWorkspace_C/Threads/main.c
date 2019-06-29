#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

void *print()
{
	printf("Hello World\n");
}

int main()
{
//pthread_t pid1, pid2;
//pthread_create(&pid1, NULL, print, NULL);
//pthread_create(&pid2, NULL, print, NULL);
//pthread_join(pid1, NULL);
//pthread_join(pid2, NULL);
fork();
fork();
printf("This is fork\n");
return 0;
}
