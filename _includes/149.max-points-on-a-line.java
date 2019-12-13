import java.util.HashMap;
import java.util.Map;

/*
 * @lc app=leetcode id=149 lang=java
 *
 * [149] Max Points on a Line
 *
 * https://leetcode.com/problems/max-points-on-a-line/description/
 *
 * algorithms
 * Hard (16.36%)
 * Likes:    636
 * Dislikes: 1613
 * Total Accepted:    136.8K
 * Total Submissions: 836.6K
 * Testcase Example:  '[[1,1],[2,2],[3,3]]'
 *
 * Given n points on a 2D plane, find the maximum number of points that lie on
 * the same straight line.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,1],[2,2],[3,3]]
 * Output: 3
 * Explanation:
 * ^
 * |
 * |        o
 * |     o
 * |  o  
 * +------------->
 * 0  1  2  3  4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 * Output: 4
 * Explanation:
 * ^
 * |
 * |  o
 * |     o        o
 * |        o
 * |  o        o
 * +------------------->
 * 0  1  2  3  4  5  6
 * 
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 */

// @lc code=start
class Solution {
    public int maxPoints(int[][] points) {
        int ret = 0;
        int n = points.length;
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        for(int i=0;i<n-1;i++){
            HashMap<String, Integer> slopeCnt = new HashMap();
            int x = points[i][0];
            int y = points[i][1];
            int dup = 1;
            int vertical = 0;
            for(int j=i+1;j<n;j++){
                int px = points[j][0];
                int py = points[j][1];
                if(px==x){
                    if(py==y){
                        dup++;
                    } else {
                        vertical++;
                    }
                    continue;
                }
                int dx = px - x;
                int dy = py - y;
                int tmp = gcd(dx,dy);
                dx /= tmp;
                dy /= tmp;
                String slope = dx+"/"+dy;
                if(!slopeCnt.containsKey(slope)){
                    slopeCnt.put(slope, 0);
                }
                slopeCnt.put(slope, slopeCnt.get(slope) + 1);
            }
            for(Map.Entry<String, Integer> entry: slopeCnt.entrySet()){
                int cnt = entry.getValue() + dup;
                if(cnt > ret){
                    ret = cnt;
                }
            }
            if(vertical + dup > ret){
                ret = vertical + dup;
            }
        }
        return ret;
    }

    private int gcd(int a, int b){
        if(b==0){
            return a;
        } else {
            return gcd(b,a%b);
        }
    }
}
// @lc code=end

