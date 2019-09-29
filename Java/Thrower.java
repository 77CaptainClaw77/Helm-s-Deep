class Susceptible
{
    void execFun() throws java.io.IOException
    {
	throw new java.io.IOException("Error");
    }
    void anotherFun() throws InterruptedException,Exception
    {
	try{execFun();}
	catch(Exception e){
	    System.out.println(e.getStackTrace());
	}
	throw new InterruptedException();
    }
    void passer() throws Exception
    {
	try{
	    anotherFun();
	}
	catch(Exception e)
	    {
		throw new ArithmeticException(e.toString());
	    }
	//catch(java.io.IOException ie)
	//  {
	//	System.out.println(ie);
	//  }
    }
}
class ExecExcept
{
    public static void main(String args[])
    {
	Susceptible su=new Susceptible();
	try
	    {
		su.passer();
	    }
	catch(Exception e)
	    {
		System.out.println(e);
	    }
    }
}
