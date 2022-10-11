#include<bits/stdc++.h>
class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x), revS = s;
        reverse(begin(revS),end(revS));
        return s == revS;
    }
};
