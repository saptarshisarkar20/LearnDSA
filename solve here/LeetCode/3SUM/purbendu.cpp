class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return {};
        
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n; i++) {
            int right = n-1, left = i+1, target = -nums[i];
            while(right > left) {
                int sum = nums[left] + nums[right];
                if(sum > target) right--;
                else if(sum < target) left++;
                else {
                    vector<int> triplet = {nums[i],nums[left],nums[right]};
                    while(right > left and nums[right] == triplet[2]) right--;
                    while(right > left and nums[left] == triplet[1]) left++;
                    ans.push_back(triplet);
                }
            }
            while(i+1<n and nums[i] == nums[i+1]) i++;
            
        }
        return ans;
    }
};