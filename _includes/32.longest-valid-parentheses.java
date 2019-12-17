/*
 * @lc app=leetcode id=32 lang=java
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (26.86%)
 * Likes:    2551
 * Dislikes: 111
 * Total Accepted:    234K
 * Total Submissions: 870.8K
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * Example 1:
 * 
 * 
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 * 
 * 
 */

// @lc code=start
// DP
class Solution {
    /*
        Time Complexity : O(N)
        Space Complexity : O(N)
    */
    public int longestValidParentheses(String s) {
        int result = 0, leftCount = 0;
        int[] dp = new int[s.length()];
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                leftCount++;
            } else if (leftCount > 0) {
                dp[i] = dp[i - 1] + 2;
                dp[i] += (i - dp[i]) >= 0 ? dp[i - dp[i]] : 0;
                result = Math.max(result, dp[i]);
                leftCount--;
            }
        }
        return result;
    }
}

// Stack
public class Solution {

    public int longestValidParentheses(String s) {
        int maxans = 0;
        Stack<Integer> stack = new Stack<>();
        stack.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.empty()) {
                    stack.push(i);
                } else {
                    maxans = Math.max(maxans, i - stack.peek());
                }
            }
        }
        return maxans;
    }
}

// O(1) Space
class Solution {
    public int longestValidParentheses(String s) {
        int n = s.length();
        int max = 0;
        
        // sweep from left;
        int countL = 0;
        int countR = 0;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '(') countL++;
            if (s.charAt(i) == ')') countR++;
            if (countL == countR) max = Math.max(max, countL+countR);
            if (countL < countR) {
                countL = 0;
                countR = 0;
            }
        }
        
        // sweep from right;
        countL = 0;
        countR = 0;
        for (int i = n-1; i >= 0; i--) {
            if (s.charAt(i) == '(') countL++;
            if (s.charAt(i) == ')') countR++;
            if (countL == countR) max = Math.max(max, countL+countR);
            if (countL > countR) {
                countL = 0;
                countR = 0;
            }
        }
        return max;
    }
}
// @lc code=end

