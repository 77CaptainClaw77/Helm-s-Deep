class Employee
{
    String emp_name,designation;
    int emp_id,age;
    float salary;
    Employee(){}
    Employee(String emp_name,int emp_id,String designation,int age)
    {
	this.emp_name=emp_name;
	this.emp_id=emp_id;
	this.salary=0.0f;
	this.designation=designation;
	this.age=age;
    }
    void setSalary(float salary){this.salary=salary;}
    void display(){
	System.out.println("Employee ID:"+emp_id);
	System.out.println("Employee name:"+emp_name);
	System.out.println("Employee designation:"+designation);
	System.out.println("Employee salary:"+salary);
	System.out.println("Employee age:"+age);
    }
    static class Salary
    {
	float basic_sal,da,hra;
	Salary(){}
	Salary(float basic_sal,float da,float hra)
	{
	    this.basic_sal=basic_sal;
	    this.da=da;
	    this.hra=hra;
	}
	float computeSalary(){return basic_sal+da+hra;}
    }
}
class ExecEmployee
{
    public static void main(String args[])
    {
	java.util.Scanner sc=new java.util.Scanner(System.in);
	System.out.println("Enter the number of employees");
	int n=sc.nextInt();
	Employee e[]=new Employee[n];
	Employee.Salary s[]=new Employee.Salary[n];
	for(int i=0;i<n;i++)
	    {
		System.out.println("Enter the employee ID");
		int emp_id=sc.nextInt();
		System.out.println("Enter the employee name");
		String emp_name=sc.nextLine();
		emp_name=sc.nextLine();
		System.out.println("Enter the employee designation");
		String designation=sc.nextLine();
		System.out.println("Enter the employee age");
		int age=sc.nextInt();
		System.out.println("Enter the employee basic salary");
		float basic_sal=sc.nextFloat();
		System.out.println("Enter the employee dearness allowance ");
		float da=sc.nextFloat();
		System.out.println("Enter the employee housing rent allowance");
		float hra=sc.nextFloat();
		e[i]=new Employee(emp_name,emp_id,designation,age);
		s[i]=new Employee.Salary(basic_sal,da,hra);
		//e_s[i]=e[i].new EmployeeSalary(basic_sal,da,hra);
		e[i].setSalary(s[i].computeSalary());
		System.out.println();
	    }
	for(int i=0;i<n;i++)
	    {
		e[i].display();
	    }
    }
}
