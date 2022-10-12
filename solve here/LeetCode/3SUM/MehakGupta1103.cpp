class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        //if all are greater than 0
        int f1 = 1, f2 = 1, f3 = 1;
        int ze = 0;
        int n = nums.size();
        //f1 --> all positive
        //f2 all negetive
        for(int i = 0; i < n; i++){
            
            if(nums[i]==0) ze++;
            
            if(nums[i] < 0){
                f2 = 0;
                f3 = 0;
            }
            if(nums[i] > 0){
                f1 = 0; 
                f3 = 0;
            }
        }
        
        
        if(f3){
            cout << "chala" << endl;
            vector<int> temp;
            for(int i = 0; i < 3; i++){
                temp.push_back(nums[i]);
            }
            ans.push_back(temp);
            return ans;
        }
        if(f1) return ans;
        if(f2) return ans;
        
        map<int, int> m;
        for(int i = 0; i < n; i++){
            m[nums[i]]++;
        }
        
        vector<int> odd;
        
        vector<int> even;
                
        vector<int> temp;
        
        set<vector<int>> s;
        
        int flag = 0;
        for(int i = 0; i < n; i++){
            if(nums[i]<0) odd.push_back(nums[i]);
            else if(nums[i] != 0) even.push_back(nums[i]);
            else flag = 1;
        }
        
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        
        //case 1 -- (o, o, e) where o+o = e
        int o = odd.size();
        for(int i = 0; i < o; i++){
            for(int j = i+1; j < o; j++){
                int l = odd[i]+odd[j];
                if(m[(-1)*l]>0){
                    temp.push_back(odd[i]);
                    temp.push_back(odd[j]);
                    temp.push_back(l*(-1));
                }
                if(!temp.empty()) s.insert(temp);
                temp.clear();
            }
        }
        
        //case 2 -- (e, e, 0) where e+e = o
        int e = even.size();
        for(int i = 0; i < e; i++){
            for(int j = i+1; j < e; j++){
                int l = even[i]+even[j];
                if(m[(-1)*l]>0){
                    temp.push_back(even[i]);
                    temp.push_back(even[j]);
                    temp.push_back(l*(-1));
                }
                if(!temp.empty()) s.insert(temp);
                temp.clear();
            }
        }
        
        //case 3 --> zero exist  (o, 0, e)
        if(ze){
             for(int i = 0; i < o; i++){
            if(m[(-1)*odd[i]] > 0){
                temp.push_back(odd[i]);
                temp.push_back(0);
                temp.push_back((-1)*odd[i]);
                if(!temp.empty()) s.insert(temp);
                temp.clear();
            }
        }
        }
       
        
        cout << "all the tuples" << endl;
        for(auto &it: s){
            // cout << it << endl;\
            for(auto &p: it) cout << p << " ";
            cout << endl;
            ans.push_back(it);
        }
        temp.clear();
        if(ze>=3){
            temp.push_back(0);
            temp.push_back(0);
            temp.push_back(0);
            ans.push_back(temp);
        }
        return ans;
    }
};