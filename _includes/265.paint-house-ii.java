/*
 * @lc app=leetcode id=265 lang=java
 *
 * [265] Paint House II
 *
 * https://leetcode.com/problems/paint-house-ii/description/
 *
 * algorithms
 * Hard (43.45%)
 * Likes:    431
 * Dislikes: 17
 * Total Accepted:    53.6K
 * Total Submissions: 123.3K
 * Testcase Example:  '[[1,5,3],[2,9,4]]'
 *
 * There are a row of n houses, each house can be painted with one of the k
 * colors. The cost of painting each house with a certain color is different.
 * You have to paint all the houses such that no two adjacent houses have the
 * same color.
 * 
 * The cost of painting each house with a certain color is represented by a n x
 * k cost matrix. For example, costs[0][0] is the cost of painting house 0 with
 * color 0; costs[1][2] is the cost of painting house 1 with color 2, and so
 * on... Find the minimum cost to paint all houses.
 * 
 * Note:
 * All costs are positive integers.
 * 
 * Example:
 * 
 * 
 * Input: [[1,5,3],[2,9,4]]
 * Output: 5
 * Explanation: Paint house 0 into color 0, paint house 1 into color 2. Minimum
 * cost: 1 + 4 = 5; 
 * Or paint house 0 into color 2, paint house 1 into color 0. Minimum cost: 3 +
 * 2 = 5. 
 * 
 * 
 * Follow up:
 * Could you solve it in O(nk) runtime?
 * 
 */

// @lc code=start
class Solution {
    public int minCostII(int[][] costs) {
        int n = costs.length;
        if(n==0) return 0;
        int k = costs[0].length; 
        if(k==1) return costs[0][0];
        int[][] dp = new int[2][k];
        int cur = 0;
        int prev = 1;
        for(int i=0;i<n;i++){
            cur = 1 - cur;
            prev = 1 - cur;
            int one = -1;
            int two = -1;
            for(int j=0;j<k;j++){
                if(one==-1 || dp[prev][j] < dp[prev][one]){
                    two = one;
                    one = j;
                } else if(two==-1 || dp[prev][j] < dp[prev][two]){
                    two = j;
                }
            }
            for(int j=0;j<k;j++){
                if(j==one){
                    dp[cur][j] = dp[prev][two] + costs[i][j];
                } else {
                    dp[cur][j] = dp[prev][one] + costs[i][j];
                }
            }
        }
        int ans = Integer.MAX_VALUE;
        for(int j=0;j<k;j++){
            if(dp[cur][j] < ans) ans = dp[cur][j];
        }
        return ans;
    }
}
// @lc code=end

