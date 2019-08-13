class LifetimeOfVariables
{
    public static void main(String args[])
    {
        for(int i=0;i<100;i++)
        {
            int y=5;
            System.out.println("The value of y is now "+y);
            y+=i*120;
        }    
    } 
}