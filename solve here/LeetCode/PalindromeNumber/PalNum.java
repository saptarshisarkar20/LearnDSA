class Solution {
    public boolean isPalindrome(int x) {
        if (x <= 9) { 
            
            if (x < 0)  {
               return false;
            } 
        }
        else {
            return true;
        }
       
        if (x % 10 ==0) {
            return false;
        }
            
   
        int reverse = 0;
    
        while(x > reverse) {
             int num = x % 10;
             x /= 10;
             reverse = (reverse * 10) + num;
        }
        if (x == reverse || x == reverse / 10) {
             return true;
        }
        else {
            return false;
        }
    }
}
