class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper("",n,0,res);
        return res;
    }
    void helper(string cur, int left, int right,vector<string>& res){   
        if(!left&&!right) res.push_back(cur);
        else{
            if(left>0) helper(cur+"(",left-1,right+1,res);
            if(right>0) helper(cur+")",left,right-1,res);
        }
    }
};
