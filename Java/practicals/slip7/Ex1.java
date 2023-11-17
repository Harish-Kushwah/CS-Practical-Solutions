package practicals.slip7;
/*
 * Q1) Design a class for Bank. Bank Class should support following operations;   
                   a. Deposit a certain amount into an account 
                   b. Withdraw a certain amount from an account 
                   c. Return a Balance value specifying the amount with details
 */

class Bank 
{
    String bank_name;
    float balance;
    public Bank(String bank_name , float balance)
    {
        this.bank_name = bank_name;
        this.balance = balance;
    }

    public void deposit(float amount)
    {
        this.balance+=amount;
        System.out.println("Amount deposit successful");
    }
    public void withdraw(float amount)
    {
        if(this.balance >= amount)
        {
            this.balance -=amount;
        }
        System.out.println("Amount withdraw successful");
    }
    public void showDetails()
    {
        System.out.println("Bank name :" + this.bank_name);
        System.out.println("Current Balance :Rs." + this.balance );
        
    }

}
public class Ex1 {
 public static void main(String[] args) {
    Bank HDFC  = new Bank("HDFC", 0);
    HDFC.deposit(12000);
    HDFC.showDetails();
    HDFC.withdraw(2000);
    HDFC.showDetails();
 }   
}
