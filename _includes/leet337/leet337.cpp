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
    int rob(TreeNode* root) {
        int incl = 0,excl = 0;
        if(root) dfs(root,incl,excl);
        return max(incl,excl);
    }
private:
    void dfs(TreeNode* root, int& incl, int& excl){
        int incl_l = 0, excl_l = 0, incl_r = 0, excl_r = 0;
        if(root->left) dfs(root->left,incl_l,excl_l);
        if(root->right) dfs(root->right,incl_r,excl_r);
        incl = root->val+ excl_l+ excl_r ;
        excl = max(incl_l,excl_l)+max(incl_r,excl_r);
    }
};