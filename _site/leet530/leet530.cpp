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
    int getMinimumDifference(TreeNode* root) {
        res = INT_MAX;
        pre = NULL;
        helper(root);
        return res;
    }
private:
    int res;
    TreeNode* pre;
    void helper(TreeNode* root){
        if(root==NULL) return;
        helper(root->left);
        if(pre)
            res = min(res,root->val-pre->val);
        pre = root;
        helper(root->right);
    }
};
