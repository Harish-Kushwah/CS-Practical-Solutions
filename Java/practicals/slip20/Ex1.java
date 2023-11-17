package practicals.slip20;
/*
 * Q1) Write a Program to illustrate multilevel Inheritance such that country is inherited from 
continent. State is inherited from country. Display the place, state, country and continent
 */
class Continent {
    String continent_name;

    Continent(String continent_name) {
        this.continent_name = continent_name;
    }
}

class Country extends Continent {
    String country_name;

    Country(String country_name, String Continent) {
        super(Continent);
        this.country_name = country_name;
    }

}

class State extends Country {

    String state_name;
    State(String state_name , String country_name ,String continent_name)
    {
        super(country_name, continent_name);
        this.state_name = state_name;
    }

   
}
class Place extends State
{
   String place_name ;
   Place(String place_name , String state_name , String country_name ,String continent_name)
   {
    super(state_name,country_name,continent_name);
    this.place_name = place_name;
   }

    void displayDetails()
    {
        System.out.println("Continent : " + this.continent_name);
        System.out.println("Country : "+ this.country_name);
        System.out.println("State : "+this.state_name);
        System.out.println("Place : "+this.place_name);
    }
}

public class Ex1 {
    public static void main(String[] args) {

        Place p1 = new Place("Malegaon" ,"Maharashtra", "INDIA", "Asia");
        p1.displayDetails();
    }
}