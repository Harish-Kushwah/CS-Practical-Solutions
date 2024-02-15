package practicals.slip2;

/*
 *  Q1) Write a program to read the First Name and Last Name of a person, his weight and height using    
 *      command line arguments. Calculate the BMI Index which is defined as the individual's body mass  
 *      divided by the square of their height. 
 * 
 *      (Hint : BMI = Wts. In kgs / (ht)2)
 */
class Person {
    String f_name;
    String l_name;
    float weight;
    float height;
    float BMI;

    public Person(String f_name, String l_name, float weight, float height) {
        this.f_name = f_name;
        this.l_name = l_name;
        this.weight = weight;
        this.height = height;

    }

    public void calculateBMI() {
        this.BMI = this.weight / (this.height * this.height);
    }

    public void showDetails() {
        System.out.println("Name :" + this.f_name + " " + this.l_name);
        System.out.println("Weight :" + this.weight);
        System.out.println("Height :" + this.height);
        System.out.println("BMI :" + this.BMI);
    }
}

public class Ex1 {
    public static void main(String[] args) {
        try{
            
            String f_name = args[0];
            String l_name = args[1];
            float weight = Float.parseFloat(args[2]);
            float height = Float.parseFloat(args[3]);
            Person harry = new Person(f_name, l_name, weight, height);
            harry.calculateBMI();
            harry.showDetails();

        }
        catch(Exception exp)
        {
            System.out.println("Enter valid arguments");
        }
    }
}
