class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> ans;
        factor(n,2,res,ans);
        return res;
    }

    void factor(int n,int minval,vector<vector<int>>& res, vector<int>& ans){
        for(int i=minval;i*i<=n;i++){
            if(n%i==0){
                ans.push_back(i);
                factor(n/i,i,res,ans);
                ans.pop_back();
            }
        }
        if(!ans.empty()){
            ans.push_back(n);
            res.push_back(ans);
            ans.pop_back();
        }    
    }
};
