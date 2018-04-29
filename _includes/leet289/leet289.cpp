class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if(!m) return;
        int n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sum = 0;
                for(int p = max(0,i-1);p<=min(m-1,i+1);p++){
                    for(int q = max(0,j-1);q<=min(n-1,j+1);q++){
                        if(p!=i||q!=j){
                            sum += (board[p][q]&1);
                        }
                    }    
                }
                if(sum==3||(sum==2&&(board[i][j]&1))) board[i][j] += 2;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                board[i][j] >>= 1;
            }
        }
    }
};