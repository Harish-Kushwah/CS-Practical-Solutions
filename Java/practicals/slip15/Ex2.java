package practicals.slip15;
/*
 * Q2) Write a program to  define a class Account having members custname, accno. Define default  
        and parameterized constructor. Create a subclass called SavingAccount with member savingbal,   
        minbal. Create a derived class AccountDetail that extends the class SavingAccount with    
        members, depositamt and withdrawalamt. Write a appropriate method to display customer  
        details
 */

class Account 
{
    String cust_name;
    String acc_no;
    public Account(String cust_name , String acc_no)
    {
        this.cust_name = cust_name;
        this.acc_no = acc_no;
    }
}
class SavingAccount extends Account 
{
    float saving_bal;
    float min_bal;
    public SavingAccount(String cust_name, String acc_no) {
        super(cust_name, acc_no);
    }
    public void setSavingBalance(float saving_bal)
    {
        this.saving_bal = saving_bal;
    }

    public void setMinimumBalance()
    {
       this.min_bal = 1000;
    }
    
}
class AccountDetails extends SavingAccount 
{

    float deposit_amount;
    float withdraw_amount;
    public AccountDetails(String cust_name, String acc_no) {
        super(cust_name, acc_no);
        
    }

    public void depositAmount(float amount)
    {
      this.deposit_amount = amount;
      this.saving_bal +=this.deposit_amount;
      System.out.println("Amount deposit successful");
    }

    public void withDrawAmount(float amount)
    {
        float remaining_amount = this.saving_bal - amount;
        if( amount<=this.saving_bal && remaining_amount >= this.min_bal)
        {
           this.saving_bal-=amount;
            System.out.println("Amount Withdraw successful");
        }
        else{
            System.out.println("Unable to withdraw amount,maintain minimum balance");
        }
    }
    public void showAccountDetails()
    {
        System.out.println("Name :" + this.cust_name);
        System.out.println("Account no :" + this.acc_no);
        System.out.println("Total saving balance :"+this.saving_bal);
    }

    
}
public class Ex2 {
    public static void main(String[] args) {
     
        AccountDetails account = new AccountDetails("Harry", "AB1234569");
        account.depositAmount(900);
        account.showAccountDetails();
        account.withDrawAmount(102003);
        account.showAccountDetails();
    }
}
