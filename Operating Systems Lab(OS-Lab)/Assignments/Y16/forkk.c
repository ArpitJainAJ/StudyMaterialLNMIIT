#include  <stdio.h>
#include  <sys/types.h>
#include  <sys/wait.h>
#define   MAX_COUNT  200

void  ChildProcess(void);               
void  ParentProcess(void);               

int  main(int argc, char *argv[])
{
	
     pid_t  pid;

     pid = fork();
     if (pid == 0) {
	 
          ChildProcess();
}
     else 
          ParentProcess();
}

void  ChildProcess()
{
     	int i, n, t1 = 0, t2 = 1, nextTerm;
	
	for (i = 1; i <= 10; ++i)
    {
        printf("%d, ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
   
          
}
printf("   This line is from child, value = %d\n", getpid());
     printf("   *** Child process is done ***\n");
}

void  ParentProcess(void)
{	
	
     int   i;

     
     printf("This line is from parent, value = %d\n", getpid());
	wait(NULL);
     printf("*** Parent is done ***\n");
	

}
