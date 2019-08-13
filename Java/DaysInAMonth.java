import java.util.Scanner;
class MonthDays
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the month number: ");
        int month_num=sc.nextInt();
        System.out.print("Is it a leap year? (Enter \'true\' or \'false\'): ");
        boolean is_leap=sc.nextBoolean();
        System.out.println("The number of days in the month is "+((month_num>7)?(month_num%2==0?31:30):(month_num==2?(is_leap?29:28):(month_num%2==0?30:31))));
    }    
}