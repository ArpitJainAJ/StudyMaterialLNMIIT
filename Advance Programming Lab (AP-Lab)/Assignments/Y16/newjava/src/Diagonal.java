
import java.io.*;
import java.util.*;

public class Diagonal {
	
	
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
	void display()
	{
		for(int i=0;i<3;i++)
			{
			for(int j=0;j<3;j++)
			{
			System.out.println(trn[i][j]+"  ");
			}
			System.out.println();
		}
	}
	void main()
	{
		input();
		transpose();
		display();
	}
}
	