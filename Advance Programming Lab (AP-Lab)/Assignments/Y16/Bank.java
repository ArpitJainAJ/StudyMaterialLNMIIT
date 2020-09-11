 /**** Class Account ***/
import java.util.Scanner;
class Account
{
      private int accno;
      private double balance;
      protected double minbalance;
      
      public Account(int ac, double bal, double minbal)
        {
            accno= ac;
            balance = bal;
            minbalance = minbal;
         }
      protected int getAccno()
        {
            return accno;
        }
      protected double getBalance()
        {
            return balance;
        }
     protected void setBalance(double bal)
        {
            balance = bal;
        }
     protected double getMinBalance()
        {
            return minbalance;
        }
     protected void setMinBalance(int bal)
        {
            minbalance = bal;
        }
}

class SavingAccount extends Account
{
     private double interest;
     static private double rate;
     static int temp = 100;
     public SavingAccount(double bal, double minbal)
       {
         //int accno;
            
           super(generateAccountNumber(), bal,minbal);
           interest =0;
           rate = 4.5;
       }
     private static int generateAccountNumber()
	 {
		  return temp++;
	 }
	 static public double getRate()
	 {
		 return rate;
	 }
    public void deposit(int amt)
     {
          setBalance(super.getBalance()+amt);
     }
    public void withdraw(int amt)
     {
           if(getBalance()-amt >= minbalance)
                 setBalance(getBalance()-amt);
           else
                {
                    System.out.println("Your Balance is less: "+getBalance());
                 }
      }
    public void showBalance()
      {
          System.out.println("Your Balance is: " + getBalance());
      }
    public int getAccno()
      {
          return super.getAccno();
      }
	  public static void modifyRate(double irate)
	  {
		   rate = irate;
	  }
	  public void calInterest()
	  {
		  interest = getBalance()*this.getRate()/100;
		  setBalance(getBalance()+interest);
	  }
	  public void showDetails()
	  {
		  
		  System.out.println("Account Type:  Saving Account");
		  System.out.println("Account No:"+this.getAccno());
		  System.out.println("Balance:   "+super.getBalance());
		  System.out.println("Min Balance: "+super.getMinBalance());
	  }
		  
}
class CurrentAccount extends Account
{

     private double overdraft;
     private double penaltyrate;
     private double creditlimit;
      private double penalty;
     static int temp = 1100;
     public CurrentAccount(double bal, double minbal,double credit)
       {
         //int accno;
            
           super(generateAccountNumber(), bal,minbal);
           creditlimit = credit;
		   overdraft =0;
           penaltyrate = 3.5;
		   penalty=0;
       }
     private static int generateAccountNumber()
	 {
		  return temp++;
	 }
    public void deposit(int amt)
     {
          
        setBalance(super.getBalance()+amt);
        if(getBalance() >=getMinBalance())
               {
                    penalty =  overdraft*penaltyrate;
                    setBalance(super.getBalance()-penalty);
                    overdraft =0;
               }
        else
                overdraft = overdraft-amt+penalty;
}
   public void withdraw(int amt)
     {
      
           if(getBalance()-getMinBalance()>=amt)
		   {
			   setBalance(getBalance()-amt);
			   penalty = 0;
		   }   
		   else
                if(amt<=creditlimit)
				{
                    overdraft = getBalance()+getMinBalance()-amt;
					setBalance(getBalance()-amt);
				}	
				else
				{	
				    System.out.println("Your withdrawl request exceeded credit limit: "+getBalance());
				   	System.out.println("Your credit limit: "+creditlimit);
                }
      }
    public void showBalance()
      {
          System.out.println("Your Balance is: " + getBalance());
      }
    public int getAccno()
      {
          return super.getAccno();
      }
	  public void showDetails()
	  {
		  
		  System.out.println("Account Type:  Current Account");
		  System.out.println("Account No:   "+this.getAccno());
		  System.out.println("Balance:      "+super.getBalance());
		  System.out.println("Min Balance:  "+super.getMinBalance());
		  System.out.println("Credit Limit: "+this.creditlimit);
		  System.out.println("Overdraft:    "+this.overdraft);
		  System.out.println("Penaltyrate:  "+this.penaltyrate);
		  System.out.println("penalty  :    "+this.penalty);
		 		  
	  }
		  
}
/******  Class Bank  ******/
public class Bank
{    
    public static int search(SavingAccount save[], int acno, int size)
      {
          int i;
          for(i=0;i<size;i++)
            if(save[i].getAccno() == acno)
                return i;
          return -1;
      }
     public static int search(CurrentAccount cur[], int acno, int size)
      {
          int i;
          for(i=0;i<size;i++)
            if(cur[i].getAccno() == acno)
                return i;
          return -1;
      } 
        

    public static void main(String[] args)
    {             
        Scanner scan = new Scanner(System.in);
        SavingAccount save[] = new SavingAccount[10];
        CurrentAccount cur[] = new CurrentAccount[5];
        int i=0, j=0, pos,amt,accno;    
        char ch;
        /*  Perform Bank operations  */
        do
        {
            System.out.println("\nLNMIIT Banking System\n");
            System.out.println("1. open new saving account");
            System.out.println("2. open new current account");
            System.out.println("3. deposit in saving account");
            System.out.println("4. deposit in current account");
            System.out.println("5. withdraw from saving account");
            System.out.println("6.  withdraw from current account");       
            System.out.println("7. Show Balance Saving Account");
			System.out.println("8. Show Balance Current Account");
            System.out.println("9. Show Details Saving Account");
            System.out.println("10. Show Details Current Account");
			System.out.println("11. Quit");
     
            int choice = scan.nextInt();            
            switch (choice)
            {
            case 1 : 
                //System.out.println("Enter your details");
                save[i] = new SavingAccount(5000,5000);
				save[i].showDetails();
                //save[i].getData(scan); 
				i++;                  
                break;                          
            case 2 : 
                System.out.println("Enter your details");
                cur[j] = new CurrentAccount(10000,10000,50000);
                cur[j].showDetails();
				j++;
                break;                         
            case 3 : 
                System.out.println("Enter the account no");
                accno = scan.nextInt() ;
                pos = search(save,accno,i);
                if(pos>=0)
                 {
                        System.out.println("Enter the amount to be deposited");
                        amt = scan.nextInt() ;
                        save[pos].deposit(amt);
						
                 }
              else
                 System.out.println("Account does not exist");
                 break;
						
                                                          
            case 4 : 
                System.out.println("Enter the account no");
                accno = scan.nextInt() ;
                pos = search(cur,accno,j);
                if(pos<0)
                 {
                        System.out.println("Account does not exist");
                        break;
                 }
                System.out.println("Enter the amount to be deposited");
                amt = scan.nextInt() ;
                cur[pos].deposit(amt); break;
            case 5 : 
                System.out.println("Enter the account no");
                accno = scan.nextInt() ;
                pos = search(save,accno,i);
                if(pos>=0)
                 {
                        
                System.out.println("Enter the withdrawl amount ");
                amt = scan.nextInt() ;
                save[pos].withdraw(amt);
				 }
				else 
					 System.out.println("Account does not exist");
                        
				 break;
                
            case 6 : 
                System.out.println("Enter the account no");
                accno = scan.nextInt() ;
                pos = search(cur,accno,j);
                if(pos<0)
                 {
                        System.out.println("Account does not exist");
                        break;
                 }
                System.out.println("Enter the withdrawl amount ");
                amt = scan.nextInt() ;
                cur[pos].withdraw(amt); break;
            
            case 7: System.out.println("Enter the account no");
                        accno = scan.nextInt() ;
                        pos = search(save,accno,i);
                if(pos>=0)
                 
					save[pos].showBalance();
				else	
					System.out.println("Account does not exist");
                break;
                 
                
                  
            case 8: System.out.println("Enter the account no");
                accno = scan.nextInt() ;
                pos = search(cur,accno,j);
                if(pos<0)
                 {
                        System.out.println("Account does not exist");
                        break;
                 }
                cur[pos].showBalance(); break;
                
            case 9: System.out.println("Enter the account no");
                        accno = scan.nextInt() ;
                        pos = search(save,accno,i);
                if(pos>=0)
                 
					save[pos].showDetails();
				else	
					System.out.println("Account does not exist");
                break;
			
             case 10: System.out.println("Enter the account no");
                        accno = scan.nextInt() ;
                        pos = search(cur,accno,j);
                if(pos>=0)
                 	   cur[pos].showDetails();
				else	
					System.out.println("Account does not exist");
                break;     
               case 11: System.out.println("Bank Software Closed");System.exit(1);
                default : System.out.println("Wrong Entry \n ");
                
            }
        
           System.out.println("\nDo you want to continue (Type y or n) \n");
            ch = scan.next().charAt(0); // will give the first character of entered string                       
        } while (ch == 'Y'|| ch == 'y');               
    }
}
