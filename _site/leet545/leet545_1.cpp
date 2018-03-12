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
        if(!root) return res;
        res.push_back(root->val);
        TreeNode* temp= root->left;
        while(temp&&(temp->left||temp->right)){
            res.push_back(temp->val);
            if(temp->left) temp = temp->left;
            else if(temp->right) temp = temp->right;
        }
        
        if(root->left)dfs(res,root->left);
        if(root->right)dfs(res,root->right);
        
        stack<int> R;
        temp = root->right;
        while(temp&&(temp->left||temp->right)){
            R.push(temp->val);
            if(temp->right) temp = temp->right;
            else if(temp->left) temp = temp->left;
        }
        while(!R.empty()){
            res.push_back(R.top());
            R.pop();
        }
        return res;
    }
    void dfs(vector<int>& res,TreeNode* node){
        if(!node->left&&!node->right) res.push_back(node->val);
        else{
            if(node->left) dfs(res,node->left);
            if(node->right) dfs(res,node->right);
        }   
    }
};
