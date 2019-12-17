/*
 * @lc app=leetcode id=22 lang=java
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (58.44%)
 * Likes:    3692
 * Dislikes: 214
 * Total Accepted:    433.4K
 * Total Submissions: 740.7K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */

// @lc code=start
// BackTracking 1
class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList();
        char[] cur = new char[n*2];
        backtrack(ans, cur, 0, 0, 0, n);
        return ans;
    }
    public void backtrack(List<String> ans, char[] cur, int l, int r, int pos, int n){
        if ( pos==2*n) {
            ans.add(new String(cur));
            return;
        }

        if (l < n){
            cur[pos] = '(';
            backtrack(ans, cur, l+1, r, pos+1, n);
        }
        if (r < l){
            cur[pos] = ')';
            backtrack(ans, cur, l, r+1, pos+1, n);
        }

    }
}
// @lc code=end

