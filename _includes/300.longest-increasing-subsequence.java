/*
 * @lc app=leetcode id=300 lang=java
 *
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (41.72%)
 * Likes:    3350
 * Dislikes: 76
 * Total Accepted:    290.4K
 * Total Submissions: 696K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 * 
 * Example:
 * 
 * 
 * Input: [10,9,2,5,3,7,101,18]
 * Output: 4 
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4. 
 * 
 * Note: 
 * 
 * 
 * There may be more than one LIS combination, it is only necessary for you to
 * return the length.
 * Your algorithm should run in O(n^2) complexity.
 * 
 * 
 * Follow up: Could you improve it to O(n log n) time complexity?
 * 
 */

// @lc code=start
// DP + binary Search
class Solution {
    public int lengthOfLIS(int[] nums) {        
        int[] dp = new int[nums.length];
        int len = 0;
        for (int num : nums) {
            int i = Arrays.binarySearch(dp, 0, len, num);
            if (i < 0) {
                i = -(i + 1);
            }
            dp[i] = num;
            if (i == len) {
                len++;
            }
        }
        return len;
    }
    
}

// DP only
class Solution {
    // Solution 1: DP (time O(n^2), space O(n))
    /* - [10,9,2,5,3,7,101,18] , output = 4
       - [2,5,7,101] -> max_length at 101 = max_length at 7 + 1
       - if current num > previous, max_length + 1
       - else, reuse the previous max_length. 
       - idea: for each num[i], compare every num[j] which is previous to num[i] with num[i]. if num[i] > num[j], update max_length = dp[i] = num[j] + 1.  
       - nums [10,9,2,5,3,7,101,18] 
        dp起始 [1,1,1,1,1,1,1,1]
        dp结果 [1,1,1,2,2,3,4,4]
    */
    public int lengthOfLIS(int[] nums) {
        if(nums == null || nums.length == 0){
            return 0;
        }
        int[] dp = new int[nums.length];
        
        int max = 0;
        
        for(int i = 0; i < nums.length; i++){
            dp[i] = 1;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
            max = Math.max(max, dp[i]);
        }

        return max;
    }
}
// @lc code=end

