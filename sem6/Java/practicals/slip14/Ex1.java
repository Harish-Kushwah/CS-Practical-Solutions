package sem6.Java.practicals.slip14;
/*
 * 1. Write a Java program for a simple search engine. Accept a string to be searched. Search
the string in all text files in the current folder. Use a separate thread for each file. The
result should display the filename and line number where the string is found. 
 */
import java.io.*;
import java.util.Scanner;
class SearchThread extends Thread 
{
    String searchString;
    File file;
    SearchThread(String searchString ,File file)
    {
        this.searchString = searchString;
        this.file = file;
    }

    public void run()
    {
        try{
        BufferedReader br = new BufferedReader(new FileReader(this.file));

        String line;
        int lineNum =0;
        while((line = br.readLine())!= null)
        {   
            lineNum++;
            if(line.contains(searchString)){
                System.out.println("found '" + searchString + "' in file :" + file.getName() + " On line num "+ lineNum);
            }
           
        }
      }
      catch(Exception exp)
      {
        exp.printStackTrace();
      }
    }
}
public class Ex1 {
    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        System.out.print("Enter search string :");
        String searchString  = scan.nextLine();

        File currentFolder = new File("C://Users//haris//Desktop//TYBCS//CS-Practical-Solutions//sem6//Java//practicals//slip14");
        File[] files = currentFolder.listFiles();

        if(files!=null)
        {
            for(File file : files)
            {
                if(file.isFile() && file.getName().endsWith(".txt")){
                    SearchThread thread = new SearchThread(searchString, file);
                    thread.start();
                }
            }
        }
    }
}
