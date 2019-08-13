import java.util.Scanner;
public class PrintMessage
{
    public static void main(String[] args) 
    {
        if(args.length>0)
        {
                for(String message:args)
                    System.out.print(message+" ");
                System.out.println();
        }
        else
        {
            Scanner sc=new Scanner(System.in);
            System.out.print("Enter a message: ");
            String message=sc.nextLine();
            System.out.println(message);
        }
    }
}