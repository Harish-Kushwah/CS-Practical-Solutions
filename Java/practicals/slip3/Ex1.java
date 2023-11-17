package practicals.slip3;
/*
 * Q1) Write a program to accept ‘n’ name of cities from the user and sort them in ascending order.
 */

import java.util.Scanner;

class City 
{
    String name;
    public City(String name )
    {
        this.name = name;
    }
    public static void sort(City cities[] , int n)
    {
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(cities[j].name.compareTo(cities[j+1].name)>=0)
                {
                    City temp = cities[j];
                    cities[j] = cities[j+1];
                    cities[j+1] = temp;
                }
            }
        }
    } 

    public static void showAllCities(City cities[] , int n)
    {
        for(int i=0;i<n;i++)
        {
            System.out.println(cities[i].name);
        }
    }
}
public class Ex1 {
    
    public static void main(String[] args) {
        Scanner scan  = new Scanner(System.in);

        System.out.print("Enter n :");
        int n =scan.nextInt();
        City []cities = new City[n];
        scan.nextLine();
        for(int i=0;i<n;i++)
        {
            System.out.print("Enter name :");
            String name  = scan.nextLine(); 
            cities[i] = new City(name);
        }

        City.sort(cities, n);
        System.out.println("Cities name after sorting :");
        City.showAllCities(cities, n);

        scan.close();
    }
   
}
