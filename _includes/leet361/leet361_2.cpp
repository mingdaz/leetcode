class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        if(n == 0) return 0;
        
        int E_row = 0, res = 0;
        std::vector<int> E_col(n, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(j == 0 || grid[i][j-1] == 'W'){
                    E_row = 0;
                    for(int k = j; k < n && grid[i][k] != 'W'; k++)
                        E_row += (grid[i][k] == 'E');
                }
                
                if(i == 0 || grid[i-1][j] == 'W'){
                    E_col[j] = 0;
                    for(int k = i; k < m && grid[k][j] != 'W'; k++)
                        E_col[j] += (grid[k][j] == 'E');
                }
                
                if(grid[i][j] == '0') res = max(res, E_row + E_col[j]);
            }
        }
        return res;
    }
};