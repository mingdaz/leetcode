class Solution {
public:
  // traditional dp - bottom up
  // let n = nums.size()
  // cs(t) = sum { cs(t-nums[i]) } for 0 <= i <= n-1
  int combinationSum4(vector<int>& nums, int target) {
    vector<int> t(target+1, 0);
    
    for (int i = 1; i <= target; i++) {
      for (auto n : nums) {
        if (n == i) t[i]++;
        else if (n < i) t[i] += t[i-n];
      }
    }

    return t[target];
  }


};
