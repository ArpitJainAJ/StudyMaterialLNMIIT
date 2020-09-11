#include <stdio.h>
int main()
{
	int pid;
	int status;
	pid = fork();

	// Child process
	if (pid == 0)
	{
		system("ps -ef");
		sleep(10);
		system("ps -ef");
		return 3; //exit status is 3 from child process
	}
	else
	{
		sleep(3);
		wait(&status);
		printf("In parent process: exit status from child is decimal %d, hexa %0x\n", status,status);
	}
	return 0;
}
