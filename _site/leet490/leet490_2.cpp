class Solution {
public:
    typedef pair<int, int> PII;
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int R = maze.size(), C = maze[0].size();
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        visited[start[0]][start[1]] = true;
        queue<PII> q;
        q.emplace(start[0], start[1]);
        
        vector<PII> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!q.empty()) {
            PII cur = q.front();
            q.pop();
            
            for (PII dir : dirs) {
                
                int r = cur.first, c = cur.second;
                int nr = r + dir.first, nc = c + dir.second;
                while (nr>=0 && nc>=0 && nr<R && nc<C && maze[nr][nc] == 0) {
                    r = nr;
                    c = nc;
                    
                    nr = r + dir.first;
                    nc = c + dir.second;
                }
                
                if (destination[0] == r && destination[1] == c) return true;
                
                if (visited[r][c]) continue;
                visited[r][c] = true;
                q.emplace(r, c);
            }
            
        }
        
        return false;
        
    }
};
