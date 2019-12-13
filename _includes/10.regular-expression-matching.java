/*
 * @lc app=leetcode id=10 lang=java
 *
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (25.97%)
 * Likes:    3340
 * Dislikes: 611
 * Total Accepted:    365.5K
 * Total Submissions: 1.4M
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement regular expression
 * matching with support for '.' and '*'.
 * 
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * 
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * Note:
 * 
 * 
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like . or *.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the preceding element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "ab"
 * p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 * 
 * 
 * Example 4:
 * 
 * 
 * Input:
 * s = "aab"
 * p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore,
 * it matches "aab".
 * 
 * 
 * Example 5:
 * 
 * 
 * Input:
 * s = "mississippi"
 * p = "mis*is*p*."
 * Output: false
 * 
 * 
 */

// @lc code=start
class Solution {
    public boolean isMatch(String s, String p) {
        boolean[][] dp = new boolean[s.length()+1][p.length()+1]; 
        dp[0][0] = true;
        for(int j=0;j<p.length();j++){
            if(p.charAt(j)=='*'){
                dp[0][j+1] = dp[0][j-1];
            } 
        }

        // 0..i-1, 0..j-1 dp[i][j] s[i]==p[j] || p[j]=='.' || (p[j]=='*' && p[j-1] == s[i]) 
        // 0..i, 0..j-1  (dp[i+1][j],dp[i+1][j-1]) p[j]=='*' 
        // 0..i-1, 0..j  dp[i][j+1] p[j]=='*' && (p[j-1]==s[i] || p[j-1]=='.');

        for(int i=0;i<s.length();i++){
            for(int j=0;j<p.length();j++){
                if(dp[i][j] && (s.charAt(i) ==p.charAt(j) || p.charAt(j)=='.' || (p.charAt(j)=='*' && p.charAt(j-1) == s.charAt(i)) )){
                    dp[i+1][j+1] = true;
                } else if(p.charAt(j)=='*' && (dp[i+1][j] || dp[i+1][j-1])){
                    dp[i+1][j+1] = true;
                } else if(dp[i][j+1] && p.charAt(j)=='*' && (p.charAt(j-1)==s.charAt(i) || p.charAt(j-1)=='.')){
                    dp[i+1][j+1] = true;
                }
            }
        }
        return dp[s.length()][p.length()];
    }

    public boolean isMatch2(String text, String pattern) {
        if (pattern.isEmpty()) return text.isEmpty();
        boolean first_match = (!text.isEmpty() &&
                               (pattern.charAt(0) == text.charAt(0) || pattern.charAt(0) == '.'));

        if (pattern.length() >= 2 && pattern.charAt(1) == '*'){
            return (isMatch(text, pattern.substring(2)) ||
                    (first_match && isMatch(text.substring(1), pattern)));
        } else {
            return first_match && isMatch(text.substring(1), pattern.substring(1));
        }
    }
}
// @lc code=end
