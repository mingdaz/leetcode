class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int lens = word.size();
        if(!m || !lens) return false;
        int n = board[0].size();
        if(m*n<lens) return false;
        bool flag = false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    backtracking(board,i,j,1,word,flag,m,n);
                    if(flag) return true;
                }
            }
        }
        return false;
    }
private:
    void backtracking(vector<vector<char>>& board, int i, int j, int idx, const string& word, bool& flag, int m, int n){
        if(idx==word.size())
            flag = true;
        if(flag)
            return;
        char tmp = board[i][j];
        board[i][j] = '$';
        if(i+1<m && board[i+1][j]==word[idx])
            backtracking(board,i+1,j,idx+1,word,flag,m,n);
        if(i-1>=0 && board[i-1][j]==word[idx])
            backtracking(board,i-1,j,idx+1,word,flag,m,n);
        if(j+1<n && board[i][j+1]==word[idx])
            backtracking(board,i,j+1,idx+1,word,flag,m,n);
        if(j-1>=0 && board[i][j-1]==word[idx])
            backtracking(board,i,j-1,idx+1,word,flag,m,n);
        board[i][j] = tmp;
    }
};