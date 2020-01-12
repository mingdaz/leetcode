/*
 * @lc app=leetcode id=15 lang=java
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (25.33%)
 * Likes:    5274
 * Dislikes: 641
 * Total Accepted:    744K
 * Total Submissions: 2.9M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 */

// @lc code=start
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new LinkedList<>();
        Arrays.sort(nums);
        for(int i=0;i<nums.length-2;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            twoSum(-nums[i],i+1,nums.length-1, nums, res);
        }
        return res;
    }

    private void twoSum(int target, int l, int r, int[] nums, List<List<Integer>> res){
        while(l<r){
            int tmp = nums[l] + nums[r];
            if(tmp > target){
                r--;
            } else if(tmp < target){
                l++;
            } else {
                res.add(Arrays.asList(-target, nums[l], nums[r]));
                l++;
                r--;
                while(l<r&&nums[l]==nums[l-1]){
                    l++;
                }
                while(l<r&&nums[r]==nums[r+1]){
                    r--;
                }
            }
        }
    }
}
// @lc code=end

