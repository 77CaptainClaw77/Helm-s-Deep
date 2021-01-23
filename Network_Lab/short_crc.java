import java.util.*;
import java.math.*;
class CRC{
    public static void main(String[] args) {
	String dataword,gen;
	Scanner sc=new Scanner(System.in);
	dataword=sc.next();
	gen=sc.next();
	System.out.println(gen.length());
	String append="";
	for(int i=0;i<gen.length()-1;i++)
	    append=append+"0";
	dataword=dataword+append;
	BigInteger dtw=new BigInteger(dataword,2);
	System.out.println(dtw.toString(2));
	BigInteger g=new BigInteger(gen,2);
	System.out.println(g.toString(2));
	BigInteger rem=dtw.mod(g);
	System.out.println(rem.toString(2));
	BigInteger cdw=dtw.add(rem);
	System.out.println(cdw.mod(g));
      	String res=(cdw.mod(g)).toString(2);
	if(res.equals("0"))
	    System.out.println("No error");
	else
	    System.out.printf(res);
    }
}
