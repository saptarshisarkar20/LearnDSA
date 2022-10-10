// Author: Siddharth Verma
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>v;
        sort(nums.begin(),nums.end());
        int left,right,sum;
        for(int i=0;i<nums.size();i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            left=i+1;
            right=nums.size()-1;
            sum=nums[i];
            while(left<right)
            {
                if(sum+nums[left]+nums[right]>0)
                    right--;
                else if(sum+nums[left]+nums[right]<0)
                    left++;
                else
                {
                    v.push_back(vector<int>{nums[i],nums[left],nums[right]});
                    left++;
                    while(nums[left]==nums[left-1] and left<right)
                        left++;
                }
            }
        }
        return v;
    }
};
int main()
{
    Solution sol;
    vector<int>v{-1, 0, 1, 2, -1, -4};
    vector<vector<int>>ans=sol.threeSum(v);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<3;j++)
            printf("%d ",ans[i][j]);
        printf("\n");
    }
    return 0;
}