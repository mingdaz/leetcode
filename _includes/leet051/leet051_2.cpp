class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> path;
        backtracking(res,path,n,0,0,0);
        return res;
    }
    void backtracking(vector<vector<string>>& res,vector<string>& path,int n, int col,int diag1,int diag2){
        int j = path.size();
        if(j==n) res.push_back(path);
        else{
            string tmp(n,'.');
            for(int i=0;i<n;i++){
                if(!(col&(1<<i)) && !(diag1&(1<<(i+j))) && !(diag2&(1<<(i-j+n-1))) ){
                    tmp[i] = 'Q';
                    path.push_back(tmp);
                    backtracking(res,path,n,col|(1<<i),diag1|(1<<(i+j)),diag2|(1<<(i-j+n-1)));
                    path.pop_back();
                    tmp[i] = '.';               
                }
            }
        }
    }
    
};