import java.util.Scanner;
class Call
{
    float cost,duration;
    float computeCost()
    {
	return cost*duration;
    }
    Call(float cost,float duration)
    {
	this.cost=cost;
	this.duration=duration;
    }
    
}
class LightningCall extends Call
{
    float urgency_charge,connection_charge;
    LightningCall(float cost,float duration,float connection_charge,float urgency_charge)
    {
	super(cost,duration);
	this.connection_charge=connection_charge;
	this.urgency_charge=urgency_charge;
    }
    float computeCost()
    {
	return cost*duration+connection_charge+urgency_charge;
    }
}
class UrgentCall extends Call
{
    float urgency_charge;
    UrgentCall(float cost,float duration,float urgency_charge)
    {
	super(cost,duration);
	this.urgency_charge=urgency_charge;
    }
    float computeCost()
    {
	return cost*duration+urgency_charge;
    }
}
class TrunkCaller
{
    public static void main(String args[])
    {
	Call c;
	Scanner sc=new Scanner(System.in);
	System.out.println("Enter the cost per minute");
	float cost=sc.nextFloat();
	System.out.println("Enter the duration of the call in minutes");
	float dur=sc.nextFloat();
	System.out.println("Enter the type of call:-\n1.Ordinary Call\n2.Urgent Call\n3.Lightning Call");
	int ch=sc.nextInt();
	if(ch==1)
		c=new Call(cost,dur);
	else
	    {
		System.out.println("Enter the urgency charge");
		float uc=sc.nextFloat();
		if(ch==2)
		    c=new UrgentCall(cost,dur,uc);
		else
		    {
		    System.out.println("Enter the connection charge");
		    float cc=sc.nextFloat();
		    c=new LightningCall(cost,dur,cc,uc);
		}
	    }
	System.out.println("The cost incurred is "+c.computeCost());
    }
}
