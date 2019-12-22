/*
 * @lc app=leetcode id=215 lang=java
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (51.20%)
 * Likes:    2698
 * Dislikes: 203
 * Total Accepted:    488.4K
 * Total Submissions: 951.2K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 */

// @lc code=start
class Solution {
    public int findKthLargest(int[] nums, int k) {
        return select(nums,0,nums.length-1,k-1);
    }

    private int select(int[] nums, int l, int r, int k){
        if(l==r){
            return nums[l];
        }
        int pivot = k;
        pivot = partition(nums, l, r, pivot);
        if(k>pivot){
            return select(nums, pivot+1, r, k);
        } else if(k<pivot){
            return select(nums, l, pivot-1, k);
        } else {
            return nums[pivot];
        }

    }

    private int partition(int[] nums, int l, int r, int pivot){
        int val = nums[pivot];
        swap(nums,r,pivot);
        int index = l;
        for(int i=l;i<r;i++){
            if(nums[i]>val){
                swap(nums, i, index);
                index++;
            }
        }
        swap(nums, r, index);
        return index;
    }

    private void swap(int[] nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}
// @lc code=end

