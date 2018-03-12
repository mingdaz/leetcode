class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        int cnt = 0;
        int prev = INT_MIN;
        vector<int> ret;
        helper(root,ret,cnt,prev);
        if(cnt > freq){
            freq = cnt;
            ret.clear();
        }
        if(cnt==freq)
            ret.push_back(prev);
        return ret;

    }
private:
    int freq = 1;

    void helper(TreeNode* root, vector<int>& ret, int& cnt, int &prev){
        if(root){
            helper(root->left,ret,cnt,prev);
            if(root->val==prev) cnt++;
            else{
                if(cnt > freq){
                    freq = cnt;
                    ret.clear();
                }
                if(cnt==freq)
                    ret.push_back(prev);
                cnt = 1;
                prev = root->val;  
            } 
            helper(root->right,ret,cnt,prev);
        }
    }
};
