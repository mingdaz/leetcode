import java.util.Set;

/*
 * @lc app=leetcode id=139 lang=java
 *
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (37.50%)
 * Likes:    3065
 * Dislikes: 167
 * Total Accepted:    428.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words.
 * 
 * Note:
 * 
 * 
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "applepenapple", wordDict = ["apple", "pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output: false
 * 
 * 
 */

// @lc code=start
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        if(s.length()==0) return false;
        Boolean[] memo = new Boolean[s.length()];
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        for(String word: wordDict){
            if(word.length()<min) min = word.length();
            if(word.length()>max) max = word.length();
        }
        return dfs(s,0,new HashSet<String>(wordDict),memo, min, max);
    }
    private boolean dfs(String s, int i, Set<String> wordDict, Boolean[] memo,
    int min, int max){
        if(i==s.length())
            return true;
        if(memo[i]!=null){
            return memo[i];
        }
        for(int j=i+min;j<=Math.min(s.length(),i+max);j++){
            String word = s.substring(i, j);
            if(wordDict.contains(word)){
                if(dfs(s,j,wordDict,memo,min,max)){
                    memo[i] = true;
                    return true;
                }
            }
        }
        memo[i] = false;
        return false;
    }
}
// @lc code=end

