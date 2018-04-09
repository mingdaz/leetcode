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
    int minDiffInBST(TreeNode* root) {
        int res = INT_MAX;
        TreeNode* prev = NULL;
        inorder(root,prev,res);
        return res;
    }
    
    void inorder(TreeNode* root, TreeNode*& prev, int& res){
        if(!root){
            return;
        }
        if(root->left){
            inorder(root->left,prev,res);
        } 
        if(prev){
            res = min(res,root->val - prev->val);
        }
        prev = root;
        if(root->right){
            inorder(root->right,prev,res);
        }
    }
    
    
};