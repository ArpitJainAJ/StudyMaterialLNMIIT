import java.util.Scanner;

import hospital.*;


public class Doctest {
	public static void main(String args[])
	{
		Scanner s = new Scanner(System.in);
		Patient patients[]=new Patient[10];
		Patient pt=new Patient();
		Doctor doc[] = new Doctor[10];
		int i=0;char c;
		do
		{
			int option;
			System.out.println("\nMenu: \n\n1.Add a Patient.\n2.Search Patient.");
			option=s.nextInt();
			int id;
			String title;
			switch(option)
			{
				case 1: System.out.println("\nEnter the Patient details\n");
						
						
						
						
								//patients[i]= new Patient();
								System.out.println("\nEnter the PatientId:");
								id = s.nextInt();
								
								System.out.print("\nEnter the Patient Name: ");
								title = s.next();
								
								System.out.println("\nEnter the illness.: ");
								String illness = s.next();
								patients[i] = new Patient(id,title,illness);
							    i++;
							    break;
						
					case 2: System.out.println("\nEnter the Patient ID and Patient name\n");
							
							System.out.println("\nEnter the PatientId:");
							id = s.nextInt();
							
							System.out.print("\nEnter the Patient Name: ");
							title = s.next();
							pt.search(patients,title,id);
							break;
							
					default:System.out.println("!Wrong Option Selected!");
							break;
			}
			
			System.out.println("Would you like to continue? (Y/N) : ");
			c = s.next().charAt(0);
			
		}while(c=='y' || c=='Y');
								
						
						
	}

}
