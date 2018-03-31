class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        dfs(root, res);
        return res;
    }
    
private:
    int dfs(TreeNode* root, int &res) {
        if (root == NULL) {
            return 0;
        }
        
        int l = dfs(root->left, res);
        int r = dfs(root->right, res);
        
        if (l + r + root->val > res) {
            res = l + r + root->val;
        }
        
        int ans = max(0, max(l, r)) + root->val;
        if (ans > res) {
            res = ans;
        }
        
        return ans;
    }
};