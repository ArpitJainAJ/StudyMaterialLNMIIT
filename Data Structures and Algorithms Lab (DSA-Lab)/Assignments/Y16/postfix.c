#include<stdio.h>
#include<string.h>
char stack[20];
int top=-1;

void push(char a)
{
	stack[++top]=a;					//push the character into stack
}

char pop()
{
    if(top == -1)					//pop the top element
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '(')					//checking the priority of operands
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}


void main()
{	int j=0;
	 char postfix[20]="" ;
	char exp[20];char *e, x;
	printf("ENTER THE INFIX EXPRESSION..");
	scanf("%s",exp);
	e=exp;
	while(*e!='\0')
{	
	if(isalnum(*e))
            postfix[j++]=*e;
	 else if(*e == '(')
            push(*e);
	 else if(*e == ')')
        {
            while((x = pop()) != '(')
		postfix[j++]=x;
        }
	 else
        {
            while(priority(stack[top]) >= priority(*e))
                postfix[j++]=pop();
		 
            push(*e);
	}
         e++;
}
    	while(top != -1)
        {
	  postfix[j++]=pop();
         
        }
	 	
	j=0;char ch;
	 

	ch=postfix[j];
	while(ch!='\0')
{	
	printf(" %c", (postfix[j++]));
	ch=postfix[j];
}
printf("\n\n THANK YOU!\n"); 
}













