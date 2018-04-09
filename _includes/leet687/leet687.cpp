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
    int longestUnivaluePath(TreeNode* root) {
        if (!root) { return 0; }
        int res = 0;
        countLength(res, root);
        return res;
    }
    
private:
    int countLength(int& res, TreeNode* root) {
        if (!root) { return 0; }
        int l = countLength(res, root->left);
        int r = countLength(res, root->right);
        int resL = (root->left && root->val == root->left->val)? l + 1 : 0;
        int resR = (root->right && root->val == root->right->val)? r + 1 : 0;
        res = max(res, resL + resR);
        return max(resL, resR);
    }
};
