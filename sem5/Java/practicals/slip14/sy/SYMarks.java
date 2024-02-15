package practicals.slip14.sy;

import java.util.Scanner;

public class SYMarks {
    float computer_total;
    float maths_total;
    float electronic_total;

    public float  getComputerTotal()
    {
        return this.computer_total;
    }
   
    public void inputSyMarks()
    {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter computer total /100 :");
        this.computer_total = scan.nextFloat();

        System.out.print("Enter maths total /100 :");
        this.maths_total = scan.nextFloat();

        System.out.print("Enter electronic total /100 :");
        this.electronic_total = scan.nextFloat();

    }
    public float getTotalSyMarks()
    {
        return this.computer_total + this.maths_total + this.electronic_total;
    }

}
