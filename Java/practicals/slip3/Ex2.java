package practicals.slip3;
/*
 * Q2)  Define  a  class  patient  (patient_name,  patient_age,  patient_oxy_level,patient_HRCT_report). 
   Create  an  object  of  patient.  Handle  appropriate  exception  while  patient  oxygen  level  less  than 
   95% and HRCT scan report greater than 10, then throw user defined Exception “Patient is Covid 
   Positive(+) and Need to Hospitalized” otherwise display its information.
 */

import java.util.Scanner;

class CovidPatientException extends Exception {
    public CovidPatientException(String message) {
        super(message);
    }
}

class Patient {
    String name;
    int age;
    float oxy_level;
    float HRCT_report;

    public Patient(String name, int age, float oxy_level, float HRCT_report) {
        this.name = name;
        this.age = age;
        this.oxy_level = oxy_level;
        this.HRCT_report = HRCT_report;
    }

    public void showPatientDetails() {
        System.out.println("Name :" + this.name);
        System.out.println("Age :" + this.age);
        System.out.println("Oxygen level :" + this.oxy_level);
        System.out.println("HRCT Report :" + this.HRCT_report);
    }

}

public class Ex2 {
    public static void main(String[] args) {

        System.out.println("Enter patient details :");
        Scanner scan = new Scanner(System.in);

        System.out.print("Enter name :");
        String name = scan.nextLine();

        System.out.print("Enter Age :");
        int age = scan.nextInt();

        System.out.print("Enter Oxygen level :");
        float oxy_level = scan.nextFloat();

        System.out.print("Enter HRCT Report :");
        float HRCT_report = scan.nextFloat();

        scan.close();
        try {

            Patient patient = new Patient(name, age, oxy_level, HRCT_report);

            if (patient.oxy_level < 95 && patient.HRCT_report < 10) {
                throw new CovidPatientException("Patient is covid +ve");
            } else {
                patient.showPatientDetails();
            }

        } catch (CovidPatientException cp) {
            System.out.println(cp.getMessage());
        }

    }

}
