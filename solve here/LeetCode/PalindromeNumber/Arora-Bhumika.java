class Solution 
{
    public boolean isPalindrome(int x) 
    {
        int n=x; //assign number to another variable
        int s=0; //to store reverse of the number
        int r;
        while(n>0) //to check whether number is greater than zero
        {
            r=n%10;
            s=s*10+r;
            n=n/10;
        }
        if(x==s) // comparing the original number with reverse
            return true;
        else
            return false;  
    }
}