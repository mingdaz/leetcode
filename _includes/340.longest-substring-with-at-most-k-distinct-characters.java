/*
 * @lc app=leetcode id=340 lang=java
 *
 * [340] Longest Substring with At Most K Distinct Characters
 *
 * https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/description/
 *
 * algorithms
 * Hard (41.92%)
 * Likes:    759
 * Dislikes: 25
 * Total Accepted:    100.3K
 * Total Submissions: 238.7K
 * Testcase Example:  '"eceba"\n2'
 *
 * Given a string, find the length of the longest substring T that contains at
 * most k distinct characters.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: s = "eceba", k = 2
 * Output: 3
 * Explanation: T is "ece" which its length is 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aa", k = 1
 * Output: 2
 * Explanation: T is "aa" which its length is 2.
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
    public int lengthOfLongestSubstringKDistinct(String ss, int k) {
        int[] charCnt = new int[256];
        int distinct = 0;
        int l, r = 0;
        char[] s = ss.toCharArray();
        int ret = 0;
        for(l = 0;l<s.length;l++){
            while(r<s.length && distinct <= k){
                ++charCnt[s[r]];
                if(charCnt[s[r]]==1){
                    ++distinct;
                }
                r++;
            }
            if(distinct>k){
                ret = Math.max(ret, r-1-l);
            } else {
                ret = Math.max(ret, r-l);
            }
            --charCnt[s[l]];
            if(charCnt[s[l]]==0){
                --distinct;
            }
        }
        return ret;
    }
}
// @lc code=end

