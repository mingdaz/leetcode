/*
 * @lc app=leetcode id=364 lang=java
 *
 * [364] Nested List Weight Sum II
 *
 * https://leetcode.com/problems/nested-list-weight-sum-ii/description/
 *
 * algorithms
 * Medium (60.76%)
 * Likes:    438
 * Dislikes: 108
 * Total Accepted:    51.4K
 * Total Submissions: 84.6K
 * Testcase Example:  '[[1,1],2,[1,1]]'
 *
 * Given a nested list of integers, return the sum of all integers in the list
 * weighted by their depth.
 * 
 * Each element is either an integer, or a list -- whose elements may also be
 * integers or other lists.
 * 
 * Different from the previous question where weight is increasing from root to
 * leaf, now the weight is defined from bottom up. i.e., the leaf level
 * integers have weight 1, and the root level integers have the largest
 * weight.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: [[1,1],2,[1,1]]
 * Output: 8 
 * Explanation: Four 1's at depth 1, one 2 at depth 2.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,[4,[6]]]
 * Output: 17 
 * Explanation: One 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 1*3 +
 * 4*2 + 6*1 = 17.
 * 
 * 
 * 
 * 
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *     // Constructor initializes an empty nested list.
 *     public NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     public NestedInteger(int value);
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // Set this NestedInteger to hold a single integer.
 *     public void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     public void add(NestedInteger ni);
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
class Solution {
    public int depthSumInverse(List<NestedInteger> nestedList) {
        return level( nestedList, 0);
    }

    private int level( List<NestedInteger> nestedList, int sum){
        if(nestedList.isEmpty()) return sum;
        int cur = sum;
        List<NestedInteger> next = new LinkedList<NestedInteger>();
        for(NestedInteger nested: nestedList){
            if(nested.isInteger()){
                sum += nested.getInteger();
            } else {
                next.addAll(nested.getList());
            }
        }
        return cur + level(next,sum);
    }
}

class SolutionII {
    public int depthSumInverse(List<NestedInteger> nestedList) {
        
        int cur = 0, sum = 0;
        while(!nestedList.isEmpty()){
            List<NestedInteger> next = new LinkedList<NestedInteger>();
            for(NestedInteger nested: nestedList){
                if(nested.isInteger()){
                    cur += nested.getInteger();
                } else {
                    next.addAll(nested.getList());
                }
            }
            sum += cur;
            nestedList = next;
        }
        return sum;
    }
}
// @lc code=end

