class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), lens = word.size();
        if(!lens || !m)
            return false;
        int n = board[0].size();
        if(m*n < lens)
            return false;
       for(int i = 0; i < m; ++i)
           for(int j = 0; j < n; ++j)
           {
               bool flag = false;
               backtrack(i, j, m, n, -1, word, board, flag);
               if(flag)
                   return true;
           }
       return false;
    }

private:
    void backtrack(int i, int j, const int m, const int n, int depth, const string &word, vector<vector<char>> &board, bool &flag)
    {
        if(++depth+1 == word.size() && board[i][j] == word[depth])   //an early end to backtrack must be done!
            flag = true;
        if(flag || board[i][j] != word[depth])
            return;
        int tmp = board[i][j];
        board[i][j] = '$';   // '$' won't appear in an English word!
        if(i+1 < m)
            backtrack(i+1, j, m, n, depth, word, board, flag);
        if(i > 0)
            backtrack(i-1, j, m, n, depth, word, board, flag);
        if(j+1 < n)
            backtrack(i, j+1, m, n, depth, word, board, flag);
        if(j > 0)
            backtrack(i, j-1, m, n, depth, word, board, flag);
        board[i][j] = tmp;
    }
};