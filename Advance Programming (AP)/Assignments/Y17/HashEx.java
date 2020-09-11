import java.util.HashSet;
 
public class HashEx {
 
    public static void main(String a[]){
         
        HashSet<Item> lhm = new HashSet<Item>();
        lhm.add(new Hitem("Banana", 20));
        lhm.add(new Hitem("Apple", 40));
        lhm.add(new Hitem("Orange", 30));
        for(Hitem pr:lhm){
            System.out.println(pr);
        }
        Hitem duplicate = new Hitem("Banana", 20);
        System.out.println("inserting duplicate object...");
        lhm.add(duplicate);
        System.out.println("After insertion:");
        for(Hitem pr:lhm){
            System.out.println(pr);
        }
    }
}
 
class Hitem{
     
    private String name;
    private int price;
     
    public Hitem(String name, int price){
        this.name = name;
        this.price = pr;
    }
     
    public int hashCode(){
        System.out.println("In hashcode");
        int hashcode = 0;
        hashcode = price*20;
        hashcode += name.hashCode();
        return hashcode;
    }
     
    public boolean equals(Object obj){
        System.out.println("In equals");
        if (obj instanceof Hitem) {
            Hitem it = (Hitem) obj;
            return (it.name.equals(this.name) && it.price == this.price);
        } else {
            return false;
        }
    }
     
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public int getPrice() {
        return price;
    }
    public void setPrice(int price) {
        this.price = price;
    }
     
    public String toString(){
        return "Name: "+name+"  price: "+price;
    }
}