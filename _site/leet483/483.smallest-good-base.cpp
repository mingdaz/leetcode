class Solution {
public:
    using ull = unsigned long long;
    string smallestGoodBase(string n) {
        ull un = stoll(n);
        // 1. loop from length 64 - 2
        for(int i=62;i>=2;i--){
            // 2. do binary search to get base
            ull cur = getBase(un, i);
            // 3. output if base valid
            if(cur) return to_string(cur);
        }
        return to_string(un-1);
    }
    ull getBase(ull n, int l){
        double dn = n;
        ull p = 2, q = pow(dn, 1.0/(l-1))+1;
        while(p<=q){
            ull mid = p + (q-p)/2, cand = 1, cur = 1;
            for(int i=2;i<=l;i++){
                cur *= mid;
                cand += cur;
            }
            if(n==cand) return mid;
            else if(cand > n) q = mid-1;
            else p = mid + 1;
        }
        return 0;
    }
};