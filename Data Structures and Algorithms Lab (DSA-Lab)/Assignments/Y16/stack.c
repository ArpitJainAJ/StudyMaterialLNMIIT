#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};
struct node *create() 
{
	struct node *ptr;
	ptr=(struct node*)malloc(sizeof(struct node ));
	ptr->data=0;
	ptr->next=NULL;
	return ptr;
} 
void insert(int data, struct node* ptr)
{
	struct node* nptr;
	nptr=(struct node*)malloc(sizeof(struct node));
	nptr->data=data;
	ptr->data++;
	nptr->next=ptr->next;
	ptr->next=nptr;
}
void display(struct node* ptr)
{
	printf("\nThe stack is\n");
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
		printf("%d->",ptr->data);
	}printf("NULLL\n\n");
}
void delete(struct node* ptr)
{
	struct node* tptr;
	tptr=ptr->next;
	ptr->data-=1;
	if(ptr->next!=NULL)
	ptr->next=ptr->next->next;
	free(tptr);
}

void main()
{
	int data,c;
	struct node *head;
	head=create();
	do{
		printf("1. Push 2. Pop 3. Disp 0. Exit\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:printf("Enter data to be stacked\n");scanf("%d",&data);
					insert(data,head);
					display(head);break;
			case 2:delete(head);display(head);break;
			case 3:display(head);break;
			default: if(c!=0)
				  printf("Enter valid option\n");break;
		};
	}while(c!=0);
}
