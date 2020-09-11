#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h> // The maximum number of student threads.
#define MAX_Students 50 // Function prototypes...
//#define students 10
//#define CHAIRS 3
void *student(void *num);
void *TA(void *);
void randwait(int secs);

//Define the semaphores and mutex.
// waitingHallway Limits the # of students allowed  to enter the waiting room at one time.
sem_t waitingHallway;
// TAChair ensures mutually exclusive access to the TA chair.
sem_t TAChair;
// TAPillow is used to allow the TA to sleep until a Students arrives.
sem_t TAPillow;
// helpbyTA is used to make the student to wait until the TA is done cutting his/her hair.
sem_t helpbyTA;
// Flag to stop the TA thread when all students have been serviced.
int allDone = 0;

int main(int argc, char *argv[])
{
    pthread_t tatid;
    pthread_t tid[MAX_Students];
    int i, x, numstudents, numChairs; int Number[MAX_Students];
    printf("Maximum number of students can only be %d. Enter number of students and chairs.\n",MAX_Students);
    scanf("%d",&x);
    numstudents = x;
    scanf("%d",&x);
    numChairs = x;
    if (numstudents > MAX_Students) {
       printf("The maximum number of Students is %d.\n", MAX_Students);
       system("PAUSE");   
       return 0;
    }
    printf("A solution to the sleeping TA problem using semaphores.\n");
    for (i = 0; i < MAX_Students; i++) {
        Number[i] = i;
    }
    // Initialize the semaphores with initial values...
    sem_init(&waitingHallway, 0, numChairs);
    sem_init(&TAChair, 0, 1);
    sem_init(&TAPillow, 0, 0);
    sem_init(&helpbyTA, 0, 0);
   
    // Create the TA.
    pthread_create(&tatid, NULL, TA, NULL);
   
    // Create the students.
    for (i = 0; i < numstudents; i++) {
        pthread_create(&tid[i], NULL, student, (void *)&Number[i]);
    }
    // Join each of the threads to wait for them to finish.
    for (i = 0; i < numstudents; i++) {
        pthread_join(tid[i],NULL);
    }
    // When all of the students are finished, kill the TA thread.
    allDone = 1;
    sem_post(&TAPillow); // Wake the TA so he will exit.
    pthread_join(tatid,NULL);
    //system("PAUSE");   
    return 0;
}

void *student(void *number) {
     int num = *(int *)number; // Leave for the room and take some random amount of  time to arrive.
     printf("student %d leaving for TA room to visit.\n", num);
     randwait(5);
     printf("student %d arrived at TA office area.\n", num); // Wait for space to open up in the waiting room...
     sem_wait(&waitingHallway);
     printf("student %d entering waiting room.\n", num); // Wait for the TA chair to become free.
     sem_wait(&TAChair); // The chair is free so give up your spot in the  waiting room.
     sem_post(&waitingHallway); // Wake up the TA...
     printf("student %d waking the TA.\n", num);
     sem_post(&TAPillow); // Wait for the TA to finish your problem.
     sem_wait(&helpbyTA); // Give up the chair.
     sem_post(&TAChair);
     printf("student %d leaving TA room.\n", num);
}

void *TA(void *junk)
{
// While there are still students to be serviced... Our TA is omnicient and can tell if there are  students still on the way to his room.
  
  while (!allDone) { // Sleep until someone arrives and wakes you..
    printf("The TA is sleeping\n");
    sem_wait(&TAPillow); // Skip this stuff at the end...
    if (!allDone)
    { // Take a random amount of time to solve a student's problem.
     printf("The TA is solving problem\n");
     randwait(3);
     printf("The TA has finished solving problem.\n"); // Release the student when done helping...
     sem_post(&helpbyTA);
    }
    else {
         printf("The TA is going home for the day.\n");
    }
   }
}
   
void randwait(int secs) {
     int len = 1; // Generate an arbit number...
     sleep(len);
}






