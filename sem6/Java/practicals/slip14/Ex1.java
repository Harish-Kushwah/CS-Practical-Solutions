package sem6.Java.practicals.slip14;

import java.io.*;
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
        while((line = br.readLine())!= null)
        {
            System.out.println(line);
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

        File file = new File("C://Users//haris//Desktop//TYBCS//CS-Practical-Solutions//sem6//Java//practicals//slip14//sample.txt");
        SearchThread searchThread = new SearchThread("hii", file);
        searchThread.start();
    }
}
