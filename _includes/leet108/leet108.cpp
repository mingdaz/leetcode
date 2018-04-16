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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
    TreeNode* helper(vector<int>& nums, int l, int r){
        if(l>r) return NULL;
        int mid = l + (r - l)/2;
        TreeNode* ret = new TreeNode(nums[mid]);
        ret->left = helper(nums,l,mid-1);
        ret->right = helper(nums,mid+1,r);
        return ret;
    }
};