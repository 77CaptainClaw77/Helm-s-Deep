import java.util.Scanner;
public class Circle
{
    float radius;
    Circle()
    {
        radius=0.0f;        
    }
    Circle(float r)
    {
        radius=r;
    }
    float getArea()
    {
        return (float)(Math.PI*radius*radius);
    }
}
class CircArea{
    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the radius of the circle: ");
        Circle circ=new Circle(sc.nextFloat()); 
        System.out.format("The area of the circle with radius %.2f is %.4f\n", circ.radius, circ.getArea());
        sc.close();
    }
}

