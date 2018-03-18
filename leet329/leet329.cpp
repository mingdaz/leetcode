class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m==0) return 0;
        int n = matrix[0].size();
        vector<vector<int>> DP(m,vector<int>(n,-1));
        int ret = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                helper(matrix,DP,i,j,ret);
            }
        }
        return ret;
    }
private:
    void helper(vector<vector<int>>& mat, vector<vector<int>>& DP, int i, int j, int& ret){
        if(DP[i][j]>0) return; // already visited
        int m = mat.size();
        int n = mat[0].size();
        DP[i][j] = 1;
        if(i>0&&mat[i][j]<mat[i-1][j]){
            if(DP[i-1][j]<0) helper(mat,DP,i-1,j,ret);
            DP[i][j] = max(DP[i][j],1+DP[i-1][j]);
        }
        if(i+1<m&&mat[i][j]<mat[i+1][j]){
            if(DP[i+1][j]<0) helper(mat,DP,i+1,j,ret);
            DP[i][j] = max(DP[i][j],1+DP[i+1][j]);
        }
        if(j>0&&mat[i][j]<mat[i][j-1]){
            if(DP[i][j-1]<0) helper(mat,DP,i,j-1,ret);
            DP[i][j] = max(DP[i][j],1+DP[i][j-1]);
        }
        if(j+1<n&&mat[i][j]<mat[i][j+1]){
            if(DP[i][j+1]<0) helper(mat,DP,i,j+1,ret);
            DP[i][j] = max(DP[i][j],1+DP[i][j+1]);
        }
        if(DP[i][j]>ret) ret = DP[i][j];
    }
};