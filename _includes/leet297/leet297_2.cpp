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
        string res;
        _serialize(root,res);  
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx = 0;
        return _deserialize(data,idx);
    }
    
private:
    void _serialize(TreeNode* node, string& res){
        if(node==NULL){
            res.append(" N");
            return;
        }
        res.push_back(' ');
        res.append(to_string(node->val));
        _serialize(node->left, res);
        _serialize(node->right, res);
    }
    TreeNode* _deserialize(string& data,int& idx){
        idx++;
        if(data[idx]=='N'){
            idx++;
            return NULL;
        }
        int begin = idx;
        while(data[idx]!=' '&&idx<data.size()) 
            idx++;
        int val = stoi(data.substr(begin,idx - begin));
        TreeNode* node = new TreeNode(val);
        node->left = _deserialize(data,idx);
        node->right = _deserialize(data,idx);
        return node;
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));