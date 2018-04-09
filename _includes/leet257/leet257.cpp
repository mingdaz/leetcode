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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if(root){
            path = to_string(root->val);
            if(!root->left&&!root->right) ret.push_back(path);
            else{
                if(root->left) helper(root->left,path,ret);
                if(root->right) helper(root->right,path,ret);
            }   
        }  
        return ret;
    }
private:
    string path = "";
    void helper(TreeNode* root, string& path, vector<string>& ret){
        if(root!=NULL){
            string temp = path;
            path+=("->"+to_string(root->val));
            if(!root->left&&!root->right) ret.push_back(path);
            else{
                if(root->left) helper(root->left,path,ret);
                if(root->right) helper(root->right,path,ret);
            }
            path = temp;
        }  
    }
};
