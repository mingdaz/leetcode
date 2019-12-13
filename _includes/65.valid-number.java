import javax.lang.model.util.ElementScanner6;

/*
 * @lc app=leetcode id=65 lang=java
 *
 * [65] Valid Number
 *
 * https://leetcode.com/problems/valid-number/description/
 *
 * algorithms
 * Hard (14.57%)
 * Likes:    555
 * Dislikes: 3964
 * Total Accepted:    144.6K
 * Total Submissions: 992.7K
 * Testcase Example:  '"0"'
 *
 * Validate if a given string can be interpreted as a decimal number.
 * 
 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * " -90e3   " => true
 * " 1e" => false
 * "e3" => false
 * " 6e-1" => true
 * " 99e2.5 " => false
 * "53.5e93" => true
 * " --6 " => false
 * "-+3" => false
 * "95a54e53" => false
 * 
 * Note: It is intended for the problem statement to be ambiguous. You should
 * gather all requirements up front before implementing one. However, here is a
 * list of characters that can be in a valid decimal number:
 * 
 * 
 * Numbers 0-9
 * Exponent - "e"
 * Positive/negative sign - "+"/"-"
 * Decimal point - "."
 * 
 * 
 * Of course, the context of these characters also matters in the input.
 * 
 * Update (2015-02-10):
 * The signature of the C++ function had been updated. If you still see your
 * function signature accepts a const char * argument, please click the reload
 * button to reset your code definition.
 * 
 */

// @lc code=start
class Solution {
    public boolean isNumber(String s) {
        int status = 0;
        for(char c: s.toCharArray()){
            if(c==' '){
                if(status!=0 && status != 10){
                    if(status==2||status==3||status==4||status==7 ){
                        status = 10;
                    } else {
                        return false;
                    }
                }
            } else if(c=='+' || c=='-'){
                if(status == 0){
                    status = 1;
                } else if(status==5){
                    status = 6;
                } else{
                    return false;
                }
            } else if(c>='0'&&c<='9'){
                if(status <=2){
                    status = 2;
                } else if(status<=4){
                    status = 4;
                } else if(status<=7){
                    status = 7;
                } else if(status==11){
                    status = 4;
                } else {
                    return false;
                }
            } else if(c=='.'){
                if(status==2){
                    status = 3;
                } else if(status<2){
                    status = 11;
                }else {
                    return false;
                }
            } else if(c=='e'){
                if(status>=2&&status<=4){
                    status =5;
                } else{
                    return false;
                }
            } else {
                return false;
            }
        }
        if(status==2||status==3||status==4||status==7 || status==10)
            return true;
        return false;
    }
}
// @lc code=end

