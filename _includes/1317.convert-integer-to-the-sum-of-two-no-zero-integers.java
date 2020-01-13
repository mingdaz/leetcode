/*
 * @lc app=leetcode id=1317 lang=java
 *
 * [1317] Convert Integer to the Sum of Two No-Zero Integers
 *
 * https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/description/
 *
 * algorithms
 * Easy (59.01%)
 * Likes:    16
 * Dislikes: 23
 * Total Accepted:    5.1K
 * Total Submissions: 8.6K
 * Testcase Example:  '2'
 *
 * Given an integer n. No-Zero integer is a positive integer which doesn't
 * contain any 0 in its decimal representation.
 * 
 * Return a list of two integers [A, B] where:
 * 
 * 
 * A and B are No-Zero integers.
 * A + B = n
 * 
 * 
 * It's guarateed that there is at least one valid solution. If there are many
 * valid solutions you can return any of them.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 2
 * Output: [1,1]
 * Explanation: A = 1, B = 1. A + B = n and both A and B don't contain any 0 in
 * their decimal representation.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 11
 * Output: [2,9]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 10000
 * Output: [1,9999]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: n = 69
 * Output: [1,68]
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: n = 1010
 * Output: [11,999]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= n <= 10^4
 * 
 */

// @lc code=start
class Solution {
    public int[] getNoZeroIntegers(int n) {
        int[] res = new int[2];
        for(int i=1;i<=n/2;i++){
            if(isValid(i) && isValid(n-i)){
                res[0] = i;
                res[1] = n - i;
                return res;    
            }
        }
        return res;
    }
    
    private boolean isValid(int x){
        while(x!=0){
            int d = x%10;
            if(d == 0)
                return false;
            x /= 10; 
        }
        return true;
    }
}
// @lc code=end

