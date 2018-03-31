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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        vector<int> cur;
        helper(ret,cur,root,sum);
        return ret;
    }
private: 
    void helper(vector<vector<int>>& ret, vector<int>& cur, TreeNode* root, int sum ){
        if(!root) return;
        sum -= root->val;
        if(!root->left&&!root->right){
            if(sum==0){
                cur.push_back(root->val);
                ret.push_back(cur);
                cur.pop_back();
            }
        }
        else{
            cur.push_back(root->val);
            if(root->left)helper(ret,cur,root->left,sum);
            if(root->right)helper(ret,cur,root->right,sum);
            cur.pop_back();

        }
   
    }
};