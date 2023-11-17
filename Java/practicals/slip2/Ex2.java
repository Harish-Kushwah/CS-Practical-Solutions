package practicals.slip2;
/*
 * Q2)  Define  a  class  CricketPlayer  (name,no_of_innings,no_of_times_notout,  totatruns,  bat_avg).    
*  Create  an  array  of  n  player  objects  .Calculate  the  batting  average  for  each  player  using  static 
*  method avg(). Define a static sort method which sorts the array on the basis of average. Display 
*  the player details in sorted order.
 */

import java.util.Scanner;

class CricketPlayer 
{
    String name;
    int no_of_innings;
    int no_of_times_notout;
    int totalruns;
    float bat_avg;

    public CricketPlayer(String name , int no_of_innings , int no_of_times_notout , int totalruns , float  bat_avg)
    {
        this.name  = name;
        this.no_of_innings = no_of_innings ;
        this.no_of_times_notout = no_of_times_notout;
        this.totalruns = totalruns;
        this.bat_avg = bat_avg;
    }
    public static void avg(CricketPlayer players[] , int n)
    {
        for(int i=0;i<n;i++)
        {
           players[i].bat_avg  = players[i].totalruns / (players[i].no_of_innings  - players[i].no_of_times_notout);
        }
    }

    public static void sort(CricketPlayer player[] , int n)
    {
        for(int i=0;i<n-1;i++)
        {
           for(int j = 0 ; j<n-i-1;j++)
           {
            if(player[j].bat_avg < player[j+1].bat_avg)
            {
                CricketPlayer temp = player[j];
                player[j] = player[j+1];
                player[j+1] = temp;
            }
           }
        }
    }
    public void showDetails()
    {
        System.out.println("Name :" + this.name);
        System.out.println("No of Innings :" + this.no_of_innings );
        System.out.println("No of times not out :"  + this.no_of_times_notout);
        System.out.println("Total Runs :" + this.totalruns);
        System.out.println("Batting average :" +this.bat_avg);
    }
    public static void showAllDetails(CricketPlayer player[] , int n)
    {
        for(int i=0;i<n;i++)
        {
           player[i].showDetails();
        }
    }
}
public class Ex2 {
    public static void main(String[] args) {
        
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter total number of players :");
        int total_player = scan.nextInt();
        

        CricketPlayer []players = new CricketPlayer[total_player];
        for(int i=0;i<total_player;i++)
        {
            scan.nextLine();
            System.out.print("Enter name :");
            String name = scan.nextLine();

            System.out.print("Enter no of innings :");
            int no_of_innings = scan.nextInt();

            System.out.print("Enter no of times not out :");
            int no_of_times_notout = scan.nextInt();

            System.out.print("Enter total runs :");
            int totalruns = scan.nextInt();

           players[i] = new CricketPlayer(name, no_of_innings, no_of_times_notout, totalruns, totalruns);
        }

        CricketPlayer.avg(players , total_player);

        CricketPlayer.sort(players, total_player);

        CricketPlayer.showAllDetails(players, total_player);

        scan.close();

    }
}
