/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * 	   int val;
 *     TreeNode *left;
 *	   TreeNode *right;
 *	   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode* upsideDownBinaryTree(TreeNode* root) {
		if(root==NULL) return NULL;
		TreeNode* l = root->left;
		TreeNode* r = root->right;
		TreeNode* temp;
		if(l){
			temp = upsideDownBinaryTree(l);
	        l->left = r;
	        l->right = root;
	        root->left = NULL;
	        root->right = NULL;
	    }
	   	else temp = root;
	    return temp;
	}
};
