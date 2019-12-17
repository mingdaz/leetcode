/*
 * @lc app=leetcode id=266 lang=java
 *
 * [266] Palindrome Permutation
 *
 * https://leetcode.com/problems/palindrome-permutation/description/
 *
 * algorithms
 * Easy (60.86%)
 * Likes:    266
 * Dislikes: 43
 * Total Accepted:    76.3K
 * Total Submissions: 125.3K
 * Testcase Example:  '"code"'
 *
 * Given a string, determine if a permutation of the string could form a
 * palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: "code"
 * Output: false
 * 
 * Example 2:
 * 
 * 
 * Input: "aab"
 * Output: true
 * 
 * Example 3:
 * 
 * 
 * Input: "carerac"
 * Output: true
 * 
 */

// @lc code=start
class Solution {
    public boolean canPermutePalindrome(String s) {
        boolean[] odd = new boolean[256];
        for(char c: s.toCharArray()){
            odd[(int)c] = !odd[(int)c];
        }
        boolean flag = false;
        for(int i=0;i<odd.length;i++){
            if(odd[i]){
                if(flag) 
                    return false;
                else 
                    flag = true;
            }
        }
        return true;
    }
}
// @lc code=end

