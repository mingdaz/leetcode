/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream oss;
        visitSer(root, oss);
        return oss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss;
        iss.str(data);
        return visitDes(iss);
    }
    
private:
    void visitSer(TreeNode* node, ostringstream& oss) {
        if(node == NULL) {
            oss << " " << "N";
            return;            
        }
        oss << " " << node->val;
        visitSer(node->left, oss);
        visitSer(node->right, oss);
    }
    TreeNode* visitDes(istringstream& iss) {
        string val;
        iss >> val;
        if(val == "N")
            return NULL;
        TreeNode* res = new TreeNode(stoi(val));
        res->left = visitDes(iss);
        res->right = visitDes(iss);
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));