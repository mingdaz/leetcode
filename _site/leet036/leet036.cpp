class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {};
        bool col[9][9] = {};
        bool box[9][9] = {};
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                int n= board[i][j]-'1';
                if(!row[i][n]) row[i][n] = true;
                else return false;
                if(!col[j][n]) col[j][n] = true;
                else return false;
                int b = i/3*3+j/3;
                if(!box[b][n]) box[b][n] = true;
                else return false;
            }
        }
        return true;
    }
};
