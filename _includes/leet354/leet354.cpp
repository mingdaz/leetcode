class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
            if (p1.first == p2.first) {
                return p1.second > p2.second;
            } 
            return p1.first < p2.first;
        });
        int n = envelopes.size();
        vector<int> ends;
        for (auto& envelope : envelopes) {
            auto it = lower_bound(ends.begin(), ends.end(), envelope.second);
            if (it == ends.end()) {
                ends.push_back(envelope.second);
            } else {
                *it = envelope.second;
            }
        }
        return ends.size();
    }
};
