class Solution {
    // recursive
public:
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> res;
       helper(res,nums,0);
       return res;
    }
    void helper(vector<vector<int>>& res,vector<int>& nums,int begin ){
        if(begin>=nums.size()) {
            res.push_back(nums);
            return;
        }
        for(int i=begin;i<nums.size();i++){
            swap(nums[begin],nums[i]);
            helper(res,nums,begin+1);
            swap(nums[begin],nums[i]);
        }
    }
};