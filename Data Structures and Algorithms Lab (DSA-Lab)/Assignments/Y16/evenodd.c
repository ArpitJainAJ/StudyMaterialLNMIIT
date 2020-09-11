#include <stdio.h>
#include <stdlib.h>
void main()
{
  int val;
  FILE *fn, *feo;

  // To open the file number.txt in Read mode
  fn = fopen("number.txt", "r");
  if(fn == NULL)								// For Robust programming check whether file exist or not
  {
     printf("File does not exist");
     exit(0);
  }
 
 // To open the file even_odd to write modified data 
  feo = fopen("even_odd.txt", "w");
   if(feo == NULL)							// For Robust programming check whether file can be open 
  {
     printf("File could not be created");
     exit(0);
  }


  while(!feof(fn))           // Execute loop till file pointer reach to end of file means no more records available
   {

       fscanf(fn, "%d",&val);
       if(val%2 == 0 && val>=0)
	         fprintf(feo, "%d ", val*10);
       else
	    if(val%2 == 0 && val<0)
		     fprintf(feo, "%d ", val*(-10));
		else
		  if(val%2 !=0 && val>=0)
		     fprintf(feo, "%d ", val+10);     
		  else
		     fprintf(feo, "%d ", val-10);   
   }
   
   
   fclose(fn);     // For robust programming properly close all the files otherwise file may be corrupted 
   fclose(feo);
  
}

