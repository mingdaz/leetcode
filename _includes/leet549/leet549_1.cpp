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
    int longestConsecutive(TreeNode* root) {
        int res = 0;
        helper(root,res, NULL);
        return res;
    }
private:
    int helper(TreeNode* root, int& res, TreeNode* parent){
        if(root==NULL) return 0;
        int l = helper(root->left,res,root);
        int r = helper(root->right,res,root);
        if((root->left&&root->right)&&
           (root->left->val - root->val == root->val - root->right->val)){
                res = max(l+r+1,res);
        }   
        else{
            res = max(max(l,r)+1,res);
        }
        if(parent==NULL) return max(l,r)+1;
        else{
            int d = parent->val - root->val;
            if(d==1||d==-1){
                int dl = root->left?(root->val-root->left->val):0;
                int dr = root->right?(root->val-root->right->val):0;
                int ans = 0;
                if(d==dl) ans = max(ans,l);
                if(d==dr) ans = max(ans,r);
                return ans + 1;
            }
            else return 0;
        }
    }
};
