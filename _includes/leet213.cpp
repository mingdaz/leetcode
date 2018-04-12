class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n ==1) return nums[0];
        return max(robber(nums, 0, n-2), robber(nums, 1, n-1));
    }
    int robber(vector<int>&nums, int begin, int end){
        int pre = 0, cur = 0;
        for(int i = begin; i<= end; i++){
            int tmp = max(pre+nums[i], cur);
            pre = cur;
            cur = tmp;
        }
        return cur;
    }
};