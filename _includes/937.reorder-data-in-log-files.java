import java.util.Comparator;

/*
 * @lc app=leetcode id=937 lang=java
 *
 * [937] Reorder Data in Log Files
 *
 * https://leetcode.com/problems/reorder-data-in-log-files/description/
 *
 * algorithms
 * Easy (53.66%)
 * Likes:    394
 * Dislikes: 1215
 * Total Accepted:    75K
 * Total Submissions: 139.7K
 * Testcase Example:  '["dig1 8 1 5 1","let1 art can","dig2 3 ' +
  '6","let2 own kit dig","let3 art zero"]'
 *
 * You have an array of logs.  Each log is a space delimited string of words.
 * 
 * For each log, the first word in each log is an alphanumeric identifier.
 * Then, either:
 * 
 * 
 * Each word after the identifier will consist only of lowercase letters,
 * or;
 * Each word after the identifier will consist only of digits.
 * 
 * 
 * We will call these two varieties of logs letter-logs and digit-logs.  It is
 * guaranteed that each log has at least one word after its identifier.
 * 
 * Reorder the logs so that all of the letter-logs come before any digit-log.
 * The letter-logs are ordered lexicographically ignoring identifier, with the
 * identifier used in case of ties.  The digit-logs should be put in their
 * original order.
 * 
 * Return the final order of the logs.
 * 
 * 
 * Example 1:
 * Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit
 * dig","let3 art zero"]
 * Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5
 * 1","dig2 3 6"]
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= logs.length <= 100
 * 3 <= logs[i].length <= 100
 * logs[i] is guaranteed to have an identifier, and a word after the
 * identifier.
 * 
 * 
 */

// @lc code=start
class Solution {
    public String[] reorderLogFiles(String[] logs) {
        Arrays.sort(logs, new Cmp());
        return logs;
    }
}

class Cmp implements Comparator<String> {
    public int compare(String a, String b){
        int i = a.indexOf(' ');
        int j = b.indexOf(' ');
        i++;
        j++;
        boolean ta = Character.isDigit(a.charAt(i));
        boolean tb = Character.isDigit(b.charAt(j));

        if(ta&&tb) return 0;
        else if(ta&&!tb) return 1;
        else if(!ta&&tb) return -1;
        else {
            int res = a.substring(i).compareTo(b.substring(j));
            if(res==0) return a.compareTo(b);
            return res;
        }
    }
}
// @lc code=end

