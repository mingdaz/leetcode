/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        int ret = 0;
        helper(root,1,ret);
        return ret;
    }
    
    void helper(TreeNode* root, int cur, int& max_len){
        if(root==NULL) return;
        if(root->left){
            helper(root->left,(root->left->val==root->val+1)?cur+1:1,max_len);    
        }
        if(root->right){
            helper(root->right,(root->right->val==root->val+1)?cur+1:1,max_len);    
        }
        if(cur > max_len){
            max_len = cur;
        }
    }
};
