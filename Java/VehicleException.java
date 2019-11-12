import java.util.Scanner;
class VehicleException extends Exception
{
    String message;
    VehicleException(String vnameA,String vnameB)
    {
	super("Collision between vehicle "+vnameA+" and vehicle "+vnameB);
    }
    VehicleException()
    {
	super("Collision occured");
    }    
}
class Vehicle
{
    String vehicle_name;
    static final int LEFT=0,RIGHT=1;
    int direction;
    Vehicle(String vname,int dir)
    {
	vehicle_name=vname;
	direction=dir;
    }
    void checkCollision(Vehicle v) throws VehicleException
    {
	if(this.direction!=v.direction)
	    throw new VehicleException(this.vehicle_name,v.vehicle_name);
	else
	    System.out.println("No Collision Occurs");
    }
}
class ExecVehicle
{
    public static void main(String args[])
    {
	Vehicle v1,v2;
	String vname;
	int dir;
	Scanner sc=new Scanner(System.in);
	System.out.println("Enter name of first vehicle: ");
	vname=sc.nextLine();
	System.out.println("Enter the direction of first vehicle:\n1.Left\n2.Right");
	dir=sc.nextInt()==1?Vehicle.LEFT:Vehicle.RIGHT;
	v1=new Vehicle(vname,dir);
	System.out.println("Enter name of second vehicle: ");
	vname=sc.nextLine();
	vname=sc.nextLine();
	System.out.println("Enter the direction of second vehicle:\n1.Left\n2.Right");
	dir=sc.nextInt()==1?Vehicle.LEFT:Vehicle.RIGHT;
	v2=new Vehicle(vname,dir);
	try{
	    v1.checkCollision(v2);
	}
	catch(Exception e){
	    System.out.println(e.getMessage());
	    }
    }
}
