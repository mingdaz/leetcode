/*
 * @lc app=leetcode id=150 lang=java
 *
 * [150] Evaluate Reverse Polish Notation
 *
 * https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
 *
 * algorithms
 * Medium (34.10%)
 * Likes:    732
 * Dislikes: 410
 * Total Accepted:    194.6K
 * Total Submissions: 568.5K
 * Testcase Example:  '["2","1","+","3","*"]'
 *
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * 
 * Valid operators are +, -, *, /. Each operand may be an integer or another
 * expression.
 * 
 * Note:
 * 
 * 
 * Division between two integers should truncate toward zero.
 * The given RPN expression is always valid. That means the expression would
 * always evaluate to a result and there won't be any divide by zero
 * operation.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["2", "1", "+", "3", "*"]
 * Output: 9
 * Explanation: ((2 + 1) * 3) = 9
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["4", "13", "5", "/", "+"]
 * Output: 6
 * Explanation: (4 + (13 / 5)) = 6
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
 * Output: 22
 * Explanation: 
 * ⁠ ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 * = ((10 * (6 / (12 * -11))) + 17) + 5
 * = ((10 * (6 / -132)) + 17) + 5
 * = ((10 * 0) + 17) + 5
 * = (0 + 17) + 5
 * = 17 + 5
 * = 22
 * 
 * 
 */

// @lc code=start
class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> st = new Stack<>();
        for(int i=0;i<tokens.length;i++){
            char c = tokens[i].charAt(0);
            if(tokens[i].length()==1 && !Character.isDigit(c)){
                int a = st.pop();
                int b = st.pop();
                int r = 0;
                if(c=='+'){
                    r = a+b;
                } else if(c=='-'){
                    r = b - a;
                } else if(c=='*'){
                    r = a*b;
                } else if(c=='/'){
                    r = b/a;
                }
                st.push(r);
            }else {
                st.push(Integer.parseInt(tokens[i]));
            }
        }
        return st.isEmpty()?-1:st.pop();
    }
}
// @lc code=end

