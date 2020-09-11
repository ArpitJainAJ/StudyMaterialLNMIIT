#include<stdio.h>
#include<stdlib.h>
#define size 5
 
int queue[size];
int front=-1,rear=-1;

void insert(int);
void delete();
void display();

 
 

void insert(int value)
{
   if((front == 0 && rear == size - 1) || (front == rear+1))
      printf("\nOverflow! Insertion not possible!!!\n");
   else{
      if(rear == size-1 && front != 0)
	 rear = -1;
      queue[++rear] = value;
      printf("\nInsertion Success!!!\n");
      if(front == -1)
	 front = 0;
   }
}
void delete()
{
   if(front == -1 && rear == -1)
      printf("\nCircular Queue is Empty! Deletion is not possible!!!\n");
   else{
      printf("\nDeleted element : %d\n",queue[front++]);
      if(front == size)
	 front = 0;
      if(front-1 == rear)
	 front = rear = -1;
   }
}
void display()
{
   if(front == -1)
      printf("\nCircular Queue is Empty!!!\n");
   else{
      int i = front;
      printf("\nCircular Queue Elements are : \n");
      if(front <= rear){
	 while(i <= rear)
	    printf("%d  ",queue[i++]);
      }
      else{
	 while(i <= size - 1)
	    printf("%d  ", queue[i++]);
	 i = 0;
	 while(i <= rear)
	    printf("%d  ",queue[i++]);
      }
   }
}

void main()
{
   int choice, value;
    
   while(1){
      printf("\n MENU \n");
      printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice){
	 case 1: printf("\nEnter the value to be insert:  ");
		 scanf("%d",&value);
		 insert(value);
		 display();
		 break;
	 case 2: delete();
		 display();
		 break;
	 case 3: display();
		 break;
	 case 4: exit(0);
	 default: printf("\nPlease select the correct choice!!!\n");
      }
   }
}


