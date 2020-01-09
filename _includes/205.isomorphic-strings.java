import java.util.Map;

/*
 * @lc app=leetcode id=205 lang=java
 *
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (38.69%)
 * Likes:    1042
 * Dislikes: 292
 * Total Accepted:    253.9K
 * Total Submissions: 654K
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 * 
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * 
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "egg", t = "add"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "foo", t = "bar"
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: s = "paper", t = "title"
 * Output: true
 * 
 * Note:
 * You may assume both s and t have the same length.
 * 
 */

// @lc code=start
class Solution {
    public boolean isIsomorphic(String ss, String tt) {
        if(ss==null || tt==null || ss.length()!=tt.length()) return false;
        Map<Character, Character> abmap = new HashMap<>();
        Map<Character, Character> bamap = new HashMap<>();
       
        char[] s = ss.toCharArray();
        char[] t = tt.toCharArray();
        for(int i=0;i<s.length;i++){
            char a = s[i];
            char b = t[i];
            if(!abmap.containsKey(a) && !bamap.containsKey(b)){
                abmap.put(a,b);
                bamap.put(b,a);
            } else {
                if(abmap.containsKey(a) && abmap.get(a)!=b){
                    return false;
                }
                if(bamap.containsKey(b) && bamap.get(b)!=a){
                    return false;
                }
            }

        }
        return true;
    }
}
// @lc code=end

