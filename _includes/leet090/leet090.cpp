class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        sort(nums.begin(),nums.end());
        helper(res,path,nums,0);
        return res;
    }
private:
    void helper(vector<vector<int>>& res,vector<int>& path, vector<int>& nums, int idx){
        res.push_back(path);
        for(int i=idx;i<nums.size();i++){
            int j = i;
            for(;j+1<nums.size()&&nums[j]==nums[j+1];j++);
            for(int k=i;k<=j;k++){
                path.push_back(nums[i]);
                helper(res,path,nums,j+1);
            }
            for(int k=i;k<=j;k++){
                path.pop_back();
            }
            i = j;
        }
    }
};