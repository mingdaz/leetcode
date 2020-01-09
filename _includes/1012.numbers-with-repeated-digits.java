/*
 * @lc app=leetcode id=1012 lang=java
 *
 * [1012] Numbers With Repeated Digits
 *
 * https://leetcode.com/problems/numbers-with-repeated-digits/description/
 *
 * algorithms
 * Hard (36.25%)
 * Likes:    127
 * Dislikes: 38
 * Total Accepted:    3.9K
 * Total Submissions: 10.8K
 * Testcase Example:  '20'
 *
 * Given a positive integer N, return the number of positive integers less than
 * or equal to N that have at least 1 repeated digit.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 20
 * Output: 1
 * Explanation: The only positive number (<= 20) with at least 1 repeated digit
 * is 11.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 100
 * Output: 10
 * Explanation: The positive numbers (<= 100) with atleast 1 repeated digit are
 * 11, 22, 33, 44, 55, 66, 77, 88, 99, and 100.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 1000
 * Output: 262
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 10^9
 * 
 * 
 * 
 */

// @lc code=start
// 朴素DFS + memorization
class Solution {
    public int numDupDigitsAtMostN(int N) {
        boolean[] bitmap = new boolean[10];
        int[] visited = new int[N+1];
        Arrays.fill(visited, -1);
        return N + 1 - count( 0, N, bitmap, visited); 
    }

    private int count(long cur, long limit, boolean[] bitmap, int[] visited){
        if(cur > limit)
            return 0;
        int index = (int)cur;
        if(visited[index]>=0){
            return visited[index];
        }
        int ret = 1;
        for(int i=(cur==0?1:0);i<10;i++){
            if(bitmap[i]==false){
                bitmap[i] = true;
                ret += count(cur*10+i, limit, bitmap, visited);
                bitmap[i] = false;
            }
        }
        visited[index] = ret;
        return ret;
    }
}

// Method 2
class Solution {
    public int numDupDigitsAtMostN(int N) {
        // Transform N + 1 to arrayList
        // Possible Over Flow. Could transfer to Long first.
        char[] digits = String.valueOf(N + 1).toCharArray();

        // Count the number with digits < N
        int res = 0;

        for (int i = 1; i < digits.length; ++i) {
            res += 9 * A(9, i - 1);
        }

        // Count the number with same prefix
        Set<Integer> seen = new HashSet<>();
        for (int i = 0; i < digits.length; i++) {
            // Plus one at first to unify the solution j < digit[i] - '0';
            for (int j = i > 0 ? 0 : 1; j < digits[i] - '0'; j++) {
                if (!seen.contains(j)) {
                    res += A(9 - i, digits.length - i - 1);
                }
            }
            if (!seen.contains(digits[i] - '0')) {
                seen.add(digits[i] - '0');
            } else {
                break;
            }
        }
        return N - res;
    }
    // Did not take zero into count.
    public int A(int m, int n) {
        return n == 0 ? 1 : A(m, n - 1) * (m - n + 1);
    }
}
// @lc code=end

