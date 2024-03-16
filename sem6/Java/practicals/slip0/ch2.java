package sem6.Java.practicals.slip0;


class Addition extends Thread {

    int a , b;
    Addition(int a , int b){
        this.a = a; 
        this.b = b;
    }
    void add(){
        System.out.println(this.a+this.b);
    }

    public void run()
    {
        //    try {
        //    // Thread.sleep(1000);
        // } catch (InterruptedException e) {
          
        // }
         add();
    }
   
}

class Multi extends Thread{
    int a,b;
    Multi(int a,int b){
        this.a = a;
        this.b = b;
    }
    void mult()
    {
        System.out.println(this.a * this.b);
    }


    public void run()
    {
           mult();
    }
}

class Division implements Runnable{
    int a,b;
    Division(int a,int b){
        this.a = a;
        this.b = b;
    }
    void div()
    {
        System.out.println(this.a / this.b);
    }


    public void run()
    {
           div();
    }
}



public class ch2 {

    public static void main(String[] args) {
        Addition a = new Addition(1,3);
        Multi m = new Multi(3,4);

        Division d = new Division(4, 2);
        a.start();
        m.start();

        Thread th = new Thread(d);
        th.start();


        // a.add(1, 3);   // 1
        // m.mult(1, 2);  // 1

        // 2  sequential
        // 1 parallel

        //to achieve multithreading
        // class == Thread  --> extends    --> run(){code}  --> start()
        // interface = Runnable --> implements  --> run(){code}


    }
}
