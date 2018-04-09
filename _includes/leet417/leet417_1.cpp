class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int m = matrix.size();
        vector<pair<int, int>> ret;
        if(m==0) return ret;
        int n = matrix[0].size();
        vector<vector<char>> P(m,vector<char>(n,0));
        vector<vector<char>> A(m,vector<char>(n,0));
        queue<pair<int,int>> Q;
        
        int i,j;
        for(i=0;i<n;i++){
            P[0][i] = 1;
            Q.push(make_pair(0,i));
        }
        for(i=1;i<m;i++){
            P[i][0] = 1;
            Q.push(make_pair(i,0));
        }
        helper(Q,P,matrix);
        for(i=0;i<n;i++){
            A[m-1][i] = 1;
            Q.push(make_pair(m-1,i));
        }
        for(i=0;i<m-1;i++){
            A[i][n-1] = 1;
            Q.push(make_pair(i,n-1));
        }

        helper(Q,A,matrix);
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(A[i][j]&&P[i][j]) ret.push_back(make_pair(i,j));
            }
        }
        return ret;
    }
    void helper(queue<pair<int,int>>& Q,vector<vector<char>>& A, const vector<vector<int>>& matrix){
        int m = matrix.size();
        int n = matrix[0].size();
        while(!Q.empty()){
            auto p = Q.front();
            Q.pop();
            if(p.first>0&&A[p.first-1][p.second]==0&&matrix[p.first-1][p.second]>=matrix[p.first][p.second]){
                A[p.first-1][p.second] = 1;
                Q.push(make_pair(p.first-1,p.second));
            } 
            if(p.second>0&&A[p.first][p.second-1]==0&&matrix[p.first][p.second-1]>=matrix[p.first][p.second]){
                A[p.first][p.second-1] = 1;
                Q.push(make_pair(p.first,p.second-1));
            } 
            if(p.first<m-1&&A[p.first+1][p.second]==0&&matrix[p.first+1][p.second]>=matrix[p.first][p.second]){
                A[p.first+1][p.second] = 1;
                Q.push(make_pair(p.first+1,p.second));
            } 
            if(p.second<n-1&&A[p.first][p.second+1]==0&&matrix[p.first][p.second+1]>=matrix[p.first][p.second]){
                A[p.first][p.second+1] = 1;
                Q.push(make_pair(p.first,p.second+1));
            } 
        }
    }
};
