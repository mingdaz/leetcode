
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
    string serialize(TreeNode* root, unordered_map<string, vector<TreeNode*>>& map){
        if (root == NULL) return "";
        string left = serialize(root->left, map);
        string right = serialize(root->right, map);
        string s = "(" + left + to_string(root->val) + right + ")";
        map[s].push_back(root);
        return s;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // key is serialized tree nodes, value is all the roots with the same string key
        unordered_map<string, vector<TreeNode*>> map;
        serialize(root, map);
        vector<TreeNode*> res;
        // if more than 1 nodes have same string, which means there are at least 2 same subtrees
        for (auto e : map){
            if ((e.second).size() > 1) {
                res.push_back(e.second[0]);
            }
        }
        return res;
    }
};