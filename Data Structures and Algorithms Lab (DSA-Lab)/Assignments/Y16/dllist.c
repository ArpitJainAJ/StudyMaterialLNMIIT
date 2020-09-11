#include<stdio.h>
#include<stdlib.h>


struct node
{
	int data;
	struct node* next;
	struct node* prev;
};
struct node* create()
{
	struct node* ptr;
	ptr=(struct node*)malloc(sizeof(struct node ));
	ptr->data=0;
	ptr->next=NULL;
	ptr->prev=NULL;
	return ptr;
};
void insert(int index,int data, struct node* ptr)
{
	if(index<0||index>(ptr->data))
	 {printf("Invalid index\n");return;}
	int i;
	struct node* nptr;
	nptr=(struct node*)malloc(sizeof(struct node*));
	nptr->data=data;
	ptr->data+=1;
	i=0;
	while(i<index)
	{
		ptr=ptr->next;
		i++;
	}
	nptr->next=ptr->next;
	ptr->next=nptr;
	if(nptr->next!=NULL)
		(nptr->next)->prev=nptr;
	nptr->prev=ptr;
}
int search(int data,struct node *ptr)
{
	int i=1;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
		if(ptr->data==data)
		return i;
		i++;
	}
	return -1;
}
void del(int index,struct node *ptr)
{	int i;
	struct node *tptr;
	ptr->data-=1;
	while(i<index)
	{
		ptr=ptr->next;
		i++;
	}
	tptr=ptr->next;
	ptr->next=(ptr->next)->next;
	if(ptr->next!=NULL)
		(ptr->next)->prev=ptr;
	free(tptr);
}
void modif(int data,int ndata,struct node *ptr)
{
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
		if(ptr->data==data)
		{ptr->data=ndata;return;}
	}return;
}
void disp(struct node *ptr)
{
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
		printf("%d->",ptr->data);
	}printf("NULLL\n\n");
}
void main()
{
	int data,ndata,index,c;
	struct node *head, *ptr;
	head=create();
	label:
	printf(" 1. insert\n 2. search\n 3. del\n 4. disp\n 5. modif\n 0. exit\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:	printf("\nEnter the data and the index of the new node");
				printf("\nIndex:");

				scanf("%d",&index);
				printf("\nData:");
				scanf("%d",&data);
				insert(index,data,head);
				disp(head);
				break;
		case 2: scanf("%d",&data);
				int x=search(data,head);if(x==-1) 
				printf("NOT FOUND!\n");
				else 	
				printf("GOT ONE!\n");disp(head);break;
		case 3: scanf("%d",&index);del(index, head);disp(head); break;
		case 4: disp(head);break;
		case 5: 	printf("\nEnter the data to be modified");
				 

				scanf("%d",&data);
				printf("\nEnter the new data :");
				scanf("%d",&ndata); modif(data,ndata,head);disp(head);break;
		case 0: break;
	}
	if(c!=0)
	goto label;
	printf("\nThank You!\n");
}
