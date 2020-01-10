/*
 * @lc app=leetcode id=34 lang=java
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int l = 0;
        int r = nums.length -1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] > target){
                r = mid - 1;
            } else if(nums[mid] < target) {
                l = mid + 1;
            } else {
                l = mid;
                r = mid;
                while(l>0 && nums[l-1]==target) l--;
                while(r<nums.length-1 && nums[r+1]==target) r++;
                return new int[]{l,r};
            }
        }
        return new int[]{-1,-1};
    }
}
// @lc code=end

