class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int currContOnes = 0;
        int prevContOnes = -1; // set to -1 to handle the case when the vectors starts with 1
        for (int num : nums) {
            if (num == 1) {
                ++currContOnes;
            }
            else {
                if (currContOnes == 0) {
                    prevContOnes = 0; // the two continuous 1's are apart by more than one 0's
                }
                else {
                    prevContOnes = currContOnes;
                    currContOnes = 0;
                }
            }
            res = max(res, currContOnes + prevContOnes + 1);
        }
        return res;
    }
};
