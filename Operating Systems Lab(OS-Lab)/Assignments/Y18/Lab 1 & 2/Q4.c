#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	static int a;
	static int b=100;
	fork();
	fork();
	fork();
	fork();
	printf("Hello World\n");
	return 0;
}
