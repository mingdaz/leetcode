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
    int kthSmallest(TreeNode* root, int k) {
        int res;
        inorder(root,k,res);
        return res;
    }
    void inorder(TreeNode* root, int& k, int& res){
        if(root==NULL||k==0) return;
        inorder(root->left,k,res);
        if(k==1){
            res = root->val;
            k--;
            return;
        } 
        else if(k==0) return;
        else k--;
        inorder(root->right,k,res);
    }
};
