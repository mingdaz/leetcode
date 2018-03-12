class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m==0) return 0;
        int n = grid[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    helper(i,j,m,n,grid);   
                }
            }
        }
        return cnt;
    }
    void helper(int i, int j, int m, int n, vector<vector<char>>& grid){
        grid[i][j] = '2';
        if(i>0&&grid[i-1][j]=='1') helper(i-1,j,m,n,grid);
        if(i<m-1&&grid[i+1][j]=='1') helper(i+1,j,m,n,grid);
        if(j>0&&grid[i][j-1]=='1') helper(i,j-1,m,n,grid);
        if(j<n-1&&grid[i][j+1]=='1') helper(i,j+1,m,n,grid);

    }
};
