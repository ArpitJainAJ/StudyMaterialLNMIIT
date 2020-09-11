#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "visitor.h"
void main()
{
   struct visitor visit[100];
   int i=0, pos; 
   int choice;
   char name[50];
   while(1)
   {
       
       printf("\n MAIN MENU");
       printf("\n1. Add a Record of Visitor:");
       printf("\n2. Sort Records on the basis of Name:");
       printf("\n3. Search a Record on the basis of Name:");
       printf("\n4. Display a Visitor Record:");
       printf("\n5. Quit");
       printf("\n1. Enter your choice[1-5]:");
	fflush(stdin);
       scanf(" %d", &choice);
      
       switch(choice)
       {
	  	case 1:    visit[i] = getdata(); i++;
			 
			 break;
				 
	  	
		case 2:    sort_name(visit, i); break;
	  	
		case 3:    printf("\n Enter the Name:");
				scanf(" %[^\n]s",name);
		          // mygetstring(name);
		           pos = search_name(visit, i,name);
		           if(pos>=0)
			         display_record(visit[pos]);
		           else
			         printf("\n This record does not exist:");
		           break;
	   	
		case 4:   printf("\n Enter the Name:");
				 scanf(" %[^\n]s",name);

		           //mygetstring(name);
		           pos = search_name(visit, i,name);
		           if(pos>=0)
			         display_record(visit[pos]);
		           else
			         printf("\n This record does not exist:");
		           break;
		      
	  	case 5:   printf("\n Exiting from the Software.....");
		          printf("\n Press any key to shutdown");
		          getchar();
		          exit(0);
		default:   printf("\n Invalid choice[1-5]:");
      }
     getchar(); 
  }
}


