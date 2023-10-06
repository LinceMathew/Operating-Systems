#include<stdio.h>
#include<sys/shm.h>
int main(){
    void *shared_memory;
    int read[100];
    int shmid;
    shmid=shmget((key_t)1000,1024,0666);
    shared_memory=shmat(shmid,NULL,0);
    printf("%s",(char *)shared_memory);

}


