import java.util.List;

/*
 * @lc app=leetcode id=301 lang=java
 *
 * [301] Remove Invalid Parentheses
 *
 * https://leetcode.com/problems/remove-invalid-parentheses/description/
 *
 * algorithms
 * Hard (41.36%)
 * Likes:    1979
 * Dislikes: 82
 * Total Accepted:    168K
 * Total Submissions: 405.8K
 * Testcase Example:  '"()())()"'
 *
 * Remove the minimum number of invalid parentheses in order to make the input
 * string valid. Return all possible results.
 * 
 * Note: The input string may contain letters other than the parentheses ( and
 * ).
 * 
 * Example 1:
 * 
 * 
 * Input: "()())()"
 * Output: ["()()()", "(())()"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "(a)())()"
 * Output: ["(a)()()", "(a())()"]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: ")("
 * Output: [""]
 * 
 */

// @lc code=start
class Solution {
    public List<String> removeInvalidParentheses(String s) {
        int l = 0;
        int r = 0;
        int st = 0;
        int p = 0;
        for (char c : s.toCharArray()) {
            if (c == ')') {
                if (st > 0) {
                    st--;
                    p++;
                }
                r++;
            } else if (c == '(') {
                l++;
                st++;
            }
        }
        Set<String> res = new HashSet<>();
        dfs(0, l, r, 0, p, s, "", res);
        return new ArrayList<String>(res);
    }

    private void dfs(int i, int l, int r, int st, int p, String s, String path, Set<String> res) {
        if (p == 0) {
            if (st > 0)
                return;
            int tmp = i;
            while (i < s.length()) {
                if (s.charAt(i) != '(' && s.charAt(i) != ')') {
                    path += s.charAt(i);
                }
                i++;
            }
            res.add(path);
            return;
        } else if (Math.min(st + l, r) < p) {
            // prune, if min, left/right < remaining pair
            return;
        } else {
            while (i < s.length() && s.charAt(i) != '(' && s.charAt(i) != ')') {
                path += s.charAt(i++);
            }
            if (s.charAt(i) == '(') {
                dfs(i + 1, l - 1, r, st + 1, p, s, path + "(", res);
                dfs(i + 1, l - 1, r, st, p, s, path, res);
            } else {
                if (st > 0)
                    dfs(i + 1, l, r - 1, st - 1, p - 1, s, path + ")", res);
                dfs(i + 1, l, r - 1, st, p, s, path, res);
            }
        }
    }
}

class Solution {
    public List<String> removeInvalidParentheses(String s) {
        List<String> output = new ArrayList<>();
        removeHelper(s, output, 0, 0, '(', ')');
        return output;
    }

    public void removeHelper(String s, List<String> output, int iStart, int jStart, char openParen, char closedParen) {
        int numOpenParen = 0, numClosedParen = 0;
        for (int i = iStart; i < s.length(); i++) {
            if (s.charAt(i) == openParen)
                numOpenParen++;
            if (s.charAt(i) == closedParen)
                numClosedParen++;
            if (numClosedParen > numOpenParen) { // We have an extra closed paren we need to remove
                for (int j = jStart; j <= i; j++) // Try removing one at each position, skipping duplicates
                    if (s.charAt(j) == closedParen && (j == jStart || s.charAt(j - 1) != closedParen))
                        // Recursion: iStart = i since we now have valid # closed parenthesis thru i.
                        // jStart = j prevents duplicates
                        removeHelper(s.substring(0, j) + s.substring(j + 1, s.length()), output, i, j, openParen,
                                closedParen);
                return; // Stop here. The recursive calls handle the rest of the string.
            }
        }
        // No invalid closed parenthesis detected. Now check opposite direction, or
        // reverse back to original direction.
        String reversed = new StringBuilder(s).reverse().toString();
        if (openParen == '(')
            removeHelper(reversed, output, 0, 0, ')', '(');
        else
            output.add(reversed);
    }
}
// @lc code=end
