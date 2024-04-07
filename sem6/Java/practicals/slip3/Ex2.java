package sem6.Java.practicals.slip3;
/**
 * 2. Write a Java program to create LinkedList of String objects and perform the following:
i. Add element at the end of the list
ii. Delete first element of the list
iii. Display the contents of list in reverse order
 */

import java.util.*;
public class Ex2 {

    public static void main(String[] args) {
        LinkedList<String> list = new LinkedList<>();

        
       
        list.add("Harish");
        list.add("Rahul");
      
        list.addLast("Pratik");
      
        list.removeFirst();
        Iterator it =  list.descendingIterator();
      
        while(it.hasNext()){
        System.out.println(it.next());
       }

    }
}
