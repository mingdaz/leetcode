class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        rows_cnt = vector<int>(n,0);
        cols_cnt = vector<int>(n,0);
        diag_cnt = vector<int>(2,0);
        rows = vector<char>(n,0);
        cols = vector<char>(n,0);
        diag = vector<char>(2,0);
        this->n = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if(rows[row]==0){
            rows[row] = player;
            rows_cnt[row]++;
        } 
        else if(rows[row]==player){
            rows_cnt[row]++;
        }
        else{
            rows[row] = -1;
        }
        if(rows[row]>0&&rows_cnt[row]==n) return rows[row];
        if(cols[col]==0){
            cols[col] = player;
            cols_cnt[col]++;
        } 
        else if(cols[col]==player){
            cols_cnt[col]++;
        }
        else{
            cols[col] = -1;
        }
        if(cols[col]>0&&cols_cnt[col]==n) return cols[col];
        if(col==row){
            if(diag[0]==0){
                diag[0] = player;
                diag_cnt[0]++;
            } 
            else if(diag[0]==player){
                diag_cnt[0]++;
            }
            else{
                diag[0] = -1;
            }
            if(diag[0]>0&&diag_cnt[0]==n) return diag[0];
        }
        if(col+row==n-1){
            if(diag[1]==0){
                diag[1] = player;
                diag_cnt[1]++;
            } 
            else if(diag[1]==player){
                diag_cnt[1]++;
            }
            else{
                diag[1] = -1;
            }
            if(diag[1]>0&&diag_cnt[1]==n) return diag[1];

        }
        return 0;
            
    }
private: 
    vector<int> rows_cnt;
    vector<int> cols_cnt;
    vector<int> diag_cnt;
    vector<char> rows;
    vector<char> cols;
    vector<char> diag;
    int n;

};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
