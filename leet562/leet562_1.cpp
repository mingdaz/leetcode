class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        m = M.size();
        if(!m) return 0;
        n = M[0].size();
        if(!n) return 0;
        vector<vector<vector<int>>> cnt(m,vector<vector<int>>(n,vector<int>(4,1)));
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(M[i][j])
                    mark(cnt,M,i,j,ans);
            }
        }
        return ans;
    }
    int m;
    int n;
    vector<vector<int>> d = {{0,-1},{-1,-1},{-1,0},{-1,1}};
    void mark(vector<vector<vector<int>>>& cnt, vector<vector<int>>& M, int i, int j,int& ans){
        for(int k=0;k<4;k++){
            int x = i+d[k][0];
            int y = j+d[k][1];
            if(x>=0&&x<m&&y>=0&&y<n&&M[x][y]){
                cnt[i][j][k] = cnt[x][y][k]+1;
                ans = max(ans,cnt[i][j][k]);
            }
        }
        ans = max(ans,1);
    }
};
