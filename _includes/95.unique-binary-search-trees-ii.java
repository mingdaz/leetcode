/*
 * @lc app=leetcode id=95 lang=java
 *
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (37.72%)
 * Likes:    1625
 * Dislikes: 133
 * Total Accepted:    161.6K
 * Total Submissions: 428.2K
 * Testcase Example:  '3'
 *
 * Given an integer n, generate all structurally unique BST's (binary search
 * trees) that store values 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * Explanation:
 * The above output corresponds to the 5 unique BST's shown below:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    
    public List<TreeNode> generateTrees(int n) {
        return helper(1,n+1);
    }
    private List<TreeNode> helper(int start, int end){
        List<TreeNode> ret= new ArrayList<>();
        for(int i=start;i<end;i++){
            List<TreeNode> left = helper(start, i);
            List<TreeNode> right = helper(i+1, end);
            
            if(left.size()==0){
                if(right.size()==0){
                    ret.add(new TreeNode(i));
                } else {
                    for(TreeNode node: right){
                        TreeNode root = new TreeNode(i);
                        root.right = node;
                        ret.add(root);
                    }
                }
            } else {
                if(right.size()==0){
                    for(TreeNode node: left){
                        TreeNode root = new TreeNode(i);
                        root.left = node;
                        ret.add(root);
                    }
                } else {
                    for(TreeNode l: left){
                        for(TreeNode r: right){
                            TreeNode root = new TreeNode(i);
                            root.left = l;
                            root.right = r;
                            ret.add(root);
                        }
                    }
                }
            }
        }
        return ret;
    }
}
// @lc code=end

