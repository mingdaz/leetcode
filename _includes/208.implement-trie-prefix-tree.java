/*
 * @lc app=leetcode id=208 lang=java
 *
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (42.34%)
 * Likes:    2158
 * Dislikes: 38
 * Total Accepted:    226.3K
 * Total Submissions: 530.8K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n' +
  '[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * Implement a trie with insert, search, and startsWith methods.
 * 
 * Example:
 * 
 * 
 * Trie trie = new Trie();
 * 
 * trie.insert("apple");
 * trie.search("apple");   // returns true
 * trie.search("app");     // returns false
 * trie.startsWith("app"); // returns true
 * trie.insert("app");   
 * trie.search("app");     // returns true
 * 
 * 
 * Note:
 * 
 * 
 * You may assume that all inputs are consist of lowercase letters a-z.
 * All inputs are guaranteed to be non-empty strings.
 * 
 * 
 */

// @lc code=start
class Trie {

    public static class TrieNode{
        TrieNode[] childrens = new TrieNode[26];
        boolean isWord;
        String word;
    }

    private TrieNode root = new TrieNode(); 
    /** Initialize your data structure here. */
    public Trie() {

    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        TrieNode cur = root;
        for(char a: word.toCharArray() ){
            int c = a-'a';
            if(cur.childrens[c]==null){
                cur.childrens[c] = new TrieNode();
            }
            cur = cur.childrens[c];
        }
        cur.isWord = true;
        cur.word = word;
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        TrieNode cur = root;
        for(char a: word.toCharArray()){
            int c = a-'a';
            if(cur.childrens[c]==null){
                return false;
            }
            cur = cur.childrens[c];
        }
        return cur.isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        TrieNode cur = root;
        for(char a: prefix.toCharArray()){
            int c = a-'a';
            if(cur.childrens[c]==null){
                return false;
            }
            cur = cur.childrens[c];
        }
        return true; 
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
// @lc code=end

