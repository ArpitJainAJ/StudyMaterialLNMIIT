#include<stdio.h>
#include <unistd.h>
#include<pthread.h>
#include<semaphore.h>

sem_t rw_mutex , mutex ;
int data = 0, chair_count = 0;


void *ta(void *arg)
{
  do
  {
  	int f;
  	f = ((intptr_t) arg);
  	sem_wait(&mutex);
  	chair_count = chair_count + 1;
  	if(chair_count == 4)
  	  sem_wait(&rw_mutex);
  	sem_post(&mutex);
  	printf("Data read by the reader%d is %d\n",f+1,data);
  	//sleep(1);
  	sem_wait(&mutex);
  	chair_count = chair_count - 1;
  	if(chair_count == 0)
  	 sem_post(&rw_mutex);
  	sem_post(&mutex);
  	sleep(4);
  }while(1);
}

void *student(void *arg)
{
  do{
  	int f;
  	f = ((intptr_t) arg);
  	sem_wait(&rw_mutex);
  	data++;
  	printf("Data writen by the writer%d is %d\n",f+1,data);
  	//sleep(1);
  	sem_post(&rw_mutex);
  	sleep(4);
  }while(1);
}


int main()
{
  int i,b; 
  pthread_t taid,sid[5];
  sem_init(&mutex,0,1);
  sem_init(&rw_mutex,0,1);
	pthread_create(&taid,NULL,ta,(void *)(intptr_t));
  for(i=0;i<5;i++)
  {
    pthread_create(&sid[i],NULL,student,(void *)(intptr_t)i);
  }
	pthread_join(taid,NULL);
  for(i=0;i<5;i++)
  {
    pthread_join(sid[i],NULL);    
  }
  return 0;
}
