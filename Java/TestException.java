public class TestException
{
    public static int sum(int l[])
    {
	int res=0;
	for(int i:l)//overextend here for array out of bounds exception
	    res+=i;
	return res;
    }
    public static void main(String args[])
    {
	try
	    {
		System.out.println(sum(new int[] {1,2,3,4,5/0}));
	    }
	catch(Exception ex)
	    {
		ex.printStackTrace();
		System.out.println(ex.getMessage());
		System.out.println(ex);
		System.out.println("Trace information:-");
		StackTraceElement[] ele=ex.getStackTrace();
			for(StackTraceElement i:ele)
			    {
		System.out.println("Method:"+i.getMethodName()+":"+i.getClassName()+":"+i.getLineNumber());
	    }
	    }

    }
}
