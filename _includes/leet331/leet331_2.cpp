class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<int> q;
        if (preorder.empty() || preorder == "#") return true;
        if (preorder[0] != '#') q.push_back(2);
        for (size_t i=preorder.find(',', 0); i != string::npos; i = preorder.find(',', i+1)) {
            if (q.empty()) return false;
            if (--q.back() == 0) q.pop_back();
            if (preorder[i+1] != '#') {
                q.push_back(2);
            }
        }
        return q.empty();
        
    }
};
