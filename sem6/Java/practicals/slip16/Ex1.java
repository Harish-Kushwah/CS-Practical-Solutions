package sem6.Java.practicals.slip16;

import java.util.Scanner;
import java.util.TreeSet;

/*
 * 1. Write a java program to create a TreeSet, add some colors (String) and print out the
content of TreeSet in ascending order

NOTE:In ascending order sorting Capital letters(A-Z) will be before the Small Letters(a-z) because the sorting is based on ascii values
 */
public class Ex1 {
    public static void main(String[] args) {
        TreeSet<String> tree = new TreeSet<>();

        // Method 1
        tree.add("Red");
        tree.add("Yellow");
        tree.add("Black");
        tree.add("Pink");
        
        System.out.println(tree);

        //=====================================================
        // Method 2: if you want to take the input from the user
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter how many colors want to add :");
        int n = scan.nextInt();
        for(int i =0; i<n; i++)
        {
            System.out.print("Enter color name :");
            String color_name = scan.next();
            tree.add(color_name);
        }
        System.out.println(tree);
    }

}
