class Solution {
public:
  int findKthNumber(int m, int n, int k) {
    int lo = 1, hi = m * n;
    while(lo < hi) {
        int mid = lo + (hi - lo) / 2;
        int count = 0;
        int j = n;
        for(int i = 0; i < m; i++) {
            while(j >= 0 && (i+1)*j > mid) j--;
            count += j;
        }
        if(count < k) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}
};