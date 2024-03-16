package sem6.Java.practicals.slip4;
/**
 * 2. Write a Java program to store city names and their STD codes using an appropriate
collection and perform following operations:
i. Add a new city and its code (No duplicates)
ii. Remove a city from the collection
iii. Search for a city name and display the code
 */
import java.util.*;

public class Ex2 {

    private static  Hashtable<String,Integer> city = new Hashtable<>();

    public static void addNewCity(){
        Scanner scan = new Scanner(System.in);
      
        System.out.println("Enter City Name :");
        String name = scan.nextLine();

        System.out.println("Enter STD Code :");
        int std = scan.nextInt();

        city.put(name, std);
    }
    public static void removeCity(){
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter city name :");
        String name = scan.nextLine();
        city.remove(name);
        System.out.println("City Removed Successfully");
    }

    public static void getSTDCode(){
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter city name :");
        String name = scan.nextLine();

        System.out.println("STD :" + city.get(name) + " City Name :" + name);
    }
    public static void menu(){
        System.out.println("1.Add new City :");
        System.out.println("2.Remove city from collection :");
        System.out.println("3.Search for city name and get code :");
        System.out.println("4.Exit");
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int ch;
        do{
            menu();
            System.out.println("Enter Choice :");
            ch = scan.nextInt();

            switch (ch){
                case 1:
                    addNewCity();
                    break;
                case 2:
                    removeCity();
                    break;
                case 3:
                    getSTDCode();
                    break;
                case 4:
                    System.out.println("Exit Successfully");
                    break ;

                default:
                    System.out.println("Enter Valid case");
                    break;
            }
            
        }while(ch!=4);     
    }
}
