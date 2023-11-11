#include <stdio.h>

int main()
{
    FILE * fd = fopen("/home/aravind/Documents/Workspace/PracticePrograms/Workspace_kt/diag_echo_debug/one", "r");
    char * line=NULL;
    size_t LineBufSize = 0;
    getline(&line, &LineBufSize, fd);
    printf("\n%s\n", line);
    printf("Hello World!\n");
    return 0;
}
