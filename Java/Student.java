public class Student
{
    String usn,name,branch;
    int sem,age;
    int m[]=new int[3];
    Student()
    {
	usn=name=branch="";
	sem=1;
	age=19;
	for(int i=0;i<3;i++) m[i]=0;
    }
    Student(String usn,String name,String branch,int sem,int age,int m[])
    {
	this.usn=usn;
	this.name=name;
	this.branch=branch;
	this.sem=sem;
	this.age=age;
	for(int i=0;i<m.length;i++) this.m[i]=m[i];
    }
    double getAverage()
    {
	int s=0;
	for(int i=0;i<3;i++) s+=m[i];
	return s/3.0;
    }
}
class ExecStudent
{
    public static void main(String args[])
    {
	java.util.Scanner sc=new java.util.Scanner(System.in);
	System.out.println("Enter the number of students:");
	int n=sc.nextInt();
	Student s[]=new Student[n];
	System.out.println("Enter the details of the "+n+" students:");
	for(int i=0;i<n;i++)
	    {
		System.out.println("Enter the name:");
		String name=sc.nextLine();
		name=sc.nextLine();
		System.out.println("Enter the usn:");
		String usn=sc.nextLine();
		System.out.println("Enter the branch:");
		String branch=sc.nextLine();
		System.out.println("Enter the semester:");
		int sem=sc.nextInt();
		System.out.println("Enter the age:");
		int age=sc.nextInt();
		System.out.println("Enter the marks scored in three subjects: ");
		int m[]=new int[3];
		for(int j=0;j<3;j++)
		    m[j]=sc.nextInt();
		s[i]=new Student(usn,name,branch,sem,age,m);
	    }
	System.out.println("Name\t\t USN\t\t Branch\t Semester\t Age\t Marks1\t Marks2\t Marks3\t Average");
	for(int i=0;i<n;i++)
	    System.out.printf("%-16s %-14s  %-6s\t%1d\t\t%-2d\t  %-2d\t %2d\t %2d\t %.3f\n",s[i].name,s[i].usn,s[i].branch,s[i].sem,s[i].age,s[i].m[0],s[i].m[1],s[i].m[2],s[i].getAverage());	
    }
}
