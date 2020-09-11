#include<stdio.h>
#include<stdlib.h>

struct node *create();
void insert_node(int,int,struct node *);
int search_first_node(int,struct node *);
void search_all_nodes(int,struct node *);
void del_first_node(int,struct node *); 
void del_all_nodes (int,struct node *);
void modify_first_node(int,int,struct node *);
void modify_all_nodes(int,int,struct node *);
void display_list(struct node *);


struct node
{
	int data;
	struct node *next;
};

struct node *create() 
{
	struct node *ptr;
	ptr=(struct node*)malloc(sizeof(struct node ));
	ptr->data=0;
	ptr->next=NULL;
	return ptr;
} 

int main()
{
	int i,j,k,choice,index,new_data,old_data;
	
	struct node *head,*ptr;
	head=create();
	printf("\n");
	
	do
	{
		printf("Operations menu\n");
		printf("1. Insert a node\n");
		printf("2. Find firstoccurence of a node\n");

		printf("3.  Find all nodes\n");
		printf("4.  Delete first occurence of a node\n");
		printf("5.  Delete all occurences of a node\n");
		printf("6.  Modify first occurence of a node\n");
		printf("7.  Modify all occurences of a node\n");
		printf("8.  Display list\n");
		printf("9.  Exit\n");

		printf("Enter your choice\n");
		scanf("%d",&choice);


		switch(choice)
		{

		case 1 : printf("\nEnter the data and the index of the new node");
				printf("\nIndex:");

				scanf("%d",&index);
				printf("Data:");
				scanf("%d",&new_data);
				insert_node(index,new_data,head);
				display_list(head);
				break;

		case 2 :  printf("\nEnter the data to be searched");

			scanf("%d",&new_data);
			index=search_first_node(new_data,head);
			if(index==-1)
			printf("given data not found:");
			else
			printf("position of the given dat first index is %d\n\n:",index);
			display_list(head);
			break;

		case 3 :printf("\nEnter the data to be searched");
			scanf("%d",&new_data);
			search_all_nodes(new_data,head);
			display_list(head);
			break;

		case 4 :  printf("\nEnter the data to be deleted");
			scanf("%d",&new_data);
			index=search_first_node(new_data,head);
			if(index==-1)
			printf("given data not found:");
			else
			del_first_node(index,head);
			display_list(head);
			break;
			 

		case 5 : printf("\nEnter the data to be deleted");
			scanf("%d",&new_data);
			del_all_nodes(new_data,head);
			display_list(head);
			break;

		case 6 : printf("\nEnter the existing data to be modified");
				scanf("%d",&old_data);
				printf("\nEnter the new data to be inserted");
				scanf("%d",&new_data);
				index=search_first_node(old_data,head);
				if(index==-1)
				{
					printf("given data not found:\n");
					printf("So nothing to modify.\n:");
				}
				else
					modify_first_node(index,new_data,head);

				display_list(head);
				break;

		case 7 : 	printf("\nEnter the existing data to be modified");
				scanf("%d",&old_data);
				printf("\nEnter the new data to be inserted");
				scanf("%d",&new_data);

				modify_all_nodes(old_data,new_data,head);
				display_list(head);
				break;

		case 8 : 	display_list(head);
				break;

		case 9 : 	printf("Thank You\n");
				break;

		default : 	printf("\nEnter a valid choice \n\n");



		}

	}

		while (choice!=9);
return 0;
}




void insert_node(int index,int new_data,struct node *ptr)
{
int i;
 struct node *newptr;
if(index<0 || index>(ptr->data))
	{	
		printf("Invalid index");
		return;
}
	newptr=(struct node*)malloc(sizeof(struct node ));
newptr->data=new_data;

ptr->data=ptr->data+1;
i=0;
while(i<index)
{
	ptr=ptr->next;
	i++;
}
newptr->next=ptr->next;
ptr->next=newptr;
}


int search_first_node(int new_data,struct node *ptr)
{
	int i=1;
	while(ptr->next!=NULL)

	{
		ptr=ptr->next;
		if(ptr->data==new_data)
		return i;
		i++;
	}
return -1;
}


void search_all_nodes(int new_data,struct node *ptr)
{
	int i= 1,j=-1;
	while(ptr->next!=NULL)

	{
		ptr=ptr->next;
		if(ptr->data==new_data)
		{
		j++;
		printf("\nPosition of the given data is  %d\n\n",i);

		}
	i++;
	}
	if(j==-1)
	printf("\nData not foumd in the list\n\n");

}




void del_first_node(int index, struct node *ptr)
{

int i=1;
struct node *tempptr;
ptr->data=ptr->data-1;

while(i<index)
{
	ptr=ptr->next;
	i++;
}
tempptr=ptr->next;
ptr->next=(ptr->next)->next;

free(tempptr);

}


void del_all_nodes(int new_data,struct node *ptr)      //changes
{
	int i=0;
	struct node *tempptr;
	struct node *rootptr;
rootptr=ptr;
while(ptr->next!=NULL)
{
	if((ptr->next)->data==new_data)
	{
		tempptr=ptr->next;
		ptr->next=(ptr->next)->next;
		free(tempptr);
		i++;
	}
	else 
	ptr=ptr->next;
}
rootptr->data=rootptr->data - i;
}




void modify_first_node(int index,int new_data,struct node *ptr)
{
	int i=0;
	
while(i<index)
{
	ptr=ptr->next;
	i++;
}
ptr->data=new_data;
}


void modify_all_nodes(int old_data,int new_data,struct node *ptr)  //changes

{
while(ptr->next!=NULL)
{
	ptr=ptr->next;
	if(ptr->data==old_data)
	ptr->data=new_data;
}
}



void display_list(struct node *ptr)
{
	printf("\nList is...\n");
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
		printf("%d ",ptr->data);
}
printf("NULLL\n\n");
}
































