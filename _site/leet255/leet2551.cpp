class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if(preorder.size() < 1) {
            return true;
        }
        stack<int> s;
        int bound = INT_MIN;
        for(auto num : preorder) {
            if(num < bound) {
                return false;
            }
            while(!s.empty() && num > s.top()) {
                bound = s.top();
                s.pop();
            }
            s.push(num);
        }
        return true;
    }
};
