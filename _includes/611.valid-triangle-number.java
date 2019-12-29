/*
 * @lc app=leetcode id=611 lang=java
 *
 * [611] Valid Triangle Number
 *
 * https://leetcode.com/problems/valid-triangle-number/description/
 *
 * algorithms
 * Medium (46.90%)
 * Likes:    766
 * Dislikes: 84
 * Total Accepted:    49.5K
 * Total Submissions: 105.4K
 * Testcase Example:  '[2,2,3,4]'
 *
 * Given an array consists of non-negative integers,  your task is to count the
 * number of triplets chosen from the array that can make triangles if we take
 * them as side lengths of a triangle.
 * 
 * Example 1:
 * 
 * Input: [2,2,3,4]
 * Output: 3
 * Explanation:
 * Valid combinations are: 
 * 2,3,4 (using the first 2)
 * 2,3,4 (using the second 2)
 * 2,2,3
 * 
 * 
 * 
 * Note:
 * 
 * The length of the given array won't exceed 1000.
 * The integers in the given array are in the range of [0, 1000].
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
    public int triangleNumber(int[] A) {
        int n = A.length;
        int cnt = 0;
        Arrays.sort(A);
        for(int i=0;i<n;i++){
            int l = 0;
            int r = i-1;
            while(l<r){
                if(A[l] + A[r] > A[i]){
                    cnt += (r-l);
                    r--;
                } else {
                    l++;
                }
            }
        }
        return cnt;
    }
}
// @lc code=end

