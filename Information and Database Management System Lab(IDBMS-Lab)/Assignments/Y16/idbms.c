#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 50
struct student
{
  int roll_no;
  char name[size];
  char branch[size];
  int mobile;
};
struct acad_rec
{
  int roll_no;
  char cpi[size];
  char bld_grp[size];
  char dob[size];
  int courses;
};
FILE *fp1, *fp2;
void insert()
{
  struct student rcrd;
  struct acad_rec A_rcrd;
  fp1=fopen("Record.dat", "a");
  fp2=fopen("acad_record.dat", "a");
  if(fp1==NULL)
  {
    printf("file1 does not exists\n");
    return;
  }
  if(fp2==NULL)
  {
    printf("file2 does not exists\n");
    return;
  }
  printf("Enter name\n");
  scanf("%s", rcrd.name);
  fprintf(fp1, "Name =%s\n", rcrd.name);
  printf("enter roll number\n");
  scanf("%d", &rcrd.roll_no);
  fprintf(fp1, "roll number= %d\n", rcrd.roll_no);
  printf("enter branch\n");
  scanf("%s", rcrd.branch);
  fprintf(fp1, "branch= %s\n", rcrd.branch);
  printf("enter mobile number\n");
  scanf("%d", &rcrd.mobile);
  fprintf(fp1, "Mobile Number= %d\n", rcrd.mobile);
fprintf(fp1, "---------------------\n\n\n");
  printf("enter blood group\n");
  scanf("%s", A_rcrd.bld_grp);
  fprintf(fp2, "Blood group= %s\n", A_rcrd.bld_grp);
  printf("enter CPI\n");
  scanf("%s", A_rcrd.cpi);
  fprintf(fp2, "CPI =%s\n", A_rcrd.cpi);
  printf("enter DOB(dd/mm/yyyy)\n");
  scanf("%s", A_rcrd.dob);
  fprintf(fp2, "DOB =%s\n", A_rcrd.dob);
  printf("Enter number of courses\n");
  scanf("%d", &A_rcrd.courses);
  fprintf(fp2, "Courses=%d\n", A_rcrd.courses);
fprintf(fp2, "---------------------\n\n\n");

  fclose(fp1);
  fclose(fp2);
  return;
}
void display()
{
  char ch;
  int choice;
  fp1=fopen("Record.dat", "r");
  fp2=fopen("acad_record.dat", "r");
  printf("-----ACADEMIC DATABASE SYSTEM-----\n");
  printf("1: Display student record\n");
  printf("2: Display academic record\n");
  scanf("%d", &choice);


  if(choice==1)

  {
    while(!feof(fp1))
    {
	ch=getc(fp1);
     	printf("%c",ch);}
    }
  else if(choice==2)
  {
    while(!feof(fp2))
    	{ch=getc(fp2);
        printf("%c",ch);}
  }
  else
    printf("Invalid choice\n");
  return;
}

int main()
{
  int ch;

  do
  {
  	printf("1: Insert record\n");
  	printf("2: Display records\n");
  	printf("3: exit\n");
  	scanf("%d",&ch);
  	switch(ch)
{
	case 1:insert();
		break;
  	case 2:
    		display();
		break;
	case 3: printf("Thank You!");
		break;
	default:
    	printf("invalid input\n");
}
  }while(ch!=3);
}
