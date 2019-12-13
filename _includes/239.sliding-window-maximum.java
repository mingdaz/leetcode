import java.util.Deque;
import java.util.LinkedList;

/*
 * @lc app=leetcode id=239 lang=java
 *
 * [239] Sliding Window Maximum
 *
 * https://leetcode.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (40.16%)
 * Likes:    2348
 * Dislikes: 137
 * Total Accepted:    205.8K
 * Total Submissions: 512.3K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * Given an array nums, there is a sliding window of size k which is moving
 * from the very left of the array to the very right. You can only see the k
 * numbers in the window. Each time the sliding window moves right by one
 * position. Return the max sliding window.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
 * Output: [3,3,5,5,6,7] 
 * Explanation: 
 * 
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty
 * array.
 * 
 * Follow up:
 * Could you solve it in linear time?
 */

// @lc code=start
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        Deque<Integer> dq = new LinkedList<>();
        int n = nums.length;
        if(n==0||k==0) return new int[0];
        if(k==1) return nums;
        int max_ind = 0;
        int index = 0;
        for(int i=0;i<k;i++){
            cleam_deque(i,k, nums, dq);
            dq.addLast(i);
            if(nums[i]>nums[max_ind]) max_ind = i;
        }
        int[] ret = new int[n-k+1];
        ret[index++] = nums[max_ind];

        for(int i=k;i<nums.length;i++){
            cleam_deque(i,k, nums, dq);
            dq.addLast(i);
            ret[index++] = nums[dq.getFirst()];    
        }
        return ret;
    }

    private void cleam_deque(int i, int k, int[] nums, Deque<Integer> dq){
        if(dq.size()>0 && dq.getFirst()==i-k){
            dq.removeFirst();
        }
        while(dq.size()>0 && nums[dq.getLast()] < nums[i]){
            dq.removeLast();
        }
    }
}
// @lc code=end

