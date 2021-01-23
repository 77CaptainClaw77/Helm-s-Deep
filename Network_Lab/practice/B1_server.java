import java.net.*;
import java.io.*;
class TCP_Server{
    public static void main(String[] args) {
	try{
	    ServerSocket ss=new ServerSocket(2789);
	    System.out.println("Server in Listen Mode");
	    Socket s=ss.accept();
	    System.out.println("Connection Established!");
	    PrintWriter pw=new PrintWriter(s.getOutputStream(),true);
	    BufferedReader br=new BufferedReader(new InputStreamReader(s.getInputStream()));
	    String filename=br.readLine();
	    BufferedReader fr=new BufferedReader(new FileReader(filename));
	    String line="";
	    while((line=fr.readLine())!=null)
		pw.println(line);
	    System.out.println("Connection Closed");
	}
	catch(Exception e){
	    System.out.println(e);
	}
    }
}
