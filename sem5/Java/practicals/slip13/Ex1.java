package practicals.slip13;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

/*
 * Q1) Write a program to accept a file name from command prompt, if the file exits then display                       
    number of words and lines in that file.
 */
public class Ex1 {
    public static void main(String[] args) {

        String file_name = args[0];

        File file = new File("practicals/slip13/" + file_name);

        if (file.exists()) {
            int total_words = 0;
            int total_lines = 0;
            FileReader fr;
            try {
                fr = new FileReader(file);
                BufferedReader br = new BufferedReader(fr);

                String line;
                while ((line = br.readLine()) != null) {
                    String words[] = line.split("\\s+");
                    total_words+=words.length;
                    total_lines++;
                }

                System.out.println("Total number of words :" + total_words);
                System.out.println("Total number of Lines :" + total_lines);

                br.close();
                fr.close();
            } catch (IOException e) {

                e.printStackTrace();
            }
          

        } else {
            System.out.println("File not found");
        }
    }
}
