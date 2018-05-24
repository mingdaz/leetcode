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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if(root==NULL)
            return res;
        res.push_back(root->val);
        dfs(res,root->left,1);
        dfs(res,root->right,2);
        return res;
    }
private:
    void dfs(vector<int>& res, TreeNode* node, int type){
        if(node==NULL)
            return;
        if(node->left==NULL&&node->right==NULL){
            res.push_back(node->val);
            return;
        }
        if(type==1){
            res.push_back(node->val);
            if(node->left==NULL)
                dfs(res,node->right,1);
            else{
                dfs(res,node->left,1);           
                dfs(res,node->right,0);                
            }
        }
        else if(type==2){
            if(node->right==NULL)
                dfs(res,node->left,2);
            else{
                dfs(res,node->left,0);
                dfs(res,node->right,2);    
            }
            res.push_back(node->val);
        }
        else{
            dfs(res,node->left,0);
            dfs(res,node->right,0);    
        }
    }
};