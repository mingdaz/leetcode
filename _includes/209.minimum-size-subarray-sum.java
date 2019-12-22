/*
 * @lc app=leetcode id=209 lang=java
 *
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (36.12%)
 * Likes:    1538
 * Dislikes: 87
 * Total Accepted:    213.1K
 * Total Submissions: 589K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * Given an array of n positive integers and a positive integer s, find the
 * minimal length of a contiguous subarray of which the sum ≥ s. If there isn't
 * one, return 0 instead.
 * 
 * Example: 
 * 
 * 
 * Input: s = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: the subarray [4,3] has the minimal length under the problem
 * constraint.
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution of
 * which the time complexity is O(n log n). 
 * 
 */

// @lc code=start
class Solution {
    public int minSubArrayLen(int s, int[] nums) {

        int ret = Integer.MAX_VALUE;
        int j = 0;
        int sum = 0;
        for(int i=0;i<nums.length;i++){
            sum += nums[i];
            while(sum >= s){
                ret = Math.min(ret, i-j+1);   
                sum -= nums[j++];
            }
        }
        return ret==Integer.MAX_VALUE?0:ret;
    }
}
// @lc code=end

