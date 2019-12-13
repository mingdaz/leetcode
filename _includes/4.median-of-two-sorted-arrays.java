/*
 * @lc app=leetcode id=4 lang=java
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (27.89%)
 * Likes:    5493
 * Dislikes: 812
 * Total Accepted:    554.8K
 * Total Submissions: 2M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */

// @lc code=start
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if(nums1.length > nums2.length){
            return findMedianSortedArrays(nums2, nums1);
        }
        int m = nums1.length;
        int n = nums2.length;
        int low = 0;
        int high = m;
        while(low<=high){
            int cutX = (low + high)/2;
            int cutY = (m+n+1)/2 - cutX;
            int leftX = cutX==0 ? Integer.MIN_VALUE: nums1[cutX-1];
            int rightX = cutX==m ? Integer.MAX_VALUE: nums1[cutX];
            int leftY = cutY==0 ? Integer.MIN_VALUE: nums2[cutY-1];
            int rightY = cutY==n ? Integer.MAX_VALUE: nums2[cutY];
            if(leftY<=rightX && leftX<=rightY){
                //solution found
                if((m+n) %2==0){
                    //even number
                    return (Math.max(leftX, leftY) + Math.min(rightX, rightY))/2.0;
                } else {
                    return Math.max(leftX, leftY);
                }
            } else if(leftX > rightY){
                high = cutX - 1;
            } else{
                low = cutX + 1;
            }
        }
        return -1;
    }
}
// @lc code=end∏

