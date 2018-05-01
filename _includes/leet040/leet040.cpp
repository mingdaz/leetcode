class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& a, int target) {
        sort(a.begin(),a.end());
        vector<vector<int>> res;
        vector<int> path;
        helper(res,path,a,0,target);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& path, vector<int>& a, int idx, int target){
        if(target==0){
            res.push_back(path);
            return;
        } 
        if(idx>=a.size()) return;
        for(int i=idx;i<a.size();i++){
            if(a[i]>target) break;
            int j = i;
            for(;i+1<a.size()&&a[i]==a[i+1];i++);
            int k;
            for(k=j;k<=i&&a[k]<=target;k++){
                path.push_back(a[k]);
                target -= a[k];
                helper(res,path,a,i+1,target);
            }
            for(;k>j;k--){
                path.pop_back();
                target += a[j];
            }
        }
    }
};