class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m==0) return 0;
        int n = grid[0].size();
        if(n==0) return 0;
        vector<vector<int>> cnt(m,vector<int>(n,0));
        int ret = 0;
        for(int i=0;i<m;i++){
            int tmp = 0;
            int last = 0;
            for(int j=0;j<n;j++){
                if(grid[i][j]=='W'){
                    for(int k=last;k<j;k++){
                        if(grid[i][k]=='0'){
                            cnt[i][k] += tmp;
                            ret = max(ret,cnt[i][k]);
                        }
                    }
                    tmp = 0;
                    last = j+1;
                }
                else if(grid[i][j]=='E'){
                    tmp ++;
                }
            }
            if(tmp>0){
                for(int k=last;k<n;k++){
                    if(grid[i][k]=='0'){
                        cnt[i][k] += tmp;
                        ret = max(ret,cnt[i][k]);
                    }
                }            
            }
        }
        for(int j=0;j<n;j++){
            int tmp = 0;
            int last = 0;
            for(int i=0;i<m;i++){
                if(grid[i][j]=='W'){
                    for(int k=last;k<i;k++){
                        if(grid[k][j] == '0') {
                            cnt[k][j] += tmp;
                            ret = max(ret,cnt[k][j]);
                        }
                    }
                    tmp = 0;
                    last = i+1;
                }
                else if(grid[i][j]=='E'){
                    tmp ++;
                }
            }
            if(tmp>0){
                for(int k=last;k<m;k++){
                    if(grid[k][j]=='0'){
                        cnt[k][j] += tmp;
                        ret = max(ret,cnt[k][j]);
                    }
                } 

            }
        }
        return ret;
    }
};