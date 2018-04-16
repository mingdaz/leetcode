class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0];
        int y = click[1];
        int m = board.size();
        int n = board[0].size();
        
        if(board[x][y]=='M') {
            board[x][y]='X';
            return board;
        }
        
        queue<pair<int,int>> Q;
        Q.push(pair<int,int>(x,y));
        int size = Q.size();
        while(size){
            for(int i=0;i<size;i++){
                auto p = Q.front();
                Q.pop();
                x = p.first;
                y = p.second;
                int cnt = count(board,x,y);
                if(cnt>0){
                    board[x][y] = cnt + '0';
                }
                else{
                    board[x][y] = 'B';
                    for(int i=-1;i<2;i++){
                        if(x+i<0||x+i==m) continue;
                        for(int j=-1;j<2;j++){
                            if(i==0&&j==0) continue;
                            if(y+j<0||y+j==n) continue;
                            if(board[x+i][y+j]=='E'){
                                Q.push(pair<int,int>(x+i,y+j));
                                board[x+i][y+j]='?';
                            }
                        }
                    }
                }
            }
            size = Q.size();
        }
        return board;
    }
    
    int count(vector<vector<char>>& board, int x, int y){
        int m = board.size();
        int n = board[0].size();
        int cnt = 0;
        for(int i=-1;i<2;i++){
            if(x+i<0||x+i==m) continue;
            for(int j=-1;j<2;j++){
                if(i==0&&j==0) continue;
                if(y+j<0||y+j==n) continue;
                if(board[x+i][y+j]=='M')
                    cnt++;
            }
        }
        return cnt;
    }
};