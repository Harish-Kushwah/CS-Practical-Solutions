package sem6.Java.practicals.slip23;

import java.util.*;

/*
 * 2. Write a java program to accept ‘N’ student names through command line, store them
into the appropriate Collection and display them by using Iterator and ListIterator
interface.

  Compile the java program : javac Ex2.java
  Run pass the command line arguments : java Ex2 Raj Mayank Priya Sonu
 */
public class Ex2 {
  public static void main(String[] args) {
    
      int n = args.length;
      ArrayList<String> list = new ArrayList<>();
      for(int i=0; i<n;i++){
         list.add(args[i]);
      }

      System.out.println("Traversing using List Iterator");
      ListIterator list_itr = list.listIterator();
      while(list_itr.hasNext()){
        System.out.println(list_itr.next());
      }


      System.out.println("Traversing using Iterator");
      Iterator itr = list.iterator();
      while (itr.hasNext()) {
        System.out.println(itr.next());
      }

  }   
}
