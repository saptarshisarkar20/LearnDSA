class Solution {
public:
    int rec(int i,int j,vector<vector<int>> &dp,string &s){
        if(i==j){
            return dp[i][i] = 1;
        }
        if(j==(i+1)){
            if(s[i]==s[j]){
                return dp[i][j] = 2;
            }
            else{
                return dp[i][j] = 0;
            }
        }
        if(i>j){
            return 0;
        }
        
        auto &ans = dp[i][j];
        if(ans!=(-1)){
            return ans;
        }
        
        if(s[i]==s[j]){
            int x = rec(i+1,j-1,dp,s);
            if(x==0){
                return ans = 0;
            }
            else{
                return ans = x+2;
            }
        }
        else{
            int x = rec(i+1,j,dp,s);
            int y = rec(i,j-1,dp,s);
            return ans = 0;
        }
    }
    
    string longestPalindrome(string s) {
        
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        // rec(0,n-1,dp,s);
        
        int val = 1;
        int x = 0;
        int y = 0;
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(dp[i][j]==(-1)){
                    rec(i,j,dp,s);
                }
                if(dp[i][j]>val){
                    val = dp[i][j];
                    x = i;
                    y = j;
                }
            }
        }
        
        string ans = "";
        for(int i=x;i<(y+1);i++){
            ans+=s[i];
        }
        
        return ans;
    }
};
