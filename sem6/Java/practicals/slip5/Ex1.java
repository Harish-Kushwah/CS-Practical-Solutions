package sem6.Java.practicals.slip5;
/**
 * 1. Write a Java Program to create the hash table that will maintain the mobile number and
    student name. Display the details of student using Enumeration interface.
 */
import java.util.*;
public class Ex1 {
    public static void main(String[] args) {
        Hashtable<String , String> contact = new Hashtable<>();
        
        contact.put("Harish" , "9239012012");
        contact.put("Pratik" , "2390122321");
        contact.put("Rakesh" , "1020239023");

        Enumeration<String> enm = contact.keys();
        while(enm.hasMoreElements()){
            String key = enm.nextElement();
            System.out.println("Name :" +key+ " Contact : " + contact.get(key));
        }
    }
}
