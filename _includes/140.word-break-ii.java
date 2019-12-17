/*
 * @lc app=leetcode id=140 lang=java
 *
 * [140] Word Break II
 *
 * https://leetcode.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (28.99%)
 * Likes:    1335
 * Dislikes: 295
 * Total Accepted:    188.6K
 * Total Submissions: 649.9K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, add spaces in s to construct a sentence where each word is
 * a valid dictionary word. Return all such possible sentences.
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
 * Input:
 * s = "catsanddog"
 * wordDict = ["cat", "cats", "and", "sand", "dog"]
 * Output:
 * [
 * "cats and dog",
 * "cat sand dog"
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "pineapplepenapple"
 * wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 * Output:
 * [
 * "pine apple pen apple",
 * "pineapple pen apple",
 * "pine applepen apple"
 * ]
 * Explanation: Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "catsandog"
 * wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output:
 * []
 * 
 */

// @lc code=start
class Solution {
    class Trie
    {
        class Node
        {
            Node[] child;
            String word;
            Node()
            {
                child = new Node[26];
                word = null;
            }
        }
        
        Node root = new Node();
        
        void add(String s)
        {
            Node cur = root;
            for(char c : s.toCharArray())
            {
                if(cur.child[c - 'a'] == null)
                    cur.child[c - 'a'] = new Node();
                cur = cur.child[c - 'a'];
            }
            cur.word = s;
        }
    }
    
    public List<String> wordBreak(String s, List<String> wordDict) {
        Trie trie = new Trie();
        for(String w : wordDict)
            trie.add(w);
        
        Map<Integer, List<String>> mem = new HashMap<>();
        List<String> last = new ArrayList<>();
        last.add("");
        mem.put(s.length(), last);
        return trace(s, 0, trie, mem);
    }
    
    private List<String> trace(String s, int pos, Trie trie, Map<Integer, List<String>> mem)
    {
        if(mem.containsKey(pos))
        {
            return mem.get(pos);
        }
        
        List<String> res = new ArrayList<>();
        Trie.Node cur = trie.root;
        for(int i = pos; i < s.length(); i++)
        {
            cur = cur.child[s.charAt(i) - 'a'];
            if(cur == null)
                break;
            if(cur.word != null)
            {
                for(String r : trace(s, i + 1, trie, mem))
                {
                    res.add(cur.word + (r.length() > 0 ? " " + r : r));
                }
            }
        }
        mem.put(pos, res);
        return res;
    }
}

// @lc code=end

