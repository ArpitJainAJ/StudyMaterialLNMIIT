package hospital;

public class Patient {

	int Pid;
	String Pname;
	String illness;
	
	public Patient()
	{
		Pid=0;
		Pname="";
		illness="";
	}
	public Patient(int Pid, String Pname, String illness)
	{
		this.Pid=Pid;
		this.Pname=Pname;
		this.illness=illness;
		
	}
	
	public void search(Patient pt[], String title, int id)
	{
		int i;
		for(i=0;i<10;i++)
			 if(pt[i].Pname.equals(title) || pt[i].Pid==(id)){
				 System.out.println("Record Found\n");
				 System.out.println(pt[i].Pname+"\n"+pt[i].Pid+"\n"+pt[i].illness);
				 break;
			 }
			 else
				 System.out.println("Record NOT Found\n");
	}
}
