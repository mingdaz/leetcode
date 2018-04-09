class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res(n,1);
        if(n==k) return res;
        int l = 1;
        int r = n;
        int idx = 0;
        while(n-1>k){
            res[idx++] = l++;
            k++;
        }
        while(idx<n){
            res[idx++] = l++;
            if(idx<n)
                res[idx++] = r--;
        }
        return res;
    }
};
