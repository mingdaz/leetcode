class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<int> res(word2.size(), 0);
        int maxLength = 0;
        for (char w : word1) {
            int pre = 0;
            for (int j = 0; j < word2.size(); j++) {
                int tmp = res[j];
                if (w != word2[j]) res[j] = max(j > 0 ? res[j - 1] : 0, res[j]);
                else {
                    res[j] = max(1 + pre, res[j]);                
                }
                 maxLength = max(res[j], maxLength);
                pre = tmp;
            }
        }
        return word1.size()  + word2.size() - 2 * maxLength;
    }
};
