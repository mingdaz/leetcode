class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if(heightMap.size()==0 || heightMap[0].size()==0) return 0;
        
        //enque boundary cells & mark them as visited
        int m=heightMap.size(), n=heightMap[0].size();
        priority_queue<Cell> que;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; i++) {
            que.push(Cell(i,0,heightMap[i][0]));
            que.push(Cell(i,n-1,heightMap[i][n-1]));
            visited[i][0]=true;
            visited[i][n-1]=true;
        }
        for(int j=0; j<n; j++) {
            que.push(Cell(0,j,heightMap[0][j]));
            que.push(Cell(m-1,j,heightMap[m-1][j]));
            visited[0][j]=true;
            visited[m-1][j]=true;
        } 
        
        // Going inward - using min_height node in queue & move in 4 directions & trap water locally
        vector<int> xs({0,0,1,-1}), ys({1,-1,0,0}); // 4 directions
        int water = 0;
        while(!que.empty()) {
            Cell cell = que.top();
            que.pop();
            for(int k=0; k<4; k++) {//move in 4 directions, if possible
                int xx=cell.x+xs[k], yy=cell.y+ys[k];
                if(xx<0 || xx>=m || yy<0 || yy>=n || visited[xx][yy]) continue;
                water+=max(cell.h-heightMap[xx][yy],0);
                que.push(Cell(xx,yy,max(cell.h,heightMap[xx][yy])));    
                visited[xx][yy]=true;
            }
        }
        return water;
        
    }
private:
    struct Cell {
        int x, y, h;
        Cell(int xx, int yy, int hh):x(xx), y(yy), h(hh) {}
        bool operator<(const Cell& rhs) const {
            return this->h > rhs.h;
        }
    };
};