#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main() {
int pid;
int pids[3];
int status;
int numprocesses = 0;
int total_processes = 3;
while (numprocesses < total_processes) {
pid = fork();
// Child process
if (pid == 0) {
printf("In child process: process id is %d\n", getpid());
sleep(5);
return 4;
} else {
pids[numprocesses] = pid;
numprocesses++;

printf("In parent process: created process number: %d\n", pid);
}
}
// Waiting for 3rd child process
waitpid(pids[total_processes - 1], &status, 0);
if (WIFEXITED(status) != 0) {
printf("process %d exited normally\n", pids[total_processes - 1]);
printf("exit status from child is %d\n", WEXITSTATUS(status));
} else {
printf("process %d not exited normally\n", pids[total_processes -
1]);
}
return 0;
}
