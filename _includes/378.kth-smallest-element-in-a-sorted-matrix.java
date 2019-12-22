import java.util.Comparator;
import java.util.PriorityQueue;

import com.apple.concurrent.Dispatch.Priority;

/*
 * @lc app=leetcode id=378 lang=java
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 *
 * algorithms
 * Medium (51.51%)
 * Likes:    1631
 * Dislikes: 100
 * Total Accepted:    142.7K
 * Total Submissions: 276.6K
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * Given a n x n matrix where each of the rows and columns are sorted in
 * ascending order, find the kth smallest element in the matrix.
 * 
 * 
 * Note that it is the kth smallest element in the sorted order, not the kth
 * distinct element.
 * 
 * 
 * Example:
 * 
 * matrix = [
 * ⁠  [ 1,  5,  9],
 * ⁠  [10, 11, 13],
 * ⁠  [12, 13, 15]
 * ],
 * k = 8,
 * 
 * return 13.
 * 
 * 
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ n^2.
 */

// @lc code=start
class Solution {
    public static class Point{
        int x;
        int y;
        int val;
        Point(int x, int y, int val){
            this.x = x;
            this.y = y;
            this.val = val;
        }
    }

    public static class cmp implements Comparator<Point>{
        public int compare(Point a, Point b){
            return a.val - b.val;
        }
    }

    private static int[][] delta = {{0,1},{1,0}};

    public int kthSmallest(int[][] matrix, int k) {
        PriorityQueue<Point> pq = new PriorityQueue<>(new cmp());
        int m = matrix.length;
        int n = matrix[0].length;
        boolean[][] visited = new boolean[m][n];
        Point p = null;
        pq.offer(new Point(0,0,matrix[0][0]));
        for(int i=0;i<k;i++){
            p = pq.poll();
            int x = p.x;
            int y = p.y;
            for(int j=0;j<delta.length;j++){
                int nx = x + delta[j][0];
                int ny = y + delta[j][1];
                if(nx<m && ny<n && visited[nx][ny]==false){
                    pq.offer(new Point(nx,ny,matrix[nx][ny]));
                    visited[nx][ny] = true;
                }
            }
        }        
        return p.val;
    }
}
// @lc code=end

