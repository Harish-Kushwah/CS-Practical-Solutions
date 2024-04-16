package sem6.Java.practicals.slip14;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.*;
import java.util.List;

class SearchThread extends Thread {
    private String searchString;
    private File file;

    public SearchThread(String searchString, File file) {
        this.searchString = searchString;
        this.file = file;
    }

    @Override
    public void run() {
        try {
            BufferedReader reader = new BufferedReader(new FileReader(file));
            String line;
            int lineNumber = 0;
            while ((line = reader.readLine()) != null) {
                lineNumber++;
                if (line.contains(searchString)) {
                    System.out.println("Found '" + searchString + "' in file: " + file.getName() + " at line " + lineNumber);
                }
            }
            reader.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

public class Ex1Method2 {
    public static void main(String[] args) {
      
        Scanner scan = new Scanner(System.in);

        System.out.println("Enter what you want to search :");
        String searchString = scan.nextLine();
        File currentFolder = new File("C://Users//haris//Desktop//TYBCS//CS-Practical-Solutions//sem6//Java//practicals//slip14");
        File[] files = currentFolder.listFiles();

        List<SearchThread> threads = new ArrayList<>();

        if (files != null) {
            for (File file : files) {
              
                if (file.isFile() && file.getName().endsWith(".txt")) {
                    SearchThread thread = new SearchThread(searchString, file);
                    threads.add(thread);
                    thread.start();
                }
            }
        }

        for (SearchThread thread : threads) {
            try {
                thread.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
