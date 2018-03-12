class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<int>> dist(m,vector<int>(n,-1));
        dist[start[0]][start[1]]=0;
        queue<vector<int>> q;
        q.push(start);
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        while(!q.empty()){
            vector<int> v = q.front();
            q.pop();
            if(start!=destination){
                for(int i=0;i<4;i++){
                    int x = v[0];
                    int y = v[1];
                    int d = dist[x][y];
                    while(x>=0&&x<m&&y>=0&&y<n&&maze[x][y]==0){
                        x += dx[i];
                        y += dy[i];
                        d++;
                        
                    }
                    x -= dx[i];
                    y -= dy[i];
                    d--;
                    if(dist[x][y]==-1||dist[x][y]>d){
                        dist[x][y] = d;
                        vector<int>vv = {x,y,d};
                        q.push(vv);
                    }
                }
            }
        }
        return  dist[destination[0]][destination[1]];
    }
};
