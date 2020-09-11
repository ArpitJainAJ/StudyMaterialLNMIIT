#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*front=NULL, *rear=NULL;

void insert(int);
void delete();
void display();

int main()
{
	int choice, value;
	
	while(1)
	{
		printf("\nOPERATION MENU\n1. Insert\n2. Delete\n3. Display\n4. Exit\n\n");
		
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:	printf("Enter value:  ");
					scanf("%d",&value);
					insert(value);
					display();
					break;
					
			case 2:	delete();
					break;
					
			case 3: display();
					break;
					
			case 4: break;
			
			default: printf("\nPlease enter a correct value.\n");
			
		}	
	}
}

void insert(int value)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	
	newnode->data=value;
	newnode->next=NULL;
	
	if(front==NULL)	
		front=rear=newnode;
	else
	{	
		rear->next=newnode;
		rear=newnode;
	}
}	
	
void delete()
{
	if(front==NULL)
		printf("Queue is empty\n");
	else
	{
		struct node* temp=front;
		front=front->next;
		printf("\nDeleted element= %d",temp->data);
		free(temp);
	}
}

void display()
{
	if(front==NULL)
	printf("Queue is empty.\n");
	
	else
	{
	struct node *temp=front;
	while(temp->next!=NULL)
	{
		printf("%d-->",temp->data);
		temp=temp->next;
	}
	printf("%d-->NULL\n",temp->data);
	}
}							
			
		 
