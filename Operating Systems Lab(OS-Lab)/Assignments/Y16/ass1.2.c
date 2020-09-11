#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void *prime_no(void *var)
{
	int x = atoi(var);
	for(int i=2;i<x;i++)
    	{
      	  for(int j=2;j<i;j++)
      	  {
      	      if(i%j==0)
      	          break;
      	      else if(i==j+1)
      	          printf("%d\n",i);
      	  }
    	}
}

int main(int argc, int *argv[])
{
	int x = 0;
	//scanf("%d",&x);
	//prime_no(x);
	pthread_t tid;
	pthread_attr_t attr;
	
	pthread_attr_init(&attr);
	x = pthread_create(&tid, &attr, prime_no,argv[1]);
	
	if(x)
	{
		printf("Error Occur While PThreading!");
		exit(1);
	}
	pthread_exit(NULL);
	//pthread_join(tid,NULL);
}
