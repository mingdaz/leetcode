/*
 * @lc app=leetcode id=29 lang=java
 *
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (16.17%)
 * Likes:    867
 * Dislikes: 4166
 * Total Accepted:    232.6K
 * Total Submissions: 1.4M
 * Testcase Example:  '10\n3'
 *
 * Given two integers dividend and divisor, divide two integers without using
 * multiplication, division and mod operator.
 * 
 * Return the quotient after dividing dividend by divisor.
 * 
 * The integer division should truncate toward zero.
 * 
 * Example 1:
 * 
 * 
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * 
 * Note:
 * 
 * 
 * Both dividend and divisor will be 32-bit signed integers.
 * The divisor will never be 0.
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 2^31 − 1 when the
 * division result overflows.
 * 
 * 
 */

// @lc code=start
class Solution {
    public int divide(int dividend, int divisor) {
        if(dividend == 0){
            return 0;
        }

        if(dividend == Integer.MIN_VALUE && divisor == -1){
            return Integer.MAX_VALUE;
        }
        
        if (divisor == Integer.MIN_VALUE){
            return dividend == Integer.MIN_VALUE ? 1 : 0;
        }

        // avoid overflow
        if (dividend == Integer.MIN_VALUE){
            if (divisor > 0){
                return -1 + divide(dividend + divisor, divisor);
            }else {
                return 1 + divide(dividend - divisor, divisor);
            }
        }

        boolean isNegative = false;
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)){
            isNegative = true;
        }

        dividend = Math.abs(dividend);
        divisor = Math.abs(divisor);

        if (dividend < divisor){
            return 0;
        }

        int tmp = divisor;
        int quotient = 1;
        while (tmp < dividend && tmp < 1073741824){ // Integer.MIN_VALUE is 2147483647
            quotient = quotient << 1;
            tmp = tmp << 1;
        }
        if (tmp == dividend){
            return isNegative? -quotient : quotient;
        }
        if (tmp > dividend){
            tmp = tmp >> 1;
            quotient = quotient >> 1;
        }
        
        return isNegative? -(quotient + divide(dividend - tmp, divisor)) : quotient + divide(dividend - tmp, divisor);
    }
}
// @lc code=end

