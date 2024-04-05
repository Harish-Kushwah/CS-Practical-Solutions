package sem6.Java.practicals.slip0;

import java.util.*;

public class Ex1 {
    public static void main(String[] args) {
        int n;
        // System.out.println("Enter n :");
        Scanner scan = new Scanner(System.in);

        // n = scan.nextInt();


        /**
         * set  
         *    hashset
         *    linkedhashset
         *    Treset
         * list 
         *    ArrayList
         *    LinkedList
         *    Vector
         * queue
         *  PriorityQueue
         * 
         * map 
         *   Hashtable
         *   LinkedHashMap
         *    HashMap
         *    TreeMap
         * 
         */
        HashSet<String> set = new HashSet<>();  // no order maintains
        LinkedHashSet<String> link_set = new LinkedHashSet<>();  //maintains order
        TreeSet<String> treeSet = new TreeSet<>(); // sorted set

        ArrayList<String> arr = new ArrayList<>();  // dynamic array
        LinkedList<String> link = new LinkedList<>(); // Linked List
        Vector<String> vector = new Vector<>();

        PriorityQueue<String> queue = new PriorityQueue<>();

        //map
        /*
         * key   value
         * 1       Harish
         * 2       Pratik
         */

        Hashtable<Integer ,String> map = new Hashtable<>();  // No Order Maintains

        LinkedHashMap<Integer,String> l_map = new LinkedHashMap<>(); // Order Maintains

        HashMap<Integer , String> h_map = new HashMap<>();

        TreeMap<Integer,String> t_map = new TreeMap<>();

        String arr1[] = {"aBaba" , "Ac" ,"bK" , "Daba"};
        for (int i = 0; i < arr1.length; i++) {
            System.out.println("Enter Name :");
            String name = arr1[i];
            set.add(name);

            arr.add(name);
            

            link.add(name);

            link_set.add(name);

            treeSet.add(name);

            vector.add(name);

            queue.add(name);

            map.put(i, name);

            l_map.put(i, name);

            h_map.put(i, name);

            t_map.put(i ,name);

            


        }

        System.out.println("Set :" + set);
        System.out.println("Linked Hash Set :" + link_set);
        System.out.println("Tree Set :" + treeSet);


        Collections.sort(arr);
        System.out.println("\nArrayList :" + arr);
        System.out.println("Linked List :" + link);
        System.out.println("Vector :" + vector);

        System.out.println("\nQueue :" + queue);

        System.out.println("\nMap :"  + map);
        System.out.println("Linked hashMap :"  + l_map);
        System.out.println("hashMap :"  + h_map);
        System.out.println("TreeMap :"  + t_map);


        System.out.println("Retrive element from arryalist : " + arr.get(1));

        // arr.set(1, "Harish");

        // arr.remove(1);


        // System.out.println(arr.subList(0, 2));
        System.out.println("Retrive element from arryalist : " + arr.get(1));


        System.out.println("Retrive element from linked list : " + link.get(1));
        System.out.println("Retrive element from linked list : " + vector.get(1));



        int arr2[] = {1,12,3};
      System.out.println(  Arrays.toString(arr2));
      Arrays.sort(arr2);
      System.out.println(  arr2);


    }
}