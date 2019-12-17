/*
 * @lc app=leetcode id=44 lang=java
 *
 * [44] Wildcard Matching
 *
 * https://leetcode.com/problems/wildcard-matching/description/
 *
 * algorithms
 * Hard (23.73%)
 * Likes:    1459
 * Dislikes: 84
 * Total Accepted:    209.4K
 * Total Submissions: 881.7K
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement wildcard pattern
 * matching with support for '?' and '*'.
 * 
 * 
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * 
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * Note:
 * 
 * 
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like ? or *.
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
 * p = "*"
 * Output: true
 * Explanation: '*' matches any sequence.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "cb"
 * p = "?a"
 * Output: false
 * Explanation: '?' matches 'c', but the second letter is 'a', which does not
 * match 'b'.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input:
 * s = "adceb"
 * p = "*a*b"
 * Output: true
 * Explanation: The first '*' matches the empty sequence, while the second '*'
 * matches the substring "dce".
 * 
 * 
 * Example 5:
 * 
 * 
 * Input:
 * s = "acdcb"
 * p = "a*c?b"
 * Output: false
 * 
 * 
 */

// @lc code=start
// DP
class Solution {
    public boolean isMatch(String a, String b) {
        int m = a.length();
        int n = b.length();
        char[] s = a.toCharArray();
        char[] p = b.toCharArray();
        boolean[][] dp = new boolean[m+1][n+1];
        dp[0][0] = true;
        for(int i=0;i<n;i++){
            if(p[i]!='*'){
                break;
            } else {
                dp[0][i+1] = dp[0][i];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // dp[i+1][j+1] = dp[i][j]
                if(dp[i][j] && (s[i]==p[j] || p[j]=='?' || p[j]=='*')){
                    dp[i+1][j+1] = true;
                } else if(dp[i+1][j] && p[j]=='*'){
                    dp[i+1][j+1] = true;
                } else if(dp[i][j+1] && p[j]=='*'){
                    dp[i+1][j+1] = true;
                }
            }
        }
        return dp[m][n];
    }
}
// BackTracking
class Solution {
    public boolean isMatch(String s, String p) {
      int sLen = s.length(), pLen = p.length();
      int sIdx = 0, pIdx = 0;
      int starIdx = -1, sTmpIdx = -1;
  
      while (sIdx < sLen) {
        // If the pattern caracter = string character
        // or pattern character = '?'
        if (pIdx < pLen && (p.charAt(pIdx) == '?' || p.charAt(pIdx) == s.charAt(sIdx))){
          ++sIdx;
          ++pIdx;
        }
        // If pattern character = '*'
        else if (pIdx < pLen && p.charAt(pIdx) == '*') {
          // Check the situation
          // when '*' matches no characters
          starIdx = pIdx;
          sTmpIdx = sIdx;
          ++pIdx;
        }
        // If pattern character != string character
        // or pattern is used up
        // and there was no '*' character in pattern 
        else if (starIdx == -1) {
          return false;
        }
        // If pattern character != string character
        // or pattern is used up
        // and there was '*' character in pattern before
        else {
          // Backtrack: check the situation
          // when '*' matches one more character
          pIdx = starIdx + 1;
          sIdx = sTmpIdx + 1;
          sTmpIdx = sIdx;
        }
      }
  
      // The remaining characters in the pattern should all be '*' characters
      for(int i = pIdx; i < pLen; i++)
        if (p.charAt(i) != '*') return false;
      return true;
    }
  }
// @lc code=end

