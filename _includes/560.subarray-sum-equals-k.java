import java.util.Arrays;
import java.util.Map;

/*
 * @lc app=leetcode id=560 lang=java
 *
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (43.32%)
 * Likes:    3028
 * Dislikes: 85
 * Total Accepted:    179.7K
 * Total Submissions: 414.4K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * Given an array of integers and an integer k, you need to find the total
 * number of continuous subarrays whose sum equals to k.
 * 
 * Example 1:
 * 
 * Input:nums = [1,1,1], k = 2
 * Output: 2
 * 
 * 
 * 
 * Note:
 * 
 * The length of the array is in range [1, 20,000].
 * The range of numbers in the array is [-1000, 1000] and the range of the
 * integer k is [-1e7, 1e7].
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
    public int subarraySum(int[] nums, int k) {
        // Sum to Cnt
        Map<Integer,Integer> map = new HashMap<>();
        map.put(0,1);
        int sum = 0;
        int cnt = 0;
        for(int i=0;i<nums.length;i++){
            sum += nums[i];
            int target = sum - k;
            if(map.containsKey(target)){
                cnt += map.get(target);
            }
            map.put(sum, map.getOrDefault(sum, 0)+1);;
        }
        return cnt;
    }
}
// @lc code=end

