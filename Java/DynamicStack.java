import java.util.Scanner;
interface DynamicStackMethods
{
    public void push(int ele);
    public boolean stackUnderflow();
    public boolean stackOverflow();
    public int pop();
    public void display();
}
class DynaStack implements DynamicStackMethods
{
    int arr[],top,size;
    DynaStack()
    {
	top=-1;
	size=0;
    }
    DynaStack(int size)
    {
	arr=new int[size];
	top=-1;
	this.size=size;
    }
    public boolean stackUnderflow()
    {
	if(top==-1)
	    return true;
	return false;
    }
    public boolean stackOverflow()
    {
	if(top==size-1)
	    return true;
	return false;
    }
    public void push(int ele)
    {
	if(stackOverflow())
	    {
		int temp[]=arr;
		arr=new int[size+10];
		size+=10;
		for(int i=0;i<temp.length;i++)
		    arr[i]=temp[i];
	    }
	arr[++top]=ele;
    }
    public int pop()
    {
	if(stackUnderflow())
	    {
		System.out.println("Stack is empty!");
		return -1;
	    }
	else
	    return arr[top--];
    }
    public void display()
    {
	if(top==-1)
	    System.out.println("Stack is empty");
	for(int i=top;i>=0;i--)
	    System.out.println(arr[i]);
    }
}
class ExecDyna
{
    public static void main(String args[])
    {
	DynamicStackMethods ds=new DynaStack(3);
	Scanner sc=new Scanner(System.in);
	while(true)
	    {
		System.out.println("1.Push\n2.Pop\n3.Display\n4.Exit");
		switch(sc.nextInt())
		    {
		    case 1:System.out.println("Enter the item to be pushed: ");
			ds.push(sc.nextInt());
			break;
		    case 2:int temp=ds.pop();
			if(temp!=-1)
			    System.out.println(temp+" was popped.");
			break;
		    case 3:ds.display();
			break;
		    case 4:System.exit(0);
		    default:System.out.println("Invalid Choice");
		    }
	    }
    }
}
