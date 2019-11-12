class TriggerExecption{
	static void ArithExcept() throws ArithmeticException{
		int except=(1000/0);
	}
}
class ExecExceptionInfo{
    public static void main(String args[]){
	System.out.println("Exception 1\n");
	try{
	    TriggerExecption.ArithExcept();
	}
	catch(Exception ex){
	    System.out.println(ex);
	    System.out.println("Message:"+ex.getMessage());
	    System.out.println("Cause:"+ex.getCause());
		System.out.println("Localized Message:"+ex.getLocalizedMessage());
		System.out.println("Stack Trace:-");
		for(StackTraceElement ste:ex.getStackTrace())
			System.out.println(ste);		
	}
	int arr[]=new int[100];
	System.out.println("\nException 2\n");
	try {
		arr[100]=10;
	} catch (ArrayIndexOutOfBoundsException abe) {
		System.out.println("Message:"+abe.getMessage());
	    System.out.println("Cause:"+abe.getCause());
		System.out.println("Localized Message:"+abe.getLocalizedMessage());
		System.out.println("Stack Trace:-");
		abe.printStackTrace();
	}
    }
}
