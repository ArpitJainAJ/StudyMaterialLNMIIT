import java.util.Scanner;


public class convert implements Stack {
	
	String str="";
	char temp[]=new char[20];
	int top=-1;
	Scanner sc=new Scanner(System.in);	

	public void input() {
		
		str=sc.nextLine();
		conversion(str);
	}

	public void conversion(String s) {
		 
		
		char[] exp = s.toCharArray();
		//System.out.print(exp[0]);
		

		int j=0;int i=0;
		char postfix[]=new char[20];
		char x;
			
			
		while(i<exp.length)
		{	
			if(Character.isLetterOrDigit(exp[i]))
		            postfix[j++]=exp[i];
			
			 else if(exp[i] == '(')
		     {
				 try{
					 push(exp[i]);
				 }
				 catch(Exception e)
				 {
					  System.out.println(e.getMessage());
				 }
		     }
			 else if(exp[i] == ')')
		        {
		            try {
						while((x = pop()) != '(')
postfix[j++]=x;
					} catch (Exception e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
		        }
			 else
		        {
				 try {
		            while(priority(temp[top]) >= priority(exp[i]))
		                postfix[j++]=pop();
				 
		            
						push(exp[i]);
					} 
				 catch (Exception e) {
						
						System.out.println(e.getMessage());
					}
		        }
		         i++;
		}
		    while(top != -1)
		        {
			  try {
				postfix[j++]=pop();
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		        }
			 	
		    i=0;
		    while(i<postfix.length){
		    System.out.println(postfix[i]);
		    i++;
		    }
	}

	public void push(char a) throws Exception {
		if(top==20)
			throw new Exception("Stack overflow");
		temp[++top]=a;		
		
	}

	public char pop() throws Exception{
		
		if(top == -1)					//pop the top element
			throw new Exception("Stack underflow");
			else
	        return temp[top--];
	}
	
	int priority(char x)
	{
	    if(x == '(')					//checking the priority of operands
	        return 0;
	    if(x == '+' || x == '-')
	        return 1;
	    if(x == '*' || x == '/')
	        return 2;
		return 999;
	}
	
	public static void main(String args[])
	{
		convert s= new convert();
		s.input();
	}

	

}
