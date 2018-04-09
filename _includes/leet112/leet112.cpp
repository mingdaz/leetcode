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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        sum -= root->val;
        if(sum==0){
            if(!root->left&&!root->right) return true;
        }
        if(root->left&&hasPathSum(root->left,sum)) return true;
        if(root->right&&hasPathSum(root->right,sum)) return true;
        return false;
        
    }
};