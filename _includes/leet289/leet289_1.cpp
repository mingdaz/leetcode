class Solution {
public:
    void gameOfLife(vector<vector<int>>& a) {
        int m = a.size();
        if(!m) return;
        int n = a[0].size();
        vector<vector<int>> board = a;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sum = 0;
                if(i>0){
                    if(j>0) sum += board[i-1][j-1];
                    sum += board[i-1][j];
                    if(j<n-1) sum += board[i-1][j+1];
                }
                if(i<m-1){
                    if(j>0) sum += board[i+1][j-1];
                    sum += board[i+1][j];
                    if(j<n-1) sum += board[i+1][j+1];
                }
                if(j>0)
                    sum += board[i][j-1];
                if(j<n-1)
                    sum += board[i][j+1];
                a[i][j] = sum==3?1:((sum<2||sum>3)?0:a[i][j]);
            }
        }
    }
};
