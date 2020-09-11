#include<stdio.h>
#include<stdlib.h>
int n,j,i;
int *a;

void input()
{
printf("Enter the no of elements\n");

scanf("%d",&n);
a=(int *)malloc(n*sizeof(int));
 
printf("Enter the integers to sort %d\n",n);

for(i=0;i<n;i++)				//input
{
	scanf("%d",a+i);
}
/*for(i=0;i<n;i++)				//display the elements
printf("%d ",*(a+i));
*/
}

void display()
{
 
for(i=0;i<n;i++)				//display the elements
printf("%d ",*(a+i));
 
}

void bubble()
{
for(i=0;i<n;i++)
{	
	for(j=0;j<n-i-1;j++)			//Bubble sort
	{
		if(a[j]>a[j+1])
		{
		int temp=a[j];
		a[j]=a[j+1];
		a[j+1]=temp;
		}
	}
}
display();
}




void insertion_sort()
{
	for(j=1;j<=n;j++)
	{
		for(i=j-1;i>0;i--)
		{
		if(a[i]>a[j])
		{
		int temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		}
		}
	}

}

void main()
{
input();
//bubble();
insertion_sort();
display();
}
 


