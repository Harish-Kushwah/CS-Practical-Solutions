package practicals.slip17;

/*
 * Q1) Design a Super class Customer (name, phone-number). Derive a class Depositor(accno , balance)  
       from Customer. Again, derive a class Borrower (loan-no, loan-amt) from Depositor. Write  
       necessary member functions to read and display the details of ‘n’customers
 */
import java.util.Scanner;

class Customer {
    String name;
    String phone_number;

    public Customer(String name, String phone_number) {
        this.name = name;
        this.phone_number = phone_number;
    }
}

class Depositor extends Customer {
    String acc_no;
    float balance;

    public Depositor(String name, String phone_number) {
        super(name, phone_number);

    }

    void setAccountNumber(String acc_no) {
        this.acc_no = acc_no;
    }

    void setBalance(float balance) {
        this.balance = balance;
    }

    public void showDepositorDetails() {
        System.out.println("Name :" + this.name);
        System.out.println("Phone number:" + this.phone_number);
        System.out.println("Account number :" + this.acc_no);
        System.out.println("Balance :" + this.balance);
    }

    public static void showAllDepositor(Depositor[] depositors, int total_depositor) {
        System.out.println("\n__________All Depositor Customer___________-");
        for (int i = 0; i < total_depositor; i++) {
            depositors[i].showDepositorDetails();
        }

    }

}

class Borrower extends Depositor {

    String loan_no;
    float loan_amt;

    public Borrower(String name, String phone_number) {
        super(name, phone_number);

    }

    void setLoanNumber(String loan_no) {
        this.loan_no = loan_no;
    }

    void setLoanAmt(float loan_amt) {
        this.loan_amt = loan_amt;
    }

    public void showBorrowerDetails() {
        System.out.println("Name :" + this.name);
        System.out.println("Phone number:" + this.phone_number);
        System.out.println("Account number :" + this.acc_no);
        System.out.println("Balance :" + this.balance);
        System.out.println("Loan number :" + this.loan_no);
        System.out.println("Loan amount :" + this.loan_amt);
    }

    public static void showAllBorrower(Borrower[] borrowers, int total_borrower) {
        System.out.println("\n__________All Borrower Customer___________-");
        for (int i = 0; i < total_borrower; i++) {
            borrowers[i].showBorrowerDetails();
        }

    }

}

public class Ex1 {
    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        System.out.print("Enter total number of Customers :");
        int n = scan.nextInt();

        Borrower[] borrower = new Borrower[n];
        Depositor[] depositor = new Depositor[n];
        int total_depositor = 0;
        int total_borrower = 0;

        for (int i = 0; i < n; i++) {
            scan.nextLine();
            System.out.print("Enter customer type[depositor/borrower] :");
            String customer_type = scan.nextLine();

            System.out.print("Enter customer name :");
            String name = scan.nextLine();
            System.out.print("Enter Phone number :");
            String phone_number = scan.nextLine();

            if (customer_type.equalsIgnoreCase("depositor")) {

                System.out.print("Enter account number :");
                String acc_number = scan.nextLine();

                System.out.print("Enter balance :");
                float balance = scan.nextFloat();

                depositor[total_depositor] = new Depositor(name, phone_number);
                depositor[total_depositor].setAccountNumber(acc_number);
                depositor[total_depositor].setBalance(balance);
                total_depositor++;
            } else {
                System.out.print("Enter loan number :");
                String loan_number = scan.nextLine();

                System.out.print("Enter loan amount :");
                float loan_amount = scan.nextFloat();

                borrower[total_borrower] = new Borrower(name, phone_number);
                borrower[total_borrower].setLoanNumber(loan_number);
                borrower[total_borrower].setLoanAmt(loan_amount);
                total_borrower++;
            }

        }

        Borrower.showAllBorrower(borrower, total_borrower);
        Depositor.showAllDepositor(depositor, total_depositor);

    }
}
