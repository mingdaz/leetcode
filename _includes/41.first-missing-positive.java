/*
 * @lc app=leetcode id=41 lang=java
 *
 * [41] First Missing Positive
 *
 * https://leetcode.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (30.29%)
 * Likes:    2344
 * Dislikes: 676
 * Total Accepted:    264.6K
 * Total Submissions: 873.5K
 * Testcase Example:  '[1,2,0]'
 *
 * Given an unsorted integer array, find the smallest missing positive
 * integer.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,0]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,4,-1,1]
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [7,8,9,11,12]
 * Output: 1
 * 
 * 
 * Note:
 * 
 * Your algorithm should run in O(n) time and uses constant extra space.
 * 
 */

// @lc code=start
public class Solution {

    public int firstMissingPositive(int[] A) {
        if(A== null) return 1;
        int n = A.length;
        for(int i=0;i<n;i++){
            while(A[i]>0 && A[i]<=n){
                int tmp = A[A[i] - 1];
                if(tmp==A[i])
                    break;
                A[A[i] - 1] = A[i];
                A[i] = tmp;
            }
        }
        for(int i=0;i<n;i++){
            if(A[i]!= i+1)
                return i+1;
        }
        return n+1;
    }
}
// @lc code=end

