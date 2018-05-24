class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m==0) return 0;
        int n = grid[0].size();
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    grid[i][j] = '2';
                    queue<pair<int,int>> Q;
                    Q.push(pair<int,int>(i,j));
                    while(!Q.empty()){
                        auto p = Q.front();
                        Q.pop();
                        int x = p.first;
                        int y = p.second;
                        if(x>0&&grid[x-1][y]=='1'){
                            grid[x-1][y]='2';
                            Q.push(pair<int,int>(x-1,y));
                        }
                        if(y>0&&grid[x][y-1]=='1'){
                            grid[x][y-1]='2';
                            Q.push(pair<int,int>(x,y-1));
                        }
                        if(x+1<m&&grid[x+1][y]=='1'){
                            grid[x+1][y]='2';
                            Q.push(pair<int,int>(x+1,y));
                        }
                        if(y+1<n&&grid[x][y+1]=='1'){
                            grid[x][y+1]='2';
                            Q.push(pair<int,int>(x,y+1));
                        }
                    }
                }
            }
        }
        return cnt;
    }
};