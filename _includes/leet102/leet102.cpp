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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root==NULL) return ret;
        queue<TreeNode*> Q;
        Q.push(root);
        int size = Q.size();
            
        while(size){
            vector<int> row;
            for(int i=0;i<size;i++){
                auto node = Q.front();
                Q.pop();
                row.push_back(node->val);
                if(node->left) Q.push(node->left);
                if(node->right) Q.push(node->right);
            }
            ret.push_back(row);
            size = Q.size();
        }
        return ret;
    }
};