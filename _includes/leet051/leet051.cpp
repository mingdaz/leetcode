class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> col(n,0);
        vector<int> diag1(2*n-1,0); // i+j
        vector<int> diag2(2*n-1,0); // i-j+n-1;
        vector<string> path;
        backtracking(res,path,col,diag1,diag2);
        return res;
    }
    void backtracking(vector<vector<string>>& res,vector<string>& path,vector<int>& col,vector<int>& diag1,vector<int>& diag2){
        int j = path.size();
        int n = col.size();
        if(j==n) res.push_back(path);
        else{
            string tmp(n,'.');
            for(int i=0;i<n;i++){
                if(col[i]==0&&diag1[i+j]==0&&diag2[i-j+n-1]==0){
                    tmp[i] = 'Q';
                    col[i] = 1;
                    diag1[i+j] = 1;
                    diag2[i-j+n-1] = 1;
                    path.push_back(tmp);
                    backtracking(res,path,col,diag1,diag2);
                    path.pop_back();
                    tmp[i] = '.';
                    col[i] = 0;
                    diag1[i+j] = 0;
                    diag2[i-j+n-1] = 0;               
                }
            }
        }
    }
    
};