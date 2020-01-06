/*
 * @lc app=leetcode id=269 lang=java
 *
 * [269] Alien Dictionary
 *
 * https://leetcode.com/problems/alien-dictionary/description/
 *
 * algorithms
 * Hard (33.40%)
 * Likes:    1270
 * Dislikes: 245
 * Total Accepted:    109.2K
 * Total Submissions: 325.2K
 * Testcase Example:  '["wrt","wrf","er","ett","rftt"]'
 *
 * There is a new alien language which uses the latin alphabet. However, the
 * order among letters are unknown to you. You receive a list of non-empty
 * words from the dictionary, where words are sorted lexicographically by the
 * rules of this new language. Derive the order of letters in this language.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠ "wrt",
 * ⁠ "wrf",
 * ⁠ "er",
 * ⁠ "ett",
 * ⁠ "rftt"
 * ]
 * 
 * Output: "wertf"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * [
 * ⁠ "z",
 * ⁠ "x"
 * ]
 * 
 * Output: "zx"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * [
 * ⁠ "z",
 * ⁠ "x",
 * ⁠ "z"
 * ] 
 * 
 * Output: "" 
 * 
 * Explanation: The order is invalid, so return "".
 * 
 * 
 * Note:
 * 
 * 
 * You may assume all letters are in lowercase.
 * You may assume that if a is a prefix of b, then a must appear before b in
 * the given dictionary.
 * If the order is invalid, return an empty string.
 * There may be multiple valid order of letters, return any one of them is
 * fine.
 * 
 * 
 */

// @lc code=start
class Solution {
    public String alienOrder(String[] words) {
        Map<Character, Set<Character>> graph = new HashMap<>();
        Map<Character, Integer> indegree = new HashMap<>();
        addChar(words[0],0,graph,indegree);
        for(int i=1;i<words.length;i++){
            int x = 0;
            for(x = 0;x<Math.min(words[i-1].length(),words[i].length());x++){
                char a = words[i-1].charAt(x);
                char b = words[i].charAt(x);
                if(!graph.containsKey(b)){
                    graph.put(b,new HashSet<>());
                    indegree.put(b,0);
                }
                if(a!=b){
                    if(!graph.get(a).contains(b)){
                        graph.get(a).add(b);
                        indegree.put(b, indegree.get(b)+1);                    
                    }
                    x++;
                    break;
                }
            }
            addChar(words[i],x,graph, indegree);
        }
        
        StringBuilder sb = new StringBuilder();
        Queue<Character> q = new LinkedList<>();
        for(Map.Entry<Character, Integer> entry: indegree.entrySet()){
            if(entry.getValue()==0){
                q.offer(entry.getKey());
            }
        }
        while(!q.isEmpty()){
            Character c = q.poll();
            sb.append(c);
            for(char neighbor: graph.get(c)){
                indegree.put(neighbor,indegree.get(neighbor)-1);
                if(indegree.get(neighbor)==0){
                    q.offer(neighbor);
                }
            }
        }
        if(sb.length()!=graph.size())
            return "";
        return sb.toString();
    }
    
    private void addChar(String word, int start, Map<Character, Set<Character>> graph, Map<Character, Integer> indegree){
        for(int i=start;i<word.length();i++){
            char c = word.charAt(i);
            if(!graph.containsKey(c)){
                graph.put(c, new HashSet<>());
                indegree.put(c,0);
            }
        }
    }
}
// @lc code=end

