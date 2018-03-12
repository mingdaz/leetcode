//BFS
class Solution {
public:
bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
    int m = maze.size();
    int n = maze[0].size();
    unordered_set<int>us;
    queue<vector<int>>q;
    q.push(start);
    us.insert(start[0]*n+start[1]);
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1, 1, 0, 0};
    while(!q.empty()){
        vector<int>v = q.front();
        if(v == destination) return true;
        q.pop();
        //us.insert(v[0]*n+v[1]);
        for(int i=0;i<4;i++){
            int x = v[0];
            int y = v[1];
            while(x>=0 && x<m && y>=0 && y<n && maze[x][y]==0){
                x += dx[i];
                y += dy[i];
            }
            x -= dx[i];
            y -= dy[i];
            if(!us.count(x*n+y)){
                us.insert(x*n+y);
                vector<int>vv = {x,y};
                q.push(vv);
            }
        }
    }
    return false;    
}
};
