#include<stdio.h> // fro print statement
#include<unistd.h>//for fork()
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
    pid_t pid; //pid_t is a signed integer type which is capable of representing a process ID
    pid=fork(); //fork return 0 for child process & return 1 or more for parent process ,-1 for error
    int status;

    if(pid==0)
    { printf("child process :%d\n",getpid());
    sleep(5);
    exit(10);
   

    }
   
    else
   {
        printf("parent process: %d\n",getpid());
        wait(&status);
        printf("exit status %d",WEXITSTATUS(status));
   

   }
return 0;
}
//parent process runs first then child process