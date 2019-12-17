import java.util.Queue;

import javax.swing.tree.TreeNode;

/*
 * @lc app=leetcode id=314 lang=java
 *
 * [314] Binary Tree Vertical Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-vertical-order-traversal/description/
 *
 * algorithms
 * Medium (42.69%)
 * Likes:    724
 * Dislikes: 136
 * Total Accepted:    91.4K
 * Total Submissions: 214K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the vertical order traversal of its nodes'
 * values. (ie, from top to bottom, column by column).
 * 
 * If two nodes are in the same row and column, the order should be from left
 * to right.
 * 
 * Examples 1:
 * 
 * 
 * Input: [3,9,20,null,null,15,7]
 * 
 * ⁠  3
 * ⁠ /\
 * ⁠/  \
 * ⁠9  20
 * ⁠   /\
 * ⁠  /  \
 * ⁠ 15   7 
 * 
 * Output:
 * 
 * [
 * ⁠ [9],
 * ⁠ [3,15],
 * ⁠ [20],
 * ⁠ [7]
 * ]
 * 
 * 
 * Examples 2:
 * 
 * 
 * Input: [3,9,8,4,0,1,7]
 * 
 * ⁠    3
 * ⁠   /\
 * ⁠  /  \
 * ⁠  9   8
 * ⁠ /\  /\
 * ⁠/  \/  \
 * ⁠4  01   7 
 * 
 * Output:
 * 
 * [
 * ⁠ [4],
 * ⁠ [9],
 * ⁠ [3,0,1],
 * ⁠ [8],
 * ⁠ [7]
 * ]
 * 
 * 
 * Examples 3:
 * 
 * 
 * Input: [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left
 * child is 5)
 * 
 * ⁠    3
 * ⁠   /\
 * ⁠  /  \
 * ⁠  9   8
 * ⁠ /\  /\
 * ⁠/  \/  \
 * ⁠4  01   7
 * ⁠   /\
 * ⁠  /  \
 * ⁠  5   2
 * 
 * Output:
 * 
 * [
 * ⁠ [4],
 * ⁠ [9,5],
 * ⁠ [3,0,1],
 * ⁠ [8,2],
 * ⁠ [7]
 * ]
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
    static class Pair{
        TreeNode node;
        int level;
        Pair(TreeNode node, int level){
            this.node = node;
            this.level = level;
        }
    }

    public List<List<Integer>> verticalOrder(TreeNode root) {
        List<List<Integer>> ret = new ArrayList<>();
        if(root ==null){
            return ret;
        }
        HashMap<Integer, List<Integer>> hm = new HashMap<>();
        int left = 0;
        int right = 0;
        Queue<Pair> q = new LinkedList<>();
        q.offer(new Pair(root,0));
        while(q.size()>0){
            Pair top = q.poll();
            TreeNode node = top.node;
            int level = top.level;
            if(!hm.containsKey(level)){
                hm.put(level, new ArrayList<>());
            }
            hm.get(level).add(node.val);
            if(level < left) left = level;
            if(level > right) right = level;
            if(node.left != null){
                q.offer(new Pair(node.left, level-1));
            }
            if(node.right != null){
                q.offer(new Pair(node.right, level+1));
            }
        }   
        for(int i=left;i<=right;i++){
            ret.add(hm.get(i));
        }
        return ret;
    }
}
// @lc code=end

