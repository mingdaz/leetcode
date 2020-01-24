/*
 * @lc app=leetcode id=244 lang=java
 *
 * [244] Shortest Word Distance II
 *
 * https://leetcode.com/problems/shortest-word-distance-ii/description/
 *
 * algorithms
 * Medium (50.71%)
 * Likes:    295
 * Dislikes: 101
 * Total Accepted:    62.6K
 * Total Submissions: 123.5K
 * Testcase Example:  '["WordDistance","shortest","shortest"]\n' +
  '[[["practice","makes","perfect","coding","makes"]],["coding","practice"],["makes","coding"]]'
 *
 * Design a class which receives a list of words in the constructor, and
 * implements a method that takes two words word1 and word2 and return the
 * shortest distance between these two words in the list. Your method will be
 * called repeatedly many times with different parameters. 
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
 * Note:
 * You may assume that word1 does not equal to word2, and word1 and word2 are
 * both in the list.
 * 
 */

// @lc code=start
class WordDistance {

    Map<String, List<Integer>> word2index;

    public WordDistance(String[] words) {
        word2index = new HashMap<>();
        for(int i=0;i<words.length;i++){
            if(!word2index.containsKey(words[i])){
                word2index.put(words[i], new ArrayList<Integer>());
            }
            word2index.get(words[i]).add(i);
        }
    }
    
    public int shortest(String word1, String word2) {
        return shortest(word2index.get(word1), word2index.get(word2));
    }
    
    private int shortest(List<Integer> a, List<Integer> b){
        int minDis = Integer.MAX_VALUE;
        for(int i=0,j=0;i<a.size()&&j<b.size();){
            minDis = Math.min(minDis, Math.abs( a.get(i)-b.get(j) ));
            if(a.get(i) > b.get(j)) j++;
            else i++;
        }
        return minDis;
    }
}
/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */
/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */
// @lc code=end

