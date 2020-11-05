import java.util.*;
public class Triangle{
    public static void main(String args[]){
	Scanner sc=new Scanner(System.in);
	System.out.println("Enter values: ");
	while(true){
	    try{	  
		int a=sc.nextInt(),b=sc.nextInt(),c=sc.nextInt();
		while(a<0 || a>10 || b<0 || b>10 || c<0 || c>10){
		    System.out.println("Invalid Input!!Re-enter values: ");
		    a=sc.nextInt();
		    b=sc.nextInt();
		    c=sc.nextInt();
		}
		if(a>=b+c || b>=a+c || c>=a+b)
		    System.out.println("Not a triangle!");
		else if(a==b && b==c)
		    System.out.println("Equilateral triangle");
		else if(a==b || b==c || a==c)
		    System.out.println("Isoscles triangle");
		else
		    System.out.println("Scalene triangle");
		break;
	    }
	    catch(Exception e){
		System.out.println("Invalid Input!!Re-enter values: ");
		sc.nextLine();
		continue;
	    }
	}
	sc.close();
    }
}
