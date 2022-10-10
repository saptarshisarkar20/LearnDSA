  string reverse(string str){
        if(str.empty()){
            return str;
        }
        string ans = "";
        for(int i=str.length()-1; i>=0; i--){
            ans+=str[i];
        }
        return ans;
    }
    
    bool isPAlindrome(string str){
        
        string ans = reverse(str);
        
        if(ans==str){
            return true;
        }
        return false;
    }
    bool isPalindrome(int x) {
        
        string str = to_string(x);
        
       if(isPAlindrome(str)){
           return true;
       }
        return false;
       
        
    }