package sem6.Java.practicals.slip21;

import java.util.*;

public class Ex1 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter N :");
        int n = scan.nextInt();
        System.out.println("Enter subject Names :");
        LinkedList<String> list = new LinkedList<>();
        for(int i =0; i<n; i++)
        {
            System.out.print("Enter subject :");
            String sub_name = scan.next();
            list.add(sub_name);
        }  
        
        System.out.println("All Subject :");
        ListIterator li = list.listIterator();
        while(li.hasNext()){
            System.out.println(li.next());
        }
    }
}
