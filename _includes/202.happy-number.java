import java.util.Set;

/*
 * @lc app=leetcode id=202 lang=java
 *
 * [202] Happy Number
 *
 * https://leetcode.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (47.60%)
 * Likes:    1301
 * Dislikes: 313
 * Total Accepted:    309.2K
 * Total Submissions: 643.9K
 * Testcase Example:  '19'
 *
 * Write an algorithm to determine if a number is "happy".
 * 
 * A happy number is a number defined by the following process: Starting with
 * any positive integer, replace the number by the sum of the squares of its
 * digits, and repeat the process until the number equals 1 (where it will
 * stay), or it loops endlessly in a cycle which does not include 1. Those
 * numbers for which this process ends in 1 are happy numbers.
 * 
 * Example: 
 * 
 * 
 * Input: 19
 * Output: true
 * Explanation: 
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 * 
 */

// @lc code=start
class Solution {
    public boolean isHappy(int n) {
        Set<Integer> visited = new HashSet<>();
        while(n!=1){
            if(visited.contains(n)){
                return false;
            }
            visited.add(n);
            n = getNext(n);
        }
        return true;
    }

    private int getNext(int n){
        int ret = 0;
        while(n!=0){
            int d = n%10;
            n /= 10;
            ret += (d*d);
        }
        return ret;
    }
}
// @lc code=end

