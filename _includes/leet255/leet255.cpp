class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if (preorder.empty()) return true;
        int lowerBound = INT_MIN;
        int stackTopPosition = 0;
        for (int pos = 1; pos < preorder.size(); ++pos) {
            if (preorder[pos] < lowerBound) return false;
            while (stackTopPosition >= 0 && preorder[pos] > preorder[stackTopPosition]) {
                lowerBound = preorder[stackTopPosition--];  // Update 
            }
            preorder[++stackTopPosition] = preorder[pos];  // Push to stack
        }
        return true;
    }
};

// in place 

