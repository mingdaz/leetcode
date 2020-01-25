import java.util.LinkedList;

/*
 * @lc app=leetcode id=254 lang=java
 *
 * [254] Factor Combinations
 *
 * https://leetcode.com/problems/factor-combinations/description/
 *
 * algorithms
 * Medium (45.79%)
 * Likes:    499
 * Dislikes: 23
 * Total Accepted:    64.6K
 * Total Submissions: 140.9K
 * Testcase Example:  '1'
 *
 * Numbers can be regarded as product of its factors. For example,
 * 
 * 
 * 8 = 2 x 2 x 2;
 * ⁠ = 2 x 4.
 * 
 * 
 * Write a function that takes an integer n and return all possible
 * combinations of its factors.
 * 
 * Note:
 * 
 * 
 * You may assume that n is always positive.
 * Factors should be greater than 1 and less than n.
 * 
 * 
 * Example 1: 
 * 
 * 
 * Input: 1
 * Output: []
 * 
 * 
 * Example 2: 
 * 
 * 
 * Input: 37
 * Output:[]
 * 
 * Example 3: 
 * 
 * 
 * Input: 12
 * Output:
 * [
 * ⁠ [2, 6],
 * ⁠ [2, 2, 3],
 * ⁠ [3, 4]
 * ]
 * 
 * Example 4: 
 * 
 * 
 * Input: 32
 * Output:
 * [
 * ⁠ [2, 16],
 * ⁠ [2, 2, 8],
 * ⁠ [2, 2, 2, 4],
 * ⁠ [2, 2, 2, 2, 2],
 * ⁠ [2, 4, 4],
 * ⁠ [4, 8]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
    public List<List<Integer>> getFactors(int n) {
        List<List<Integer>> res = new ArrayList<>();
        dfs(n, 2, res, new ArrayList<>());
        return res;
    }
    
    private void dfs(int n, int start, List<List<Integer>> res, List<Integer> path){
        for (int i = start; i <= (int)Math.sqrt(n); i++){
            if (n % i == 0){
                path.add(i);
                path.add(n / i);
                res.add(new ArrayList<>(path));
                path.remove(path.size() - 1);
                dfs(n / i, i, res, path);
                path.remove(path.size() - 1);
            }
        }
    }
}
// @lc code=end

