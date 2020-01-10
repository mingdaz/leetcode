/*
 * @lc app=leetcode id=68 lang=java
 *
 * [68] Text Justification
 *
 * https://leetcode.com/problems/text-justification/description/
 *
 * algorithms
 * Hard (25.12%)
 * Likes:    493
 * Dislikes: 1290
 * Total Accepted:    115.8K
 * Total Submissions: 455.3K
 * Testcase Example:  '["This", "is", "an", "example", "of", "text", "justification."]\n16'
 *
 * Given an array of words and a width maxWidth, format the text such that each
 * line has exactly maxWidth characters and is fully (left and right)
 * justified.
 * 
 * You should pack your words in a greedy approach; that is, pack as many words
 * as you can in each line. Pad extra spaces ' ' when necessary so that each
 * line has exactly maxWidth characters.
 * 
 * Extra spaces between words should be distributed as evenly as possible. If
 * the number of spaces on a line do not divide evenly between words, the empty
 * slots on the left will be assigned more spaces than the slots on the right.
 * 
 * For the last line of text, it should be left justified and no extra space is
 * inserted between words.
 * 
 * Note:
 * 
 * 
 * A word is defined as a character sequence consisting of non-space characters
 * only.
 * Each word's length is guaranteed to be greater than 0 and not exceed
 * maxWidth.
 * The input array words contains at least one word.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * words = ["This", "is", "an", "example", "of", "text", "justification."]
 * maxWidth = 16
 * Output:
 * [
 * "This    is    an",
 * "example  of text",
 * "justification.  "
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * words = ["What","must","be","acknowledgment","shall","be"]
 * maxWidth = 16
 * Output:
 * [
 * "What   must   be",
 * "acknowledgment  ",
 * "shall be        "
 * ]
 * Explanation: Note that the last line is "shall be    " instead of "shall
 * be",
 * because the last line must be left-justified instead of fully-justified.
 * ⁠            Note that the second line is also left-justified becase it
 * contains only one word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * words =
 * ["Science","is","what","we","understand","well","enough","to","explain",
 * "to","a","computer.","Art","is","everything","else","we","do"]
 * maxWidth = 20
 * Output:
 * [
 * "Science  is  what we",
 * ⁠ "understand      well",
 * "enough to explain to",
 * "a  computer.  Art is",
 * "everything  else  we",
 * "do                  "
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> res = new ArrayList<>();
        int i = 0;
        int curLen =  0;
        while(i<words.length){
            int j = i;
            while(j <words.length && 
            (curLen + words[j].length() + (curLen==0?0:1)) <= maxWidth ){
                curLen = curLen + words[j].length() + (curLen==0?0:1);
                j++;
            }
            int k = j-i;
            StringBuilder sb = new StringBuilder();
            if(k==1){
                // line contain only one word
                sb.append(words[i]);
                while(sb.length()<maxWidth){
                    sb.append(' ');
                }
                res.add(sb.toString());
            } else if(j==words.length) {
                // last line
                sb.append(words[i]);
                for(int t=i+1;t<j;t++){
                    sb.append(' ');
                    sb.append(words[t]);
                }
                while(sb.length()<maxWidth){
                    sb.append(' ');
                }
                res.add(sb.toString());
            } else {
                k--;
                int whiteSpace = maxWidth - curLen + k;
                int extraSpace = whiteSpace % k;
                int averageSpace = whiteSpace / k;
                sb.append(words[i]);
                for(int t=i+1;t<j;t++){
                    for(int r = 0;r<averageSpace;r++)
                        sb.append(' ');
                    if(t<=i+extraSpace)
                        sb.append(' ');
                    sb.append(words[t]);
                }
                res.add(sb.toString());   
            }
            i = j;
            curLen = 0;
        }
        return res;
    }
}
// @lc code=end

