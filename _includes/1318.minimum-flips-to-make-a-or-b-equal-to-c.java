/*
 * @lc app=leetcode id=1318 lang=java
 *
 * [1318] Minimum Flips to Make a OR b Equal to c
 *
 * https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/
 *
 * algorithms
 * Medium (57.60%)
 * Likes:    24
 * Dislikes: 4
 * Total Accepted:    4.3K
 * Total Submissions: 7.4K
 * Testcase Example:  '2\n6\n5'
 *
 * Given 3 positives numbers a, b and c. Return the minimum flips required in
 * some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
 * Flip operation consists of change any single bit 1 to 0 or change the bit 0
 * to 1 in their binary representation.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: a = 2, b = 6, c = 5
 * Output: 3
 * Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)
 * 
 * Example 2:
 * 
 * 
 * Input: a = 4, b = 2, c = 7
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: a = 1, b = 2, c = 3
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= a <= 10^9
 * 1 <= b <= 10^9
 * 1 <= c <= 10^9
 * 
 */

// @lc code=start
class Solution {
    public int minFlips(int a, int b, int c) {
        int cnt = 0;
        for(int i=0;i<32;i++){
            int cc = get(c,i);
            int aa = get(a,i);
            int bb = get(b,i);
            if(cc==1){
                if((aa | bb)==0)
                    cnt++;
            } else {
                
                if(aa==1) cnt++;
                if(bb==1) cnt++;
            }
        }
        return cnt;
    }
    
    private int get(int a, int i){
        return (a>>i) & 1;
    }
}
// @lc code=end

