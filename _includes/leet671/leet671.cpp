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
    int findSecondMinimumValue(TreeNode* root) {
        if(root==NULL||root->left==NULL) return -1;
        int left,right;
        if(root->val==root->left->val){
            left = findSecondMinimumValue(root->left);
        }
        else{
            left = root->left->val;
        }
        if(root->val==root->right->val){
            right = findSecondMinimumValue(root->right);
        }
        else {
            right = root->right->val;            
        }
        if(left>0&&right>0)
            return min(left,right);
        return max(left,right);
    }

};