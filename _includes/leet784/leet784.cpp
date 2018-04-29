class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        backtracking(S,0,res);
        return res;
    }
private:
    void backtracking(string& S,int idx, vector<string>& res){
        res.push_back(S);
        for(int i=idx;i<S.size();i++){
            if(isdigit(S[i])) continue;
            int d = isupper(S[i])?32:-32;
            S[i] += d;
            backtracking(S,i+1,res);
            S[i] -= d;
        }
    }
};