
import java.text.*;
import java.util.*;  

  
public class DigitalClock extends Thread
{
  
   Thread t = null;  
   int hours=0, minutes=0, seconds=0;  
   String timeString = "";  
  
    
  public void run() {  
     
         while (true) {  
  
            Calendar cal = Calendar.getInstance();  
            hours = cal.get( Calendar.HOUR_OF_DAY );  
            if ( hours > 12 ) hours -= 12;  
            minutes = cal.get( Calendar.MINUTE );  
            seconds = cal.get( Calendar.SECOND );  
  
            SimpleDateFormat formatter = new SimpleDateFormat("hh:mm:ss");  
            Date date = cal.getTime();  
            timeString = formatter.format( date );   
            System.out.println(timeString);

             
            try {
				Thread.sleep( 1000 );
			} catch (InterruptedException e) {
				e.printStackTrace();
			}  // interval given in milliseconds  
         }  
   }
 
  
  public static void main(String args[])
  {
  	DigitalClock d1 = new DigitalClock();
  	d1.start();
  } 
}



