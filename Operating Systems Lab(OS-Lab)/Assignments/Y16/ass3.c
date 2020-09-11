#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int count=0;
pthread_mutex_t lock;
pthread_t tide;
pthread_t tido;
void* printe()
{
	while(count<=100)
	{
		pthread_mutex_lock(&lock);
		if(count%2==0)
		{
		printf("%d\n",count);count++;}
		
		pthread_mutex_unlock(&lock);
		
		
		
	}
	
}

void* printo()
{
	while(count<100)
	{
		pthread_mutex_lock(&lock);
		if(count%2!=0)
		{
		printf("in second\n");
		printf("%d\n",count);count++;}
		
		pthread_mutex_unlock(&lock);
		
	}
}
	
	
	


int main()
{
	int rv;
	
	
	
		rv=pthread_create(&tide,NULL,printe,NULL);
		
		rv=pthread_create(&tido,NULL,printo,NULL);
		
		if(rv)
		{
			printf("Error:In the creation of thread \n");
			exit(1);
		}
		
	pthread_join(tide,NULL);	
	pthread_join(tido,NULL);
	pthread_exit(NULL);
}
