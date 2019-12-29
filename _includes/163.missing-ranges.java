/*
 * @lc app=leetcode id=163 lang=java
 *
 * [163] Missing Ranges
 *
 * https://leetcode.com/problems/missing-ranges/description/
 *
 * algorithms
 * Medium (23.61%)
 * Likes:    263
 * Dislikes: 1561
 * Total Accepted:    70.6K
 * Total Submissions: 298.6K
 * Testcase Example:  '[0,1,3,50,75]\n0\n99'
 *
 * Given a sorted integer array nums, where the range of elements are in the
 * inclusive range [lower, upper], return its missing ranges.
 * 
 * Example:
 * 
 * 
 * Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
 * Output: ["2", "4->49", "51->74", "76->99"]
 * 
 * 
 */

// @lc code=start
class Solution {
    public List<String> findMissingRanges(int[] nums, int lower, int upper) {
        List<String> ret = new ArrayList<>();
        int idx = 0;
        long point = lower;
        while(idx<nums.length && nums[idx]<=upper){
            if(nums[idx]<point){
                idx++;
            } else {
                if(nums[idx]-point==1){
                    ret.add(point+"");
                } else if(nums[idx]-point>1){
                    ret.add(point + "->" + (nums[idx] - 1));
                }
                if(nums[idx]==upper){
                    return ret;
                } 
                point = nums[idx] + 1;
            }
        } 
        if(idx == nums.length){
            if(point==upper){
                ret.add(point + "");
            } else {
                ret.add(point + "->" + upper);
            }
        }
        return ret;
    }
}
// @lc code=end

