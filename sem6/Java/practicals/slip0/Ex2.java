package sem6.Java.practicals.slip0;

import java.util.*;;
public class Ex2 {
    public static void main(String[] args) {
        
        Hashtable<Integer , String> city = new Hashtable<>();
        

        city.put(123, "Malegaon");
        city.put(23, "Pune");
        city.put(20, "Dhule");

     
        System.out.println(city.get(123));
        city.remove(123);

        System.out.println(city);

    }
}
