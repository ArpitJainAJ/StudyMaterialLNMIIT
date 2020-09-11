import java.util.Scanner;


public class matrix {
		
		Scanner sc= new Scanner(System.in);
		int arr[][]=new int[3][3];
		int trn[][]=new int[3][3];
		void input()
		{
		System.out.print("Please enter the numbers");
		
		for(int i=0;i<3;i++)
			{
			for(int j=0;j<3;j++)
			{
				arr[i][j]= sc.nextInt();
			}
			}
		}
		void transpose()
		{
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
				trn[i][j]= arr[j][i];
				}
			}
		}
		matrix multiply(matrix w)
		{
			int t= new int[3[3]];

			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					t[i][j]=arr[0][j]*w.arr[i][0];
				}
			
			
			
			
			
			
			
			
		}
		void display()
		{
			System.out.println("The New Matrix Is");
			for(int i=0;i<3;i++)
				{
				for(int j=0;j<3;j++)
				{
				System.out.print(trn[i][j]+"  ");
				}
				System.out.println();
			}
		}
		 public static void main(String args[])
		{
			matrix a1 =new matrix();
			matrix a2 =new matrix();
			a1.input();
			a2.input();
			a1.multiply(a2);
			//a.transpose();
			a.display();
		}
	}
		