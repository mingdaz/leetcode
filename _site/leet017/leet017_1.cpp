class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()) return res;
        string ans = "";
        helper(digits,ans,0,res);
        return res;
    }
private:
    vector<vector<char>> dict= {
        {'a','b','c'},{'d','e','f'},
        {'g','h','i'},{'j','k','l'},{'m','n','o'},
        {'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
    void helper(string& digits, string& ans,int idx,vector<string>& res){
        if(idx==digits.size())res.push_back(ans);
        else{
            int key = digits[idx]-'2';
            for(int i=0;i<dict[key].size();i++){
                ans.push_back(dict[key][i]);
                helper(digits,ans,idx+1,res);
                ans.pop_back();
            } 
        }
    }
};
