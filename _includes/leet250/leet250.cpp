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
    int count = 0;
public:
    int countUnivalSubtrees(TreeNode* root) {
        Unival(root);
        return count;
    }
    
    bool Unival(TreeNode* root){
        bool left = true;
        bool right = true;
        if(!root) return true;
        if(root->left){
            left = Unival(root->left);
            if(root->val!=root->left->val)
                left = false;
        }       
        if(root->right){
            right = Unival(root->right);
            if(root->val!=root->right->val)
                right = false;
        }       
        if(left&&right) count++;
        return left&&right;
    }
};
