import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.*;
import java.util.Scanner;
public class MyClient
{
    public static void main(String[] args) throws Exception{
        Socket sock=new Socket("127.0.0.1",2010);
        PrintWriter pw=new PrintWriter(sock.getOutputStream(),true);
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the filename: ");
        String filename=sc.nextLine();
        pw.println(filename);
        BufferedReader br=new BufferedReader(new InputStreamReader(sock.getInputStream()));
        String f_cont;
        while((f_cont=br.readLine())!=null){
            System.out.println(f_cont);
        }
        pw.close();
        br.close();
        sock.close();
    }
}