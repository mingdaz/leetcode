/*
 * @lc app=leetcode id=166 lang=java
 *
 * [166] Fraction to Recurring Decimal
 *
 * https://leetcode.com/problems/fraction-to-recurring-decimal/description/
 *
 * algorithms
 * Medium (20.40%)
 * Likes:    618
 * Dislikes: 1343
 * Total Accepted:    103.6K
 * Total Submissions: 507.5K
 * Testcase Example:  '1\n2'
 *
 * Given two integers representing the numerator and denominator of a fraction,
 * return the fraction in string format.
 * 
 * If the fractional part is repeating, enclose the repeating part in
 * parentheses.
 * 
 * Example 1:
 * 
 * 
 * Input: numerator = 1, denominator = 2
 * Output: "0.5"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: numerator = 2, denominator = 1
 * Output: "2"
 * 
 * Example 3:
 * 
 * 
 * Input: numerator = 2, denominator = 3
 * Output: "0.(6)"
 * 
 * 
 */

// @lc code=start
class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        
        StringBuilder res = new StringBuilder();
        
        if((numerator>0&&denominator<0)||(numerator<0&&denominator>0)) 
            res.append("-");
        
        long num = Math.abs((long)numerator);
        long den = Math.abs((long)denominator);
        
        // integral part
        res.append(num / den);
        num %= den;
        if (num == 0) return res.toString();
        
        // fractional part
        res.append(".");
        Map<Long, Integer> map = new HashMap<Long, Integer>();
        
        while (num != 0) {
            if (map.containsKey(num)) {
                int index = map.get(num);
                res.insert(index, "(");
                res.append(")");
                break;
            }
            map.put(num, res.length());
            num *= 10;
            res.append(num / den);
            num %= den;
        }
        return res.toString();
    }
}
// @lc code=end

