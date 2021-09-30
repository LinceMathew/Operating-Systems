#include<semaphore.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#define size 5
int buffer[size];//declare buffer
sem_t empty_sem;//decllare empty semaphore
sem_t full_sem;//declare full semaphore
pthread_mutex_t mutex;//declare binary semaphore 
int i=0,j=0;//iteration
void* produce(){
    int item;
    srand(time(0));
    while(1)
    {
        sleep(rand()%10);
        item=rand()%1000;
        sem_wait(&empty_sem);//decrement empty
        pthread_mutex_lock(&mutex);//change mutex from 1 to 0
        buffer[i]=item;
        printf("producer produce the item %d in the buffer slot %d",item,i+1);
        i=(i+1)%size;
        pthread_mutex_unlock(&mutex); //change mutex again into 1
        sem_post(&full_sem);//increment full



    }
}
void* consume()
{
    int item;
    while(1)
    {
        sleep(rand()%10);
        sem_wait(&full_sem);
        pthread_mutex_lock(&mutex);//mutex change to 0
        item=buffer[j];
        printf("consumer consumed the item %d in the buffer %d \n",item,j+1);
        j=(j+1)%size;
        pthread_mutex_unlock(&mutex);//mutex change 
        sem_post(&empty_sem);
    
    }
}
void main(){
    sem_init(&empty_sem,0,0);//initialize empty semaphore 
    sem_init(&full_sem,0,size);//initlize full semaphore
    pthread_mutex_init(&mutex,NULL);//initilaize pthread
    pthread_t producer,consumer; 
    pthread_create(&producer,NULL,produce,NULL);
    pthread_create(&consumer,NULL,consume,NULL);
    sleep(60);

}