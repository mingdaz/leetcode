class Sulution{    
public:
	TreeNode* upsideDownBinaryTree(TreeNode* root){
		if(!root||!root->left) return root;
		TreeNode *left,*right,*tl,*tr,*tmp;
		left = root->left;
		right = root->right;
		root->left = NULL;
		root->right = NULL;
		while(left){
			tl = left->left;
			tr = left->right;
			tmp = left;
			left = right;
			right = root;
			root = tmp;
			root->left = left;
			root->right = right;
			left = tl;
			right = tr;
		}
		return root;
	}
};
