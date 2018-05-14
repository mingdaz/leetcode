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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(root==NULL) return NULL;
        if(root->left==NULL)
            return root;
        TreeNode* tmp = root->left;
        TreeNode* ret = upsideDownBinaryTree(root->left);
        tmp->left = root->right;
        tmp->right = root;
        root->left = NULL;
        root->right = NULL;
        return ret;
    }
};