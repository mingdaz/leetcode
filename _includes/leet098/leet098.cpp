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
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        return dfs(root,NULL,NULL);
    }
private:
    bool dfs(TreeNode* root,TreeNode* minNode,TreeNode* maxNode){
        if(root->left) {
            if(root->left->val>=root->val||minNode!=NULL&&root->left->val<=minNode->val)
                return false;
            if(!dfs(root->left,minNode,root))
                return false;
        }
        if(root->right) {
            if(root->right->val<=root->val||maxNode!=NULL&&root->right->val>=maxNode->val)
                return false;
            if(!dfs(root->right,root,maxNode))
                return false;
        }
        return true;
    }    
};