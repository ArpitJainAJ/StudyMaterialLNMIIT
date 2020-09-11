#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>


sem_t lock,pap,tob,mat;
int num=0;


void* agentcode(void* arg){
	do{
		sem_wait(&lock);
		//printf("Agent thread created\n");
		printf("\n");
		num = (rand() % 3 + 1);
		if(num==1){
			sem_post(&pap);
			printf("match and tobaco on table\n");
		} else if(num==2){
			sem_post(&tob);
			printf("match and paper on table\n");
		} else if(num==3){
			sem_post(&mat);
			printf("paper and tobaco on table\n");
		}

		sem_post(&lock);
		sleep(5);
	} while(1);
}


void* smoker1(void* arg){
	do{
	sem_wait(&pap);
	sem_wait(&lock);
	sleep(2);
	printf("paper supplied and cigarette made\n");
	//sleep(5);
	sem_post(&lock);
	sleep(2);
	}while(1);
}

void* smoker2(void* arg){
	do{
	sem_wait(&tob);
	sem_wait(&lock);
	sleep(2);
	printf("tobaco supplied and cigarette made\n");
	//sleep(5);
	sem_post(&lock);
	sleep(2);
	}while(1);
}

void* smoker3(void* arg){
	do{
	sem_wait(&mat);
	sem_wait(&lock);
	sleep(2);
	printf("match supplied and cigarette made\n");
	//sleep(5);
	sem_post(&lock);
	sleep(2);
	}while(1);
}


int main(){
	pthread_t agent,s1,s2,s3;

	sem_init(&lock, 0, 1);
	sem_init(&s1, 0, 0);
	sem_init(&s2, 0, 0);
	sem_init(&s3, 0, 0);

	pthread_create(&agent, NULL, agentcode, NULL);
	pthread_create(&s1, NULL, smoker1, NULL);
	pthread_create(&s2, NULL, smoker2, NULL);
	pthread_create(&s3, NULL, smoker3, NULL);

	pthread_join(agent,NULL);
	pthread_join(s1,NULL);
	pthread_join(s2,NULL);
	pthread_join(s3,NULL);
}
