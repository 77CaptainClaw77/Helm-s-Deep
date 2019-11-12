import java.util.Scanner;
import java.util.Random;
class ParentThread implements Runnable{
    Thread t;
    static Thread last;
    String tname;
    ParentThread(String name,int pri){
	this.tname=name;
	this.t=new Thread(this,name);
	t.setPriority(pri);
    }
    public void run(){
	Random rand=new Random();
	int lim=rand.nextInt(2000)+1;
	if(t.getPriority()>Thread.NORM_PRIORITY){
	    System.out.println("High priority thread "+tname+" going to sleep");
	    try{
		Thread.sleep(lim);
	    }
	    catch(InterruptedException ie){
		System.out.println(ie);
	    }		
	}
	else{
	    for(int i=0;i<lim;i++){
		System.out.println(tname+" : "+i);
		try{
		    Thread.sleep(1);
		}
		catch(InterruptedException ie){
		    System.out.println(ie);
		}
	    }
	}
	last=t;
    }
}
class ExecLongLast
{
    public static void main(String args[]){
	ParentThread multiThread[]={new ParentThread("First",Thread.MAX_PRIORITY),new ParentThread("Second",Thread.MAX_PRIORITY-1),new ParentThread("Third",Thread.NORM_PRIORITY),new ParentThread("Fourth",Thread.NORM_PRIORITY),new ParentThread("Fifth",Thread.MIN_PRIORITY)};	
	for(int i=0;i<5;i++)
	    multiThread[i].t.start();
	while(multiThread[0].t.isAlive() || multiThread[1].t.isAlive() || multiThread[2].t.isAlive() || multiThread[3].t.isAlive() || multiThread[4].t.isAlive());
	System.out.println("Longest Lasting Thread: "+ParentThread.last.getName());
    }
}
