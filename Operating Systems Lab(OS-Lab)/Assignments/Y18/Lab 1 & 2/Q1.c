#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main() 
{
	int mypid, myppid;
	printf("Program to know PID and PPID's information\n");
	mypid = getpid();
	myppid = getppid();
	printf("My process ID is %d\n", mypid);
	printf("My parent process ID is %d\n", myppid);
	return 0;
}
