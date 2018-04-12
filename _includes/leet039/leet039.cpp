class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(),candidates.end());
        helper(res,path,candidates,target,0);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& path, vector<int>& candidates, int target, int idx){
        if(target==0){
            res.push_back(path);
            return;
        } 
        if(idx>=candidates.size())
            return;
        if(candidates[idx]> target) 
            return;
        path.push_back(candidates[idx]);
        helper(res,path,candidates,target - candidates[idx],idx);
        path.pop_back();
        helper(res,path,candidates,target,idx+1);
    }
};