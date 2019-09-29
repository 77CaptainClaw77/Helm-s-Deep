class Example
{
    static
    {
	System.out.print("depends on ");
	str="a red ";
    }
    static String str;
    static String getStaticMessage()
    {
	return "wheelbarrow ";
    }
    static class StaticNested
    {
	static
	{
	    System.out.print("glazed with ");
	}
	static String getInnerMessage()
	{
	    return "rainwater beside ";
	}
    }
}
class ExecStatic
{
    final static String str="the white chickens ";
    static
    {
	System.out.print("So much ");
    }
    static String getFinalMessage()
    {
	return "\n\t\t-Mr. Robot";
    }
    public static void main(String args[])
    {
	System.out.println(Example.getStaticMessage()+Example.str+Example.StaticNested.getInnerMessage()+str+getFinalMessage());
    }
    
}
