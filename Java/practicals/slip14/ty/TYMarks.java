package practicals.slip14.ty;

import java.util.Scanner;

public class TYMarks {
    float theory;
    float practical;

    public void inputTyMarks()
    {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter Theory marks :");
        this.theory = scan.nextFloat();

        System.out.print("Enter Practical marks :");
        this.practical = scan.nextFloat();

    }

    public float getTotalTyMarks()
    {
        return this.theory + this.practical;
    }
    
}
