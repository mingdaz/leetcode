/*
 * @lc app=leetcode id=322 lang=java
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (32.72%)
 * Likes:    2633
 * Dislikes: 92
 * Total Accepted:    284.7K
 * Total Submissions: 867.2K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 * 
 * Example 1:
 * 
 * 
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3 
 * Explanation: 11 = 5 + 5 + 1
 * 
 * Example 2:
 * 
 * 
 * Input: coins = [2], amount = 3
 * Output: -1
 * 
 * 
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 * 
 */

// @lc code=start
class Solution {
    public int coinChange(int[] coins, int amount) {
        if(amount==0|| coins.length==0) return 0;
        int[] dp = new int[amount+1];

        Arrays.fill(dp, Integer.MAX_VALUE);
        for(int i=0;i<coins.length && coins[i] <= amount;i++){
            dp[coins[i]] = 1;
        }
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.length ;j++){
                int remain = i - coins[j];
                if( remain >=0 && dp[remain] != Integer.MAX_VALUE && dp[i] > dp[remain] + 1){
                    dp[i] = dp[remain] + 1;
                } 
            }
        }
        return dp[amount]==Integer.MAX_VALUE? -1:dp[amount];
    }
}
// @lc code=end

