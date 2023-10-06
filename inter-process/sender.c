#include<stdio.h>
#include<sys/shm.h>
#include<unistd.h>
#include<string.h>
int main(){
    void * shared_memory; //initalize shared memory
    int shmid;
    char buff[100];
    shmid=shmget((key_t)1000,1024,0666|IPC_CREAT); //created ipc memory with key 1000
    printf("the shm id generated is:%d",shmid);
    shared_memory=shmat(shmid,NULL,0);//memmory segment created is attached to the shared memory
    read(0,buff,100);//input from user
    strcpy(shared_memory,buff);
    printf("wrote :%s\n",(char *)shared_memory);
    
}