#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int btime[]={0,2,6,1,3,8};
int process[]={0,1,2,3,4,5};
int comp[]={0,0,0,0,0,0};

int qtime=2;int t=1;int timer=0;
int len=(int)( sizeof(btime) / sizeof(btime[0]));
void main()

{
	int i;int tt=1;
	
	while(tt)
	{
	
	for(i=1;i<=len;i++)
	{
		
	
	
		if(btime[i]>qtime && btime[i]!=0)
		{
		btime[i]-=qtime;
		timer+=qtime;
		printf("%d\n",btime[i]);
		}
		else
		{
		if(btime[i]!=0)
		{
		comp[t]=i;
		t++;
		timer+=btime[i];
		btime[i]=0;
		printf("%d\n",btime[i]);
		
		}
		}
	}printf("timer is %d\n",timer);
	tt=check();
	
	
	}

	for ( i=1; i<len; i++)
	{
	printf("P%d\n",comp[i]);
	
	}
printf("\n\n%d\n",timer);
}

int check()
{
	int i,k=0;
	for ( i=1; i<=len-1; i++)
	{	
		if(btime[i]!=0)
		{
		k=1;
		
		}
		
	}
		return k;
	
}
	


	
	
		
		
		
	
	
