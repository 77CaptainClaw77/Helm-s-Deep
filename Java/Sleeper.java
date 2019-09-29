class Delay
{
    public static void main(String args[]) throws InterruptedException
    {
	System.out.println("Sleep now!");
	java.lang.Thread.sleep(1000);
	System.out.println("Wokeup now");
	System.out.println("Slept again");
	delay(5);
    }
    static void delay(int val)
    {
	try{
	    java.lang.Thread.sleep(1000);
	}
	catch(InterruptedException ie)
	    {
		System.out.println(ie);
	    }
	System.out.println("Woke up again");
    }
}
