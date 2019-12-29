/*
 * @lc app=leetcode id=55 lang=java
 *
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (32.90%)
 * Likes:    2721
 * Dislikes: 253
 * Total Accepted:    338.1K
 * Total Submissions: 1M
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Determine if you are able to reach the last index.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last
 * index.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its
 * maximum
 * jump length is 0, which makes it impossible to reach the last index.
 * 
 * 
 */

// @lc code=start
class Solution {
    public boolean canJump(int[] nums) {
        int n = nums.length;
        if(n==0)
            return false;
        boolean dp[] = new boolean[n];
        dp[0] = true;
        for(int i=0;i<n;i++){
            if(dp[i]==true){
                if(i+nums[i]>=n-1)
                    return true;
                for(int j=0;j<=nums[i];j++){
                    dp[i+j] = true;
                }
            }
        }
        return dp[n-1]; 
    }
}
// @lc code=end

