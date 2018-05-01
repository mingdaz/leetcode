class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        helper(res,nums,path,0);
        return res;
    }
private:
    void helper(vector<vector<int>>& res,vector<int>& nums, vector<int>& path, int idx){
        res.push_back(path);
        for(int i=idx;i<nums.size();i++){
            path.push_back(nums[i]);
            helper(res,nums,path,i+1);
            path.pop_back();
        }
    }
};