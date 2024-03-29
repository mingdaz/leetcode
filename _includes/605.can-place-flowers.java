/*
 * @lc app=leetcode id=605 lang=java
 *
 * [605] Can Place Flowers
 *
 * https://leetcode.com/problems/can-place-flowers/description/
 *
 * algorithms
 * Easy (31.49%)
 * Likes:    621
 * Dislikes: 317
 * Total Accepted:    83.6K
 * Total Submissions: 265.2K
 * Testcase Example:  '[1,0,0,0,1]\n1'
 *
 * Suppose you have a long flowerbed in which some of the plots are planted and
 * some are not. However, flowers cannot be planted in adjacent plots - they
 * would compete for water and both would die.
 * 
 * Given a flowerbed (represented as an array containing 0 and 1, where 0 means
 * empty and 1 means not empty), and a number n, return if n new flowers can be
 * planted in it without violating the no-adjacent-flowers rule.
 * 
 * Example 1:
 * 
 * Input: flowerbed = [1,0,0,0,1], n = 1
 * Output: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: flowerbed = [1,0,0,0,1], n = 2
 * Output: False
 * 
 * 
 * 
 * Note:
 * 
 * The input array won't violate no-adjacent-flowers rule.
 * The input array size is in the range of [1, 20000].
 * n is a non-negative integer which won't exceed the input array size.
 * 
 * 
 */

// @lc code=start
class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        for(int i=0;i<flowerbed.length&&n>0;i++){
            if(flowerbed[i]==0){
                if((i-1<0 || flowerbed[i-1]==0)&&(i+1>=flowerbed.length || flowerbed[i+1]==0)){
                    n--;
                    flowerbed[i] = 1;
                }
            } 
        }
        return n==0;
    }
}
// @lc code=end

