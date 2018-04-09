class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int n = flowers.size();
        if (n == 0 || k >= n) return -1;
        ++k;
        int bs = (k + n - 1) / k;
        vector<int> low(bs, INT_MAX), high(bs, INT_MIN);
        for (int i = 0; i < n; i++) {
            int x = flowers[i];
            int p = x / k;
            if (x < low[p]) {
                low[p] = x;
                if (p > 0 && high[p - 1] == x - k) return i + 1;
            }
            if (x > high[p]) {
                high[p] = x;
                if (p < bs - 1 && low[p + 1] == x + k) return i + 1;
            }
        }
        return -1;
    }
};

// bucket.