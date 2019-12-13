/*
 * @lc app=leetcode id=564 lang=java
 *
 * [564] Find the Closest Palindrome
 *
 * https://leetcode.com/problems/find-the-closest-palindrome/description/
 *
 * algorithms
 * Hard (19.24%)
 * Likes:    190
 * Dislikes: 700
 * Total Accepted:    17K
 * Total Submissions: 88.4K
 * Testcase Example:  '"1"'
 *
 * Given an integer n, find the closest integer (not including itself), which
 * is a palindrome. 
 * 
 * The 'closest' is defined as absolute difference minimized between two
 * integers.
 * 
 * Example 1:
 * 
 * Input: "123"
 * Output: "121"
 * 
 * 
 * 
 * Note:
 * 
 * The input n is a positive integer represented by string, whose length will
 * not exceed 18.
 * If there is a tie, return the smaller one as answer.
 * 
 * 
 */

// @lc code=start
public class Solution {
    /**
     * @param n: a positive integer represented by string
     * @return:  the closest integer which is a palindrome
     */
    public String nearestPalindromic(String n) {
        // Write your code here
        long a = Long.valueOf(n), b;    //字符串转化为整数
        long half = (long) Math.pow(10L, n.length() / 2);
        long[] candidates = new long[] {b = a / half * half, b - (half > 1 ? half/10 : 1), b + half};	//构造三个数字
        long res = 0;
        for (long cand : candidates) {	//对3个数字每次进行构造回文串
            cand = mirroring(cand);
            if (cand == a) {
                continue;
            }
            if (Math.abs(res - a) > Math.abs(cand - a) || (Math.abs(res - a) == Math.abs(cand - a) && cand < res)) { //比较结果
                res = cand;       
            }
        }
        return ((Long) res).toString();
    }
    
    public long mirroring(long n) { //传入数字构造回文串
        long m = 0, x = n, half = 1, i = 0;
        while (x > 0) {
            m = m * 10 + x % 10; 
            x /= 10;
            if (i++ % 2 > 0) half *= 10L;
        }
        return n / half * half + m % half;	 //n / half * half可以清空后半部分，  + m % half填充后半部分
    }
}
// @lc code=end

