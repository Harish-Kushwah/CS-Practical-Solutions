package practicals.slip15;

/*
 * Q1) Accept the names of two files and copy the contents of the first to the second. First file having  
Book name and Author name in file
 */
import java.util.Scanner;
import java.io.*;

public class Ex1 {
    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        System.out.print("Enter first file name :");
        String first_file_name = scan.nextLine();

        System.out.print("Enter second file name :");
        String second_file_name = scan.nextLine();

        try {

            File file1 = new File("Java/practicals/slip15/" + first_file_name);
            File file2 = new File("Java/practicals/slip15/" + second_file_name);

            if (!file1.exists()) {
                file1.createNewFile();
                System.out.println(first_file_name + " Files created successfully");
            }
            if (!file2.exists()) {
                file2.createNewFile();
                System.out.println(second_file_name + " Files created successfully");

            }

            FileReader fr = new FileReader(file1);
            FileWriter fw = new FileWriter(file2);

            BufferedReader br = new BufferedReader(fr);

            String line;
            while ((line = br.readLine()) != null) {
                fw.write(line);
                fw.write("\n");
            }
            System.out.println("Content copied successfully");

            fw.close();
            br.close();
        } catch (IOException exp) {
            System.out.println(exp.getMessage());
        }
        scan.close();

    }
}
