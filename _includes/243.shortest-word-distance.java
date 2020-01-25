/*
 * @lc app=leetcode id=243 lang=java
 *
 * [243] Shortest Word Distance
 *
 * https://leetcode.com/problems/shortest-word-distance/description/
 *
 * algorithms
 * Easy (59.61%)
 * Likes:    382
 * Dislikes: 35
 * Total Accepted:    84.7K
 * Total Submissions: 142K
 * Testcase Example:  '["practice", "makes", "perfect", "coding", "makes"]\n"coding"\n"practice"'
 *
 * Given a list of words and two words word1 and word2, return the shortest
 * distance between these two words in the list.
 * 
 * Example:
 * Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
 * 
 * 
 * Input: word1 = “coding”, word2 = “practice”
 * Output: 3
 * 
 * 
 * 
 * Input: word1 = "makes", word2 = "coding"
 * Output: 1
 * 
 * 
 * Note:
 * You may assume that word1 does not equal to word2, and word1 and word2 are
 * both in the list.
 * 
 */

// @lc code=start
class Solution {
    public int shortestDistance(String[] words, String word1, String word2) {
        int i = -1;
        int j = -1;
        int ans = Integer.MAX_VALUE;   
        for(int k=0;k<words.length;k++){
            if(word1.equals(words[k])){
                i = k;
                if(i>=0&&j>=0){
                    ans = Math.min(ans, Math.abs(i-j));
                }
            } else if(word2.equals(words[k])) {
                j = k;
                if( i>=0 && j>=0){
                    ans = Math.min(ans, Math.abs(i-j));
                }
            }
        }
        return ans;
    }
}
// @lc code=end

