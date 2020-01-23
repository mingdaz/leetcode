/*
 * @lc app=leetcode id=1324 lang=java
 *
 * [1324] Print Words Vertically
 *
 * https://leetcode.com/problems/print-words-vertically/description/
 *
 * algorithms
 * Medium (59.30%)
 * Likes:    39
 * Dislikes: 24
 * Total Accepted:    6.1K
 * Total Submissions: 10.3K
 * Testcase Example:  '"HOW ARE YOU"'
 *
 * Given a string s. Return all the words vertically in the same order in which
 * they appear in s.
 * Words are returned as a list of strings, complete with spaces when is
 * necessary. (Trailing spaces are not allowed).
 * Each word would be put on only one column and that in one column there will
 * be only one word.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "HOW ARE YOU"
 * Output: ["HAY","ORO","WEU"]
 * Explanation: Each word is printed vertically. 
 * ⁠"HAY"
 * "ORO"
 * "WEU"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "TO BE OR NOT TO BE"
 * Output: ["TBONTB","OEROOE","   T"]
 * Explanation: Trailing spaces is not allowed. 
 * "TBONTB"
 * "OEROOE"
 * "   T"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "CONTEST IS COMING"
 * Output: ["CIC","OSO","N M","T I","E N","S G","T"]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 200
 * s contains only upper case English letters.
 * It's guaranteed that there is only one space between 2 words.
 * 
 */

// @lc code=start
import java.util.StringTokenizer;
class Solution {
    public List<String> printVertically(String s) {
        StringTokenizer st = new StringTokenizer(s);
        int maxL = -1;
        int cnt = 0;
        List<StringBuilder> sbList = new ArrayList<>();
        while(st.hasMoreTokens()){
            String next = st.nextToken();
            for(int i=0;i<next.length();i++){
                StringBuilder sb;
                if(i>maxL){
                    sb = new StringBuilder();
                } else {
                    sb = sbList.get(i);
                }
                for(int j=sb.length();j<cnt;j++){
                    sb.append(' ');
                }
                sb.append(next.charAt(i));
                if(i>maxL){
                    sbList.add(sb);
                }
                
            }
            cnt++;
            maxL = Math.max(maxL,next.length()-1);
        }
        List<String> res = new ArrayList<>();
        for(StringBuilder sb: sbList){
            String str = trim(sb);
            res.add(str);
        }
        return res;
    }
    
    private String trim(StringBuilder sb){
        int i = sb.length()-1;
        while(i>=0&&sb.charAt(i)==' '){
            i--;
        }
        return sb.substring(0,i+1);
    }
}
// @lc code=end

