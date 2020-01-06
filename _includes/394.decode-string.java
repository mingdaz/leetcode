/*
 * @lc app=leetcode id=394 lang=java
 *
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (47.34%)
 * Likes:    2237
 * Dislikes: 117
 * Total Accepted:    153.8K
 * Total Submissions: 323.9K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * Given an encoded string, return its decoded string.
 * 
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 * 
 * You may assume that the input string is always valid; No extra white spaces,
 * square brackets are well-formed, etc.
 * 
 * Furthermore, you may assume that the original data does not contain any
 * digits and that digits are only for those repeat numbers, k. For example,
 * there won't be input like 3a or 2[4].
 * 
 * Examples:
 * 
 * 
 * s = "3[a]2[bc]", return "aaabcbc".
 * s = "3[a2[c]]", return "accaccacc".
 * s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 * 
 * 
 * 
 * 
 */

// @lc code=start

//Recursive
class Solution {
    int i;
    public String decodeString(String s){
        i = 0;
        return dfs(s);
    }
    
    String dfs(String s){
        
        StringBuilder sb = new StringBuilder();
        for(;i<s.length();i++){
            if(s.charAt(i)>='0'&&s.charAt(i)<='9'){
                int start = i;
                while(s.charAt(i)>='0'&&s.charAt(i)<='9'){
                    i++;
                }
                int repeat = Integer.parseInt(s.substring(start,i));
                String str = dfs(s);
                for(int j=0;j<repeat;j++){
                    sb.append(str);
                }
            } else if(s.charAt(i)=='['){
                continue;
            } else if(s.charAt(i)==']'){
                return sb.toString();
            } else {
                sb.append(s.charAt(i));
            }
        }
        return sb.toString();
    }
}

//Stack

// @lc code=end

