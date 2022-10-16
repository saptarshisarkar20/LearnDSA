class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;    
        }
        
        set<vector<int>> s;
        
        for(int i=0;i<n;i++){
            for(int j=(i+1);j<n;j++){
                int left = (0-nums[i]-nums[j]);
                int cnt = 1;
                if(nums[i]==left){
                    cnt++;
                }
                if(nums[j]==left){
                    cnt++;
                }
                if(mp[left]>=cnt){
                    vector<int> store;
                    store.push_back(nums[i]);
                    store.push_back(nums[j]);
                    store.push_back(left);
                    sort(store.begin(),store.end());
                    s.insert(store);
                }
            }
        }
        
        
        vector<vector<int>> ans;
        for(auto it : s){
            ans.push_back(it);
        }
        
        return ans;
    }
};
