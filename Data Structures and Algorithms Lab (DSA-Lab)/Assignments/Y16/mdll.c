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
	ptr=malloc(sizeof(struct node*));
	ptr->data=0;
	ptr->next=NULL;
	ptr->prev=NULL;
	return ptr;
};
void insert(int index,int data, struct node* ptr)
{
	if(index<0||index>(ptr->data))
	 {printf("Shit\n");return;}
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
	return 0;
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
	}
}
void main()
{
	int data,ndata,index,c;
	struct node *head, *ptr;
	head=create();
	label:
	printf("1. insert 2. search 3. del 4. disp 5. modif 0. exit\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:	scanf("%d %d",&index,&data);
				insert(index,data,head);break;
		case 2: scanf("%d",&data);
				int x=search(data,head);if(x==0) printf("NOT FOUND!\n");
				else printf("GOT ONE!\n");break;
		case 3: scanf("%d",&index);del(index, head); break;
		case 4: disp(head);break;
		case 5: scanf("%d %d",&data,&ndata);modif(data,ndata,head);break;
		case 0: break;
	}
	if(c!=0)
	goto label;
	printf("All DOne!");
	
}