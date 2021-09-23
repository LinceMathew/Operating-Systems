#include<stdio.h> // fro print statement
#include<unistd.h>//for fork()
int main()
{
    pid_t pid; //pid_t is a signed integer type which is capable of representing a process ID
    pid=fork(); //fork return 0 for child process & return 1 or more for parent process ,-1 for error

    if(pid==0)
    { printf("child process :%d\n",getpid());
   

    }
   
    else
   {
        printf("parent process: %d\n",getpid());
   

   }
return 0;
}
//parent process runs first then child process

