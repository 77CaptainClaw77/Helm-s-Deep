public class Rectangle
{
    double length,width;
    double area;
    String color;
    Rectangle()
    {
        length=0;
        width=0;
        color="";
    }
    double findArea()
    {
        return length*width;
    }
    void setLength(double length)
    {
        this.length=length;   
    }
    void setWidth(double width)
    {
        this.width=width;
    }
    void setColor(String color)
    {
        this.color=color;
    }
}
class ExecRect
{
    static boolean compareRectangles(Rectangle r1, Rectangle r2)
    {
    if(r1.findArea()==r2.findArea() && r1.color.equals(r2.color))
        return true;
    return false;
    }
    public static void main(String[] args) {
        java.util.Scanner sc=new java.util.Scanner(System.in);
        Rectangle r1=new Rectangle();
        String nw="";
        System.out.println("Enter the length of the first rectangle: ");
        r1.setLength(sc.nextInt());
        System.out.println("Enter the width of the first rectangle: ");
        r1.setWidth(sc.nextInt());
        System.out.println("Enter the color of the first rectangle");
        nw=sc.nextLine();
        r1.setColor(sc.nextLine());
        Rectangle r2=new Rectangle();
        System.out.println("Enter the length of the second rectangle: ");
        r2.setLength(sc.nextInt());
        System.out.println("Enter the width of the second rectangle: ");
        r2.setWidth(sc.nextInt());
        System.out.println("Enter the color of the second rectangle");
        nw=sc.nextLine();
        r2.setColor(sc.nextLine());
        if(compareRectangles(r1, r2))
        System.out.println("Matching Rectangles");
        else
        System.out.println("Non matching Rectangle"); 
    }
}