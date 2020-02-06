import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Scanner;
import java.net.*;
public class MyServer{
    public static void main(String args[]) throws Exception{
        ServerSocket servsock=new ServerSocket(2010);
        System.out.println("Waiting for client....");
        Socket myclient=servsock.accept();
        System.out.println("Connection Established");
        PrintWriter pw=new PrintWriter(myclient.getOutputStream(),true);
        BufferedReader br=new BufferedReader(new InputStreamReader(myclient.getInputStream()));
        String filename=br.readLine();
        File fp=new File(filename);
        BufferedReader content=new BufferedReader(new FileReader(fp));
        String cont;
        while((cont=content.readLine())!=null){
            pw.println(cont);
        }
        System.out.println("Connection Terminated");
        myclient.close();
        servsock.close();
        pw.close();
        content.close();
        br.close();
    }
}