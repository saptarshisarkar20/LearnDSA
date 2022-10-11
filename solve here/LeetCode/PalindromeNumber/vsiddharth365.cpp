// Author: Siddharth Verma
#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if(x<0)
            return false;
        int dummy = 0, original = x;
        while(x)
        {
            dummy=dummy*10 + x%10;
            x/=10;
        }
        return original==dummy;
    }
};
int main()
{
    Solution sol;
    int x;
    cout<<"Enter the number to check for palindrome: ";
    cin>>x;
    if(sol.isPalindrome(x))
        cout<<x<<" is a palindrome number\n";
    else
        cout<<x<<" is not a palindrome number\n";
    return 0;
}