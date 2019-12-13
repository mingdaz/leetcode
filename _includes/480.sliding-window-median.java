/*
 * @lc app=leetcode id=480 lang=java
 *
 * [480] Sliding Window Median
 *
 * https://leetcode.com/problems/sliding-window-median/description/
 *
 * algorithms
 * Hard (34.67%)
 * Likes:    576
 * Dislikes: 60
 * Total Accepted:    35.9K
 * Total Submissions: 103.6K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * Median is the middle value in an ordered integer list. If the size of the
 * list is even, there is no middle value. So the median is the mean of the two
 * middle value.
 * Examples: 
 * [2,3,4] , the median is 3
 * [2,3], the median is (2 + 3) / 2 = 2.5 
 * 
 * Given an array nums, there is a sliding window of size k which is moving
 * from the very left of the array to the very right. You can only see the k
 * numbers in the window. Each time the sliding window moves right by one
 * position. Your job is to output the median array for each window in the
 * original array.
 * 
 * For example,
 * Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
 * 
 * 
 * Window position                Median
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       1
 * ⁠1 [3  -1  -3] 5  3  6  7       -1
 * ⁠1  3 [-1  -3  5] 3  6  7       -1
 * ⁠1  3  -1 [-3  5  3] 6  7       3
 * ⁠1  3  -1  -3 [5  3  6] 7       5
 * ⁠1  3  -1  -3  5 [3  6  7]      6
 * 
 * 
 * Therefore, return the median sliding window as [1,-1,-1,3,5,6].
 * 
 * Note: 
 * You may assume k is always valid, ie: k is always smaller than input array's
 * size for non-empty array.
 */

// @lc code=start
class Solution {
    public double[] medianSlidingWindow(int[] nums, int k) {
        PriorityQueue<Integer> max = new PriorityQueue<>((a, b) -> (b.compareTo(a)));
        PriorityQueue<Integer> min = new PriorityQueue<>((a, b) -> (a.compareTo(b)));        
        double[] res = new double[nums.length - k + 1];
        for (int i = 0; i < nums.length; i++) {
            max.offer(nums[i]); min.offer(max.poll());
            while (min.size() > max.size() + 1) max.offer(min.poll());
            if (i >= k - 1) {
                double m = median(max, min); res[i - k + 1] = m;
                if (nums[i - k + 1] < m) max.remove(nums[i - k + 1]);
                else min.remove(nums[i - k + 1]);                
            }
        }
        return res;
    }
    
    private double median(PriorityQueue<Integer> max, PriorityQueue<Integer> min) {
        if (max.isEmpty() && min.isEmpty()) return 0;
        //return max.size() == min.size() ?  (double) (max.peek() + min.peek()) / 2 : min.peek();
        if (max.size() == min.size()) {            
            double sum = (double)max.peek() + (double)min.peek();
            return sum / 2;
        } else return min.peek();
    }
}
// @lc code=end

