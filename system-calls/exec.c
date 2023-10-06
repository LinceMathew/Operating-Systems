#include<stdio.h>
#include<unistd.h>
void main()
{
    printf("pid of exe :%d",getpid());
    char *args[]={NULL};
    execv("./EXEC2",args);
    
}
