import java.net.*;
import java.io.*;
import java.util.Scanner;
class TCP_Client
{
    public static void main(String[] args)
    {
	try{
	    Scanner sc=new Scanner(System.in);
	    Socket s=new Socket("127.0.0.1",2789);
	    System.out.println("Enter the filename: ");
	    String filename=sc.nextLine();
	    PrintWriter pw=new PrintWriter(s.getOutputStream(),true);
	    pw.println(filename);
	    BufferedReader br=new BufferedReader(new InputStreamReader(s.getInputStream()));
	    String line="";
	    while((line=br.readLine())!=null)
		System.out.println(line);
	    System.out.println("text");
	    s.close();
	}
	catch(Exception e){
	    System.out.println(e);
	}
    }
}
