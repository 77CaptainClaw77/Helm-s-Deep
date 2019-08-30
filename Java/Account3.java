import java.util.*;
import java.text.*;
class Transaction
{
    char type;
    Date date;
    double amount,balance;
    String description;
    Transaction()
    {}
    Transaction(char type,double amount,double balance,String description)
    {
	this.type=type;
	this.amount=amount;
	this.balance=balance;
	this.description=description;
	this.date=new Date();    
    }
}
class Account
{
    private int id;
    private double balance,annualInterestRate;
    private Date dateCreated;
    private String name;
    private ArrayList<Transaction> transactions=new ArrayList<Transaction>();
    Scanner sc=new Scanner(System.in);
    Account()
    {
	this.id=0;
	this.balance=0.0;
	this.annualInterestRate=0.0;
	this.dateCreated=new Date();
    }
    Account(String name,int id,double balance,String date)
    {
	this.name=name;
	this.id=id;
	this.balance=balance;
	this.setDate(date);
    }
    private void setDate(String date)
    {
	if(date.equals(""))
	    this.dateCreated=new Date();
	else
	    {
		SimpleDateFormat sdf=new SimpleDateFormat("dd-MM-yyyy");
		try
		    {
		    this.dateCreated=sdf.parse(date);
		    }
	       catch(ParseException pe)
		   {
		    System.out.println("Incorrect date format");
		    this.dateCreated=new Date();
		   }
	    }
    }
    //-----------------------------
    //Accessor and Mutator Functions
    //-----------------------------
    void setId(int id){ this.id=id; }
    int getId(){ return this.id; }
    void setBalance(double balance){ this.balance=balance; }
    double getBalance(){ return this.balance; }
    void setInterestRate(double interestRate){ this.annualInterestRate=interestRate; }
    double getInterestRate(){ return this.annualInterestRate; }
    String getDate(){return (this.dateCreated).toString(); }
    void setName(String name){this.name=name;}
    String getName(){return this.name;}
    void getTransactions()
    {
	if(transactions.isEmpty())
	    System.out.println("No transactions made yet.");
	else
	    {
		for(int i=0;i<transactions.size();i++)
		    {
			System.out.println("Transaction No. "+(i+1));
			System.out.println("Transaction type: "+(transactions.get(i).type=='W'?"Withdrawl":"Deposit"));
			System.out.println("Transaction Date: "+(transactions.get(i).date.toString()));
			System.out.println("Transaction Amount: "+(transactions.get(i).amount));
			System.out.println("Balance After Transaction: "+(transactions.get(i).balance));
			System.out.println("Transaction Description: "+(transactions.get(i).description));
		    }
	    }
    }
  
    void withdraw(double amt)
    {
	if(balance-amt<0)
	    System.out.println("Insufficient Balance");
	else if(amt<0)
	    System.out.println("Invalid Amount Entered");
	else
	    {
		balance-=amt;
		System.out.println("Enter a description for the transaction made: ");
		String desc=sc.nextLine();
		System.out.println("Withdrawl Successful.Remaining Account Balance: "+balance);
		Transaction tr=new Transaction('W',amt,balance,desc);
		transactions.add(tr);
		//Transaction(char type,double amount,double balance,String description)
	    }
    }
    void deposit(double amt)
    {
	if(amt<0)
	    System.out.println("Invalid Amount Entered");
	else if(amt+balance>=Double.MAX_VALUE)
	    System.out.println("Amount too large to be deposited");
	else
	    {
		System.out.println("Enter a description for the transaction made: ");
		String desc=sc.nextLine();
		balance+=amt;
		System.out.println("Deposit Successful.Remaining Account Balance: "+balance);
		Transaction tr=new Transaction('D',amt,balance,desc);
		transactions.add(tr);
	    }
    }
    double getMonthlyInterest()
    {
	return ((annualInterestRate/12)*balance);
    }
}
class ExecAccount
{
    public static void main(String args[])
    {
	Scanner sc=new Scanner(System.in);
	ArrayList<Account> accounts=new ArrayList<Account>();
	while(true)
	    {
		System.out.println("1.Create a new Account\n2.Use an Existing Account\n3.Exit");
		int ch=sc.nextInt();
		switch(ch)
		    {
		    case 1:Account ac=new Account();
			System.out.print("Enter the account id: ");
			int id=sc.nextInt();
			System.out.print("Enter the account holder name: ");
			String name=sc.nextLine();
			name=sc.nextLine();
			System.out.print("Enter the account balance: ");
			double bal=sc.nextDouble();
			System.out.print("Enter a date of creation if necessary (Else enter no to use current date): ");
			String d=sc.next();
			if(d.equals("no")) d="";
			ac=new Account(name,id,bal,d);
			System.out.print("Enter the annual interest rate: ");
			ac.setInterestRate(sc.nextDouble());
			accounts.add(ac);
			System.out.println("Account Successfully Created");
			break;
		    case 2:if(accounts.size()==0)
			    {
				System.out.println("No existing accounts");
				break;
			    }
			System.out.print("Enter the account id you want to access: ");
			int search_id=sc.nextInt();
			int ac_id=-1;
			for(int i=0;i<accounts.size();i++)
			    if(accounts.get(i).getId()==search_id)
				ac_id=i;
			if(ac_id==-1)
			    {
				System.out.println("Account not found");
				break;
			    }
			//-------------------
			//Account Operations
			//------------------
		        boolean b=false;
			do
			    {
				System.out.println("1.Deposit\n2.Withdraw\n3.View Account Summary\n4.View Monthly Interest\n5.Back");
				int choice=sc.nextInt();
				switch(choice)
				    {
				    case 1:System.out.print("Enter the amount to be deposited: ");
					accounts.get(ac_id).deposit(sc.nextDouble());
					break;
				    case 2:System.out.print("Enter the amount to be withdrawn: ");
					accounts.get(ac_id).withdraw(sc.nextDouble());
					break;
				    case 3:System.out.println("Account ID: "+accounts.get(ac_id).getId()+"\nAccount Holder Name: "+accounts.get(ac_id).getName() +"\nAccount Balance: "+accounts.get(ac_id).getBalance()+"\nInterest Rate:  "+accounts.get(ac_id).getInterestRate()+"\nDate of Creation:"+accounts.get(ac_id).getDate()+"\nTransactions:-\n");
					accounts.get(ac_id).getTransactions();
					break;
				    case 4:System.out.println("Monthly interest is "+accounts.get(ac_id).getMonthlyInterest());
					break;
				    case 5:b=true;
					break;
				    }
			    }while(!b);
			break;
		    case 3:System.exit(1);
			break;		    
		    }
	    }
    }
}
