class ScopeOfVariables
{
    public static void main(String args[]) 
    {
        boolean truth_var=(8>>3==1)?true:false;
        if(truth_var)
        {
            int y=100;//Scope of the variable ends in this if block 
            System.out.println("y is "+y);
        }
        int y=10;//new variable
        System.out.println("Out of scope?");
    }
}