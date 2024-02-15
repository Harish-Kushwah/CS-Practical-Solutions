package practicals.slip8;
/*
 * Q1)  Create a class Sphere, to calculate the volume and surface area of sphere. 
         (Hint : Surface area=4*3.14(r*r), Volume=(4/3)3.14(r*r*r)) 
 */
class Sphere 
{
    float radius;
    float area;
    float volume;
    final float PI = 3.14f;

    public Sphere(float radius)
    {
        this.radius = radius;
    }

    public void find_area()
    {
        this.area = 4*PI*(this.radius*this.radius);
    }
    public void find_volume()
    {
        this.volume = (4/3)*PI*(this.radius*this.radius*this.radius);
    }
    public void showDetails()
    {
        System.out.println("Radius of sphere :"+ this.radius);
        System.out.println("Area of sphere :"+this.area);
        System.out.println("Volume :"+this.volume);
    }
}
public class Ex1 {
    public static void main(String[] args) {
        Sphere s1 = new Sphere(23.4f);
        s1.find_area();
        s1.find_volume();
        s1.showDetails();
    }
}
