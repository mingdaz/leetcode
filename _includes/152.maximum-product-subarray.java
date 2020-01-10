/*
 * @lc app=leetcode id=152 lang=java
 *
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (30.45%)
 * Likes:    2978
 * Dislikes: 131
 * Total Accepted:    272.6K
 * Total Submissions: 891K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 * 
 */

// @lc code=start
class Solution {
    public int maxProduct(int[] nums) {
        int minPos = 1;
        int maxNeg = 1;
        int prod = 1;
        int max = Integer.MIN_VALUE;
        for(int i=0;i<nums.length;i++){
            if(nums[i] > max) max = nums[i];
            if(nums[i]==0){
                minPos = 1;
                maxNeg = 1;
                prod = 1;        
            } else {
                prod *= nums[i];
                int tmp = prod/minPos;
                if(tmp > max) max = tmp;
                if(maxNeg < 0){
                    tmp = prod/maxNeg;
                    if(tmp > max) max = tmp;
                }
                if(prod >0 && prod < minPos) minPos = prod;
                if(prod <0 && (prod > maxNeg||maxNeg >0)) maxNeg = prod;
            }
        }
        return max;
    }
}
// @lc code=end

