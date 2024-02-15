package practicals.slip9;

/*
 * Q1)  Define a “Clock” class that does the following ;                                                          
               a. Accept Hours, Minutes and Seconds 
               b. Check the validity of numbers 
               c. Set the time to AM/PM mode 
          Use the necessary constructors and methods to do the above task
 */
class Clock {
    int hr, min, sec;
    String mode;

    public Clock(int hr, int min, int sec, String mode) {
        this.hr = hr;
        this.min = min;
        this.sec = sec;
        this.mode = mode;
    }

    public Clock(int hr, int min, int sec) {
        this.hr = hr;
        this.min = min;
        this.sec = sec;
    }

    public boolean isValidTime() {
        boolean hr_condition = this.hr >= 1 && this.hr <= 24;
        boolean min_condition = this.min >= 1 && this.min <= 60;
        boolean sec_condition = this.sec >= 1 && this.sec <= 60;
        if (!hr_condition) {
            System.out.println("Enter valid Hours ");
            return false;
        } else if (!min_condition) {
            System.out.println("Enter valid Minutes");
            return false;
        } else if (!sec_condition) {
            System.out.println("Enter valid seconds");
            return false;
        }
        return true;

    }

    public void setMode(String mode) {
        this.mode = mode;
    }

    public void showTime() {
        if (isValidTime()) {
            System.out.print("Time is :" + this.hr + ":" + this.min + ":" + this.sec);
            if(this.mode!=null)
            {
                System.out.println(" "+this.mode);
            }
        }
        
    }

}

public class Ex1 {
    public static void main(String[] args) {
        Clock c1 = new Clock(10, 30, 40,"AM");
        c1.setMode("PM");
        c1.showTime();
    }
}
