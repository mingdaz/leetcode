/*
 * @lc app=leetcode id=76 lang=java
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (32.69%)
 * Likes:    3201
 * Dislikes: 235
 * Total Accepted:    309.1K
 * Total Submissions: 943.4K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 * 
 * Example:
 * 
 * 
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 * 
 * 
 * Note:
 * 
 * 
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
 * 
 * 
 */

// @lc code=start
class Solution {
    public String minWindow(String s, String t) {
        int[] target = new int[128];
        int[] source = new int[128];
        int wordcnt = 0;
        int min = Integer.MAX_VALUE;
        int minStart= 0;
        int minEnd = 0;
        int i,j=0;
        for(char c: t.toCharArray()){
            if(target[c]==0){
                wordcnt++;
            } 
            target[c]++;
        }
        char[] str = s.toCharArray();
        for(i=0;i<str.length;i++){
            while(j<str.length && wordcnt > 0){
                char c = str[j];
                source[c]++;
                if(source[c]==target[c] && target[c]>0){
                    wordcnt--;
                }
                j++;
            }
            if(wordcnt==0 && j-i < min){
                minStart = i;
                minEnd = j;
                min = j - i;
            }
            char c = str[i];
            if(source[c]==target[c]){
                wordcnt++;
            }
            source[c]--;
        }
        return s.substring(minStart, minEnd);
    }
}
// @lc code=end

