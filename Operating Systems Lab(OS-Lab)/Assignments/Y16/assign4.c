#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

sem_t mutex, student, ta;
int waiting=0, chairs=3;
int s=0;

void* Student(){
	sem_wait(&mutex);
	if(waiting<chairs){
	waiting++;
	printf("Student %d has taken the chair\n",s++);
	sem_post(&student);
	sem_post(&mutex);
	sem_wait(&ta);
	}
	else{
	printf("Student %d left\n",s++);
	sem_post(&mutex);
	}	
}

void* taWork() {
	while(1) {
		sem_wait(&student);
		sem_wait(&mutex);
		printf("TA is working\n");
		
		waiting--;
		sem_post(&ta);
		sem_post(&mutex);	
	}
}

int main(){
	sem_init(&mutex,0,1);
	sem_init(&student,0,0);
	sem_init(&ta,0,0);
	int rv,rv1;
	pthread_t stu[10];
	pthread_t teach;
	rv= pthread_create(&teach,NULL,taWork,NULL);
	
	if(rv) {
        printf("Thread Creation fails\n");
        exit(0);
    }    
    
    for(int i=0;i<10;i++) {
        rv1= pthread_create(&stu[i],NULL,Student,NULL);
    }
	pthread_join(teach,NULL); 
	pthread_exit(0);	
	return 0;
}
