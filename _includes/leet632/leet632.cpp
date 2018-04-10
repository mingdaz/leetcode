class Solution {
public:
    typedef vector<int>::iterator vi;

    vector<int> smallestRange(vector<vector<int>> &nums) {
        auto cmp = [](pair<vi, vi> &a, pair<vi, vi> &b) {
            return *a.first > *b.first;
        };
        // Min heap
        priority_queue<pair<vi, vi>, vector<pair<vi, vi>>, decltype(cmp)> pq(cmp);
        int lo = INT32_MAX, hi = INT32_MIN;
        for (auto &vr:nums) {
            lo = std::min(lo, vr[0]);
            hi = std::max(hi, vr[0]);
            pq.push({vr.begin(), vr.end()});
        }
        // Here we have one valid range
        vector<int> res{lo, hi};
        int len = hi - lo;
        while (true) {
            pair<vi, vi> t = pq.top();
            ++t.first;
            pq.pop();
            pq.push(t);

            if (t.first == t.second)
                break;
            lo = *pq.top().first;
            hi = std::max(hi, *t.first);
            if (hi - lo < len) {
                res[0] = lo;
                res[1] = hi;
                len = hi - lo;
            }
        }
        return res;
    }


};