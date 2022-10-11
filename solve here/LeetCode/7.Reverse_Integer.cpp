class Solution {
public:
    int reverse(int x) {
        int flag=0;
        if(x==INT_MIN){
            return 0;
        }
        if(x<0){
            flag=1;
            x=-x;
        }
        vector <int> v;
        while(x){
            int a=x%10;
            v.push_back(a);
            x/=10;
        }
        int flag2=0;
        int ans=0,m=10;
        long check=ans;
        for(int i=0;i<v.size();i++){
            if(v[i]==0 && flag2==0){
                continue;
            }
            else if(v[i]==0 && flag2==1){
                if(check*m>INT_MAX){
                    return 0;
                }
                ans=ans*m + v[i];
                check=ans;
            }
            else{
                if(check*m>INT_MAX){
                    return 0;
                }
                ans=ans*m+v[i];
                check=ans;
                flag2=1;
            }
        }
        if(flag==1){
            ans=-ans;
        }
        return ans;
    }
};
