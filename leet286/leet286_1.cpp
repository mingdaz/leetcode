class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        m = rooms.size();
        if(m==0) return;
        n = rooms[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!rooms[i][j])
                    dfs(rooms,i,j);
            }
        }
    }
    
private:
    int m;
    int n;
    void dfs(vector<vector<int>>& rooms, int i,int j){
        if(i>0&&rooms[i-1][j]>rooms[i][j]+1) {
            rooms[i-1][j] = rooms[i][j] + 1;
            dfs(rooms,i-1,j);
        }
        if(i<m-1&&rooms[i+1][j]>rooms[i][j]+1) {
            rooms[i+1][j] = rooms[i][j] + 1;
            dfs(rooms,i+1,j);
        }
        if(j>0&&rooms[i][j-1]>rooms[i][j]+1) {
            rooms[i][j-1] = rooms[i][j] + 1;
            dfs(rooms,i,j-1);
        }
        if(j<n-1&&rooms[i][j+1]>rooms[i][j]+1) {
            rooms[i][j+1] = rooms[i][j] + 1;
            dfs(rooms,i,j+1);
        }
    }
};
