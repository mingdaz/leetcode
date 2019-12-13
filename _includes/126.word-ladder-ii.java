import java.awt.List;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;

import javax.xml.stream.events.StartDocument;

import sun.security.util.PropertyExpander.ExpandException;

/*
 * @lc app=leetcode id=126 lang=java
 *
 * [126] Word Ladder II
 *
 * https://leetcode.com/problems/word-ladder-ii/description/
 *
 * algorithms
 * Hard (19.76%)
 * Likes:    1341
 * Dislikes: 219
 * Total Accepted:    149.4K
 * Total Submissions: 756K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * all shortest transformation sequence(s) from beginWord to endWord, such
 * that:
 * 
 * 
 * Only one letter can be changed at a time
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 * 
 * 
 * Note:
 * 
 * 
 * Return an empty list if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * Output:
 * [
 * ⁠ ["hit","hot","dot","dog","cog"],
 * ["hit","hot","lot","log","cog"]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * Output: []
 * 
 * Explanation: The endWord "cog" is not in wordList, therefore no possible
 * transformation.
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        List<List<String>> res = new ArrayList<>();
        Set<String> words = new HashSet<>(wordList);
        if(!words.contains(endWord)) return res;
        
        Map<String, List<String>> map = new HashMap<>(); // current word and nexts
        Set<String> startSet = new HashSet<>();
        Set<String> endSet = new HashSet<>();
        startSet.add(beginWord);
        endSet.add(endWord);
        
        bfs(startSet, map, words, endSet, false);
        
        List<String> list = new ArrayList<>();
        list.add(beginWord);
        dfs(res, list, endWord, beginWord, map);
        
        return res;
    }
    
    private void dfs(List<List<String>> res, List<String> list, String endWord, String curword, Map<String, List<String>> map) {
        if(curword.equals(endWord)) {
            res.add(new ArrayList<>(list));
            return;
        }
        
        if(map.get(curword) == null) return;
        for(String next : map.get(curword)) {
            list.add(next);
            dfs(res, list, endWord, next, map);
            list.remove(list.size() - 1);
        }
    }
    
    private void bfs(Set<String> startSet, Map<String, List<String>> map, Set<String> words, Set<String> endSet, boolean reverse) {
        if (startSet.size() == 0) return;
        
        if (startSet.size() > endSet.size()) {
            bfs(endSet, map, words, startSet, !reverse);
            return;
        }
        
        Set<String> nextLevelSet = new HashSet<>();
        boolean finish = false;
        words.removeAll(startSet);
        
        for (String word : startSet) {
            char[] curword = word.toCharArray();
            for (int i = 0; i < curword.length; i++) {
                char oldchar = curword[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    curword[i] = c;
                    String word_after = new String(curword);
                    
                    if (words.contains(word_after)) {
                        if(endSet.contains(word_after)) {
                            finish = true;
                        }
                        else {
                            nextLevelSet.add(word_after);
                        }
                        
                        String key = reverse ? word_after : word;
                        String value = reverse ? word : word_after;
                        
                        if(map.get(key) == null) {
                            map.put(key, new ArrayList<>());
                        }
                        
                        map.get(key).add(value);
                    }
                }
                curword[i] = oldchar;
            }
        }
        if(finish == false) {
            bfs(nextLevelSet, map, words, endSet, reverse);
        }
    }
}
// @lc code=end

