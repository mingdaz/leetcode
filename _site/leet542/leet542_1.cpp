//BFS much faster than dfs
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(!m) return matrix;
        int n = matrix[0].size();
        queue<pair<int,int>> BFS;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]) matrix[i][j] = INT_MAX;
                else BFS.push(make_pair(i,j));
            }
        }
        pair<int,int> p;
        while(!BFS.empty()){
            p = BFS.front();
            BFS.pop();
            int i = p.first;
            int j = p.second;
            if(i>0&&matrix[i][j]+1<matrix[i-1][j]){
                matrix[i-1][j] = matrix[i][j] + 1;
                BFS.push(make_pair(i-1,j));    
            } 
            if(i<m-1&&matrix[i][j]+1<matrix[i+1][j]){
                matrix[i+1][j] = matrix[i][j] + 1;
                BFS.push(make_pair(i+1,j));    
            } 
            if(j>0&&matrix[i][j]+1<matrix[i][j-1]){
                matrix[i][j-1] = matrix[i][j] + 1;
                BFS.push(make_pair(i,j-1));    
            } 
            if(j<n-1&&matrix[i][j]+1<matrix[i][j+1]){
                matrix[i][j+1] = matrix[i][j] + 1;
                BFS.push(make_pair(i,j+1));        
            }
        }
        return matrix;
    }
   
};
