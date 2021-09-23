#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
int main(){

    struct stat buff;
   stat("./Experiment-01-fork.c",&buff);
   printf("%ldbytes",buff.st_size);


    return 0;

}
