// Structure Date 
struct Date
{
	int dd ;
	int mm;
	int yyyy;
};

// Structure Visitor
struct visitor
{
  char name[50];
  char mobno[20];
  struct Date dov;
  char purpose_of_visit[20];
 };
 
// Function to get any String data
void mygetstring(char n[])
{
   int i=0;
   char ch;
   ch =getchar();
   while(ch!='\n'&& i< sizeof(n))
     {
	     n[i]= ch;
	     i++;
	     ch =getchar();
    }
    n[i]= '\0';
}

// Function to get any visitor details
struct visitor getdata()
{
   
   struct visitor vi;
   printf("\n enter Name:");
	scanf(" %[^\n]s",vi.name);
   //mygetstring(vi.name);
 
   printf("\n enter Mobile number:");
 scanf(" %[^\n]s",vi.mobno);
   //mygetstring(vi.mobno);
 
   printf("\n enter Date of Visit in DD/MM/YYYY Format:");
 
   scanf(" %d %d %d",&vi.dov.dd,&vi.dov.mm,&vi.dov.yyyy);
 
   printf("\n enter Purpose of Visit(personal/ invited guest/official):");
 scanf(" %[^\n]s",vi.purpose_of_visit);
   //mygetstring(vi.purpose_of_visit);
 
   return vi;
	 
}

// Function to sort the Visitor records on the basis of Name
void sort_name(struct visitor x[], int n)
{
      int i,j;
      struct visitor t;
      for(i=0;i<n-1; i++)               // Bubble Sort method followed
	    for(j=0;j<n-1-i; j++)
	      if((strcmp(x[j].name,x[j+1].name))>0)
	      {
		           t = x[j];             // Complete record of Visitor are swapped
		           x[j] = x[j+1];
		           x[j+1] = t;
	      }
}

// Function to Search a Record on the basis of Visitor Name
int search_name(struct visitor y[], int n, char na[])
{
    int i;
    for(i=0;i<n;i++)                      // Linear Search is followed
       if((strcmp(y[i].name, na)) == 0)
	   return i;
    return -1;
}

// Function to Display a Record of Visitor
void display_record(struct visitor t)
{
     printf("\nVisitor Name:%s", t.name);
     printf("\nMobile Number:%s", t.mobno);
     printf("\nDate of Visit:%d/%d/%d", t.dov.dd,t.dov.mm,t.dov.yyyy);
     printf("\nPurpose of Visit:%s", t.purpose_of_visit);
}


