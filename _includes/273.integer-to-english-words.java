/*
 * @lc app=leetcode id=273 lang=java
 *
 * [273] Integer to English Words
 *
 * https://leetcode.com/problems/integer-to-english-words/description/
 *
 * algorithms
 * Hard (25.58%)
 * Likes:    739
 * Dislikes: 2089
 * Total Accepted:    135.8K
 * Total Submissions: 530.7K
 * Testcase Example:  '123'
 *
 * Convert a non-negative integer to its english words representation. Given
 * input is guaranteed to be less than 2^31 - 1.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: "One Hundred Twenty Three"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 12345
 * Output: "Twelve Thousand Three Hundred Forty Five"
 * 
 * Example 3:
 * 
 * 
 * Input: 1234567
 * Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty
 * Seven"
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: 1234567891
 * Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty
 * Seven Thousand Eight Hundred Ninety One"
 * 
 * 
 */

// @lc code=start
import java.util.Arrays;

import javafx.util.Pair;
class Solution {

    private List<Pair<Integer, String>> level = Arrays.asList(new Pair(1000000000,"Billion "), 
    new Pair(1000000, "Million "), 
    new Pair(1000, "Thousand "));  
    private static final String[] Tens = {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty", "Ninety"};
    private static final String[] Small = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight", "Nine", "Ten",
"Eleven","Twelve","Thirteen", "Fourteen", "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    
    public String numberToWords(int num) {
        if(num==0) return Small[0];
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<level.size();i++){
            int n = level.get(i).getKey();
            String name = level.get(i).getValue();
            if(num >= n){
                generate(num/n, sb);
                sb.append(name);    
                num %= n;
            }   
        }
        if(num!=0){
            generate(num, sb);
        }
        return sb.substring(0, sb.length()-1);
    }

    private void generate(int num, StringBuilder sb){
        if(num >= 100){
            sb.append(Small[num/100] + " Hundred ");
            num %= 100;
        }
        if(num >=20){
            sb.append(Tens[num/10] + " ");
            num %= 10;
        }
        if(num!=0)
            sb.append(Small[num] + " ");
    }
}
// Solution II
class Solution {
    String[] BELOW_TEN={"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    String[] BELOW_TWENTY = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    String[] TENS = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    public String numberToWords(int num) {
        if(num==0) return "Zero";
        return help(num);
    }
    
    public String help(int num){
        String res = "";
        if(num<10)
            return BELOW_TEN[num];
        if(num<20)
            return BELOW_TWENTY[num-10];
        if(num<100)
            res = TENS[num/10] + " " + help(num%10);
        else if(num<1000)
            res = help(num/100) + " Hundred "+help(num%100);
        else if(num<1000000)
            res = help(num/1000)+ " Thousand "+help(num%1000);
        else if(num<1000000000)
            res = help(num/1000000)+" Million "+help(num%1000000);
        else
            res = help(num/1000000000)+" Billion "+help(num%1000000000);
        return res.trim();
    }
}
// @lc code=end

