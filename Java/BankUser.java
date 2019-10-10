import java.util.Scanner;
public class BankUser
{
    public static void main(String args[])
    {
	Scanner sc=new Scanner(System.in);
	Balance.Account ac=new Balance.Account();
	while(true)
	    {
		System.out.println("Select the desired option\n1.Deposit\n2.Withdraw\n3.Display Balance\n4.Exit");
		switch(sc.nextInt())
		    {
		    case 1:System.out.println("Enter the amount to be deposited");
			ac.deposit(sc.nextFloat());
			ac.Display_Balance();
			break;
		    case 2:System.out.println("Enter the amount to be withdrawn");
			ac.withdraw(sc.nextFloat());
			ac.Display_Balance();
			break;
		    case 3:ac.Display_Balance();
			break;
		    case 4:System.exit(0);
		    default:System.out.println("Invalid Choice");
		    }
	    }	
    }
}
