vector<vector<int>> threeSum(const vector<int>& nums) {
  vector<vector<int>> output;
  for (int i = 0; i < nums.size(); ++i) {
    for (int j = i + 1; j < nums.size(); ++j) {
      for (int k = j + 1; k < nums.size(); ++k) {
        if (k != j + 1 && nums[k] == nums[k - 1]) continue;
        if (nums[i] + nums[j] + nums[k] == 0) {
          output.push_back({nums[i], nums[j], nums[k]});
        }
      }
    }
  }
  return output;
}
