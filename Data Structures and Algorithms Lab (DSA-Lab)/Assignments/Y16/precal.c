#define SIZE 50            /* Size of Stack */
#include <stdio.h>
#include<string.h>
int s[SIZE];
int top=-1;       /* Global declarations */

push(int elem)
{                       /* Function for PUSH operation */
 s[++top]=elem;
}

int pop()
{                      /* Function for POP operation */
 return(s[top--]);
}

  main()
{                         /* Main Program */
 char infx[50],ch;
 int i=0,op1,op2;
 printf("\n\nRead the Infix Expression ? ");
 scanf("%s",infx);
int l=strlen(infx);
  while(l!=0)
 {ch=infx[--l];
  
  if(isdigit(ch)) push(ch-'0'); /* Push the operand */
  else
  {        /* Operator,pop two  operands */
   
   op1=pop();
   op2=pop();
   switch(ch)
   {
   case '+':push(op1+op2);break;
   case '-':push(op1-op2);break;
   case '*':push(op1*op2);break;
   case '/':push(op1/op2);break;
   }
  }
 }
 printf("\n Given Infix Expn: %s\n",infx);
 printf("\n Result after Evaluation: %d\n",s[top]);
}
