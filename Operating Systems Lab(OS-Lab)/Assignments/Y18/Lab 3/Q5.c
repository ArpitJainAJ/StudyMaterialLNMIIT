/*Implement a virtual scheduler that supports two different functionalities: process generation and process scheduling. The part of the code which performs process generation generates processes in regular interval. The execution time of the process should be random (you can use a random number generator for this purpose). The process should have sufficient I/O as well as CPU requirements. For this purpose you can divide generated execution time into four equal parts one part for I/O, second part for CPU ,third part of I/O and fourth part of CPU or vice versa. You should maintain two queues ready queue (which contains the set of runnable processes) and I/O queue. The scheduler chooses/schedules one of the runnable processes according to the scheduling algorithm for execution. Next, it sends a ‘notify’ signal to only that chosen/scheduled process and ‘suspend’ signal to all other processes. Depending on the signal (‘notify’/’suspend’’) received from the scheduler, the processes can either (re)start processing or wait until it’s scheduled again. After the completion of the I/O, the process should be moved to the ready queue. Once all the processes terminate, the scheduler also terminates. You have to evaluate the performance of SRTF (Shortest Remaining Time First) algorithm in terms of average response time, average waiting time and average turnaround time.
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<unistd.h>
#include<stdlib.h>

// C++ program to implement Shortest Remaining Time First
// Shortest Remaining Time First (SRTF)


struct Process {
	int pid; // Process ID
	int bt; // Burst Time
	int at; // Arrival Time
};

//Function to generate all processes
void ProcessGeneration(struct Process proc[],int N)
{
	//Alloting processid, burst time and arrival time to each process
	printf("Displaying all processes\n");
	for(int i=0;i<N;i++)
	{
		int a=i+1;
		int b=(rand() % (upper – lower + 1))+lower;
		int c=(rand() % (upper – lower + 1))+lower;
		proc[i]={a,b,c};
		//Displaying Processes
		printf("Process id:%d	Burst Time:%d	Arrival Time:%d\n",a,b,c);
	}
}

//Function to reduce i/o time
void decio(int iolist[], int io[],int n)
{
	for(int i=0;i<n;i+++
	{
		if(io[iolist[i]]>0)
		{
			io[iolist[i]--;
			break;
		}
	}
}
// Function to find the waiting time for all processes
void findWaitingResTime(Process proc[], int n, int wt[],int rest[])
{
	//Arrays for remaining time
	int rt[n],io[n],iolist[n]={-1},k=0;

	// Copy the burst time into rt[]
	for (int i = 0; i < n; i++)
	{
		rt[i] = (proc[i].bt)/2;
		io[i] = proc[i].bt - rt[i];
	}

	int complete = 0, t = 0, minm = INT_MAX;
	int shortest = 0, finish_time;
	bool check = false;

	// Process until all processes gets completed
	while (complete < n)
	{
		// Find process with minimum remaining time among the processes that arrives till the current time
		for (int j = 0; j < n; j++)
		{
			if ((proc[j].at <= t) && (rt[j] < minm) && rt[j] > 0)
			{
				minm = rt[j];
				shortest = j;
				check = true;
			}
		}

		if (check == false)
		{
			t++;
			decio(iolist,io,n);
			continue;
		}

		// Reduce remaining time by one
		rt[shortest]--;
			

		// Update minimum
		minm = rt[shortest];
		if (minm == 0)
			minm = INT_MAX;

		// If a process gets completely
		// executed
		if (rt[shortest] == 0)
		{
			//add to io list
			iolist[k++]=shortest;

			// Increment complete
			complete++;
			check = false;

			// Find finish time of current
			// process
			finish_time = t + 1;

			// Calculate waiting time
			wt[shortest] = finish_time - proc[shortest].bt - proc[shortest].at;

			if (wt[shortest] < 0)
				wt[shortest] = 0;
		}
		// Increment time
		t++;
	}
}

// Function to calculate turn around time
void findTurnAroundTime(Process proc[], int n, int wt[], int tat[])
{
	// calculating turnaround time by adding
	// bt[i] + wt[i]
	for (int i = 0; i < n; i++)
		tat[i] = proc[i].bt + wt[i];
}

// Function to calculate average time
void findavgTime(Process proc[], int n)
{
	//arrays for waiting time, turn around time,response time, total waiting time, total turn around time, total response time
	int wt[n]={0}, tat[n]={0}, rest[n]={0} total_wt = 0, total_tat = 0,total_rest=0;

	// Function to find waiting time and response time of all processes
	findWaitingResTime(proc, n, wt, rest);

	// Function to find turn around time for all processes
	findTurnAroundTime(proc, n, wt, tat);

	// Display processes along with all details
	cout << "Processes "
		<< " Burst time "
		<< " Waiting time "
		<< " Turn around time\n"; 

	// Calculate total waiting time and total turnaround time
	for (int i = 0; i < n; i++)
	{
		total_wt = total_wt + wt[i];
		total_rest = total_rest +rest[i];
		total_tat = total_tat + tat[i];
		printf("Process ID:%d\tBurst Time:%d\tWaiting Time:%d\tTAT:%d\n", proc[i].pid,proc[i].bt,wt[i],tat[i]);
	}

	printf("\nAverage waiting time = :%f", (float)total_wt / (float)n);
	printf("\nAverage turn around time = :%f", (float)total_tat / (float)n);
	printf("\nAverage Response Time = :%f", (float)total_rest / (float)n);
}

// Driver code
int main()
{
	//Getting no of processes from user
	printf("Enter no of process to be made");
	int N,lower=1,upper=10;
	scanf("%d\n",&N);
	struct Process* proc = (struct Process *) malloc (N*sizeof(struct Process));

	//Generating Processes
	ProcessGeneration(proc,N);

	findavgTime(proc, N);
	return 0;
}






