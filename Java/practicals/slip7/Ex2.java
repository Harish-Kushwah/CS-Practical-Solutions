package practicals.slip7;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

/*
 * Q2) Write a program to accept a text file from user and display the contents of a file in  
        reverse order and change its case.
 */
public class Ex2 {
    public static void main(String[] args) {

        System.out.println("Enter file name :");
        Scanner scan = new Scanner(System.in);
        String file_name = scan.nextLine();

        File file = new File("practicals\\slip7\\" + file_name);
        try {

            if (!file.exists()) {
                file.createNewFile();
            }

            FileReader fr = new FileReader(file);
            BufferedReader br = new BufferedReader(fr);
            String line;
            while ((line = br.readLine()) != null) {

                StringBuffer str = new StringBuffer(line.toUpperCase());
                str.reverse();

                System.out.println(str);

            }

        } catch (IOException e) {

            e.printStackTrace();
        }

    }
}
