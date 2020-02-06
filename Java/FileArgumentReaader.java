import java.io.*;
public class FileArgumentReader{
    public static void main(String[] args) {
        PrintWriter p=new PrintWriter(System.out,true);
        for(String path:args){
            File f=new File(path);
            if(f.exists()){
                p.println(f.getName());
                p.println(f.getPath());
                p.println(f.canRead());
                p.println(f.canExecute());
                p.println(f.canWrite());
                p.println(f.getAbsolutePath());
                p.println(f.isHidden());
                p.println(f.getParent());
                p.println(f.length());
                p.println(f.lastModified());
                p.println(f.isFile());
                p.println(f.isDirectory());
            }
                   }
    }
}