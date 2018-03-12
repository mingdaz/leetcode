class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), mark=0, ans;

        vector<vector<int>> dist(m, vector<int>(n, 0));

        int dx[4] = {0, 1, 0, -1}; // up, right, down, left
        int dy[4] = {1, 0, -1, 0};

        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                if (grid[j][i]==1) {
                    vector<pair<int, int>> bfs(1, make_pair(j, i)), bfs2;
                    int level=1;
                    ans=INT_MAX;
                    while (!bfs.empty()) {
                        for (auto p : bfs) {
                            int y=p.first, x=p.second;
                            for (int d=0; d<4; d++) {
                                int nx=x+dx[d], ny=y+dy[d];
                                if (0<=nx && nx<n && 0<=ny && ny<m && grid[ny][nx]==mark) {
                                    grid[ny][nx] = mark-1;
                                    dist[ny][nx] += level;
                                    ans = min(ans, dist[ny][nx]);
                                    bfs2.push_back(make_pair(ny, nx));
                                }
                            }
                        }
                        level++;
                        std::swap(bfs, bfs2);
                        bfs2.clear();
                    }
                    mark -= 1;
                }
        return ans==INT_MAX ? -1 : ans;
    }
};