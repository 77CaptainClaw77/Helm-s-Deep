package Balance;
public class Account
{
    float balance;
    public Account()
    {balance=0.0f; }
    public void deposit(float amount)
    {
	balance=amount>0?balance+amount:balance;
    }
    public void withdraw(float amount)
    {
	balance=amount>balance?balance:amount<0?balance:balance-amount;
    }
    public void Display_Balance()
    {
	System.out.println("Current Balance: "+balance);
    }
}
