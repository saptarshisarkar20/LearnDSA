class PalindromeNumber {
public:
    bool main(int x) {
        if(x<0 || (x!=0 && x%10==0){
          return false;
        }
        
        int ans = 0;
        while(x > ans) {
            ans = ans * 10 + x % 10;
            x =x/ 10;
        }
        if(ans==x || ans/10 ==x){
          return true;
        }
        return false;
    }
};
