class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int idx = 0;
        int len = primes.size();
        vector<int> base(len, 1);
        vector<int> out;
        vector<int> min_j(len, 0);
        int min = -1;
        while (idx++ < n) {
            min = -1;
            int min_i = 0;
            for (int i = 0; i < len; ++i) {
                if (-1 == min || base[i] < min) {
                    min = base[i];
                    min_i = i;
                }
            }
            
            out.push_back(min);
            
            for (int i = 0; i < len; ++i) {
                if (base[i] == min) {
                    int ol = out.size();
                    for (int j = min_j[i]; j < ol; ++j) {
                        if (out[j] * primes[i] > min) {
                            base[i] = out[j] * primes[i];
                            min_j[i] = j;
                            break;
                        }
                    }
                }
            }
        }
        
        return min;
    }
};
