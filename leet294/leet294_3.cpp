class Solution {
public:
    bool canWin(string s) {
        int n = s.size();
        if (n == 0) return false;        
        vector<int> f(n+1);
        f[1] = 0;
        f[2] = 1;        
        for (int i = 3; i <= n; ++i) {
            set<int> s;
            s.insert(f[i-2]);
            for (int j = 1; j <= i-3; ++j) {
                int v = f[j] ^ f[i-j-2];
                s.insert(v);
            };
            int j = 0;
            while (s.count(j)) ++j;
            f[i] = j;            
        };
        
        int ans = 0;
        int i = 0;
        while (i < n) {
            int count = 0;
            while (i < n && s[i] == '-') ++i;
            while (i < n && s[i] == '+') {
                ++count;
                ++i;
            };
            if (count > 0)
                ans = ans ^ f[count];
        };
        return (ans != 0);
        
    }
};
