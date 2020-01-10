/*
 * @lc app=leetcode id=200 lang=java
 *
 * [200] Number of Islands
 */

// @lc code=start
import javafx.util.Pair;

class Solution {
    int m;
    int n;
    
    public int numIslands(char[][] grid) {
        if(grid.length==0 || grid[0].length==0){
            return 0;
        }
        m = grid.length;
        n = grid[0].length;
        int ret = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    bfs(grid, i, j);
                    ret ++;
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='2'){
                    grid[i][j] = '0';
                }
            }
        }
        return ret;
    }
    
    private static int[] dx = {0,0,1,-1};
    private static int[] dy = {1,-1,0,0};
    
    private void bfs(char[][] grid, int i, int j){
        Queue<Pair<Integer, Integer>> q = new LinkedList<>();
        grid[i][j] = '2';
        q.add(new Pair<>(i,j));
        while(!q.isEmpty()){
            Pair<Integer, Integer> p = q.poll();
            int x = p.getKey();
            int y = p.getValue();
            
            for(int d=0;d<4;d++){
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(nx>=0&&nx<m&&ny>=0 && ny<n && grid[nx][ny]=='1'){
                    grid[nx][ny] = '2';
                    q.offer(new Pair<>(nx, ny));
                }
            }
        }
    }
}
// @lc code=end

