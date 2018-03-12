class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n<1)
            return 0;
        vector<int> f(n);
        vector<int> inx(primes.size(), 0);
        f[0] = 1;
        
        int target;
        for (int i=1; i<n; ++i)
        {
            target = INT_MAX;
            for (int j=0; j<primes.size(); ++j)
                target = min(target, f[inx[j]]*primes[j]);
            f[i] = target;
            
            for (int j=0; j<primes.size(); ++j){
                if (target == f[inx[j]]*primes[j])
                    inx[j]++;
            }            
        }
        return f[n-1];
        
    }
};
