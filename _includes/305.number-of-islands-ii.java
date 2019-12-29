/*
 * @lc app=leetcode id=305 lang=java
 *
 * [305] Number of Islands II
 *
 * https://leetcode.com/problems/number-of-islands-ii/description/
 *
 * algorithms
 * Hard (40.75%)
 * Likes:    670
 * Dislikes: 15
 * Total Accepted:    65.4K
 * Total Submissions: 160.9K
 * Testcase Example:  '3\n3\n[[0,0],[0,1],[1,2],[2,1]]'
 *
 * A 2d grid map of m rows and n columns is initially filled with water. We may
 * perform an addLand operation which turns the water at position (row, col)
 * into a land. Given a list of positions to operate, count the number of
 * islands after each addLand operation. An island is surrounded by water and
 * is formed by connecting adjacent lands horizontally or vertically. You may
 * assume all four edges of the grid are all surrounded by water.
 * 
 * Example:
 * 
 * 
 * Input: m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]]
 * Output: [1,1,2,3]
 * 
 * 
 * Explanation:
 * 
 * Initially, the 2d grid grid is filled with water. (Assume 0 represents water
 * and 1 represents land).
 * 
 * 
 * 0 0 0
 * 0 0 0
 * 0 0 0
 * 
 * 
 * Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.
 * 
 * 
 * 1 0 0
 * 0 0 0   Number of islands = 1
 * 0 0 0
 * 
 * 
 * Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.
 * 
 * 
 * 1 1 0
 * 0 0 0   Number of islands = 1
 * 0 0 0
 * 
 * 
 * Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.
 * 
 * 
 * 1 1 0
 * 0 0 1   Number of islands = 2
 * 0 0 0
 * 
 * 
 * Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.
 * 
 * 
 * 1 1 0
 * 0 0 1   Number of islands = 3
 * 0 1 0
 * 
 * 
 * Follow up:
 * 
 * Can you do it in time complexity O(k log mn), where k is the length of the
 * positions?
 * 
 */

// @lc code=start
class Solution {
    public List<Integer> numIslands2(int m, int n, int[][] positions) {
        List<Integer> ret = new ArrayList<>();
        int[] f = new int[m*n];
        Arrays.fill(f,-1);
        int cnt = 0;
        int[] dx = {1,-1,0,0};
        int[] dy = {0,0,1,-1};
        for(int i=0;i<positions.length;i++){
            int x = positions[i][0];
            int y = positions[i][1];
            int a = n*x+y;
            if(f[a]<0){
                cnt++;
                f[a] = a;
                for(int j=0;j<4;j++){
                    int xx = x + dx[j];
                    int yy = y + dy[j];
                    if(xx>=0&&xx<m&&yy>=0&&yy<n){
                        int b = xx*n+yy;
                        if(f[b]>=0){
                            cnt += union(a,b,f);
                        }
                    }
                }
            }
            ret.add(cnt);
        }
        return ret;
    }
    
    private int find(int a, int[] f){
        int pa,px,x = a;
        while(f[x]!=x){
            x = f[x];
        }
        pa = x;
        x = a;
        while(pa!=x){
            px = f[x];
            f[x] = pa;
            x = px;
        }
        return pa;
    }
    
    private int union(int x, int y, int[] f){
        int pa = find(x,f);
        int pb = find(y,f);
        if(pa!=pb){
            f[pa] = pb;
            return -1;
        }
        return 0;
    }
}
// @lc code=end

