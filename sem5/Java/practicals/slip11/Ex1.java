package practicals.slip11;
/*
 * Q1) Define an interface “Operation” which has method volume( ).Define a constant PI having a value 
3.142 Create a class cylinder which implements this interface (members – radius, height). Create 
one object and calculate the volume.
 */

interface Operation 
{
    float PI = 3.142f;
    public void volume();
}
class Cylinder implements Operation 
{
    float radius , height;

    public Cylinder(float radius , float height)
    {
        this.radius = radius ;
        this.height = height ;
    }
    @Override
    public void volume() {
        float vol  = 2*PI*this.radius*this.radius*this.height;
        System.out.printf("Volume of cylinder is %f", vol);
    }
    
}
public class Ex1 {
    public static void main(String[] args) {
     
        Cylinder cyl = new Cylinder(13f, 23.4f);
        cyl.volume();
    }
}
