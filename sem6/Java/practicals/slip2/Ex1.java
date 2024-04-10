
/**
 * 1. Write a java program to read ‘N’ names of your friends, store it into HashSet and
    display them in ascending order
 */

import java.util.*;;
public class Ex1 {
    public static void main(String[] args) {
        HashSet<String> friends = new HashSet<>();

        Scanner scan = new Scanner(System.in);
        System.out.println("Enter N :");
        int n  = scan.nextInt();

        scan.nextLine();
        for(int i = 0 ; i<n;i++){
            System.out.println("Enter name :");
            String name = scan.nextLine();
            friends.add(name);
        }

        TreeSet<String> tree = new TreeSet<>(friends);
        System.out.println(tree);
        
    }
}
