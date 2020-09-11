#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
  char data;
  struct stack*link;
};
struct stack*top=NULL;

void push(int);
char pop();
void conv(char [],char []);
int prec(char );
char peep();


int main()
{	
	int i,n,m;
	char infx[100],pos[100],rev[100],final[100];
	printf("\nEnter an Arithmetic exp. : ");
	scanf("%s",infx);
	
	strcpy(rev,infx);
	m=strlen(rev);
	
	for(i=0;i<m;i++)		//reverse the string
	{
		rev[i]=infx[m-i-1];
	}
			
	for(i=0;i<m;i++)		//reverse the brackets
	{
		if(rev[i]=='(')
			rev[i]=')';
		else
		if(rev[i]==')')
			rev[i]='(';
	}
	
	for(i=0;i<m;i++)	//print the reversed string
	{
		printf("%c",rev[i]);	
	}
	printf("\n");

	
	conv(rev,pos);		//call the function
	
	n=strlen(pos);
	
	for(i=0;i<n;i++)		//reverse the string
	{
		final[i]=pos[n-i-1];
	}
	
	
	for(i=0;i<n;i++)		// print the final answer
	{
		printf("%c",final[i]);	
	}
	printf("\n");

return 0;
}

void push(int val)
{	struct stack*p;
	p=(struct stack*)malloc(sizeof(struct stack));
	p->data=val;
	p->link=top;
	top=p;
}

char peep()
{
	char x=pop();
	push(x);
	return x;
}

char pop()
{	char w;
	struct stack*l;
	l=top;
	w=l->data;
	top=top->link;
	free(l);
	return (w);
}

void conv(char in[100],char pos[100])
{	
	int j=0,i=0,x;
	char ch;
	while((ch=in[i++])!='\0')
	{
		if(ch>='0'&&ch<='9')
			{pos[j++]=ch;}
		else
			if(ch=='(')
				push(ch);
			else
				if(ch==')')
				{
					while((x=pop())!='(')
						pos[j++]=x;

				}
				else
				{       if(top!=NULL)
					{	while(prec(x=peep()) >= prec(ch) )
						{	
							x=pop();
							pos[j++]=x;
							if(top==NULL)
								break;
						}
					}
					push(ch);
				}
	
	}
	while(top!=NULL)
		pos[j++]=pop();
	
	pos[j]='\0';

}

int prec(char x)
{	
	
	switch(x)
	{
		case '+': 
		case '-': return 1;
		case '*':
		case '/': return 2;
		case '^': return 3;
		case '(': return 0;
		default : return 0;	
	
	}

}
















