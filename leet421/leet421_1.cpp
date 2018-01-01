// sample 39 ms submission
class Solution {
    struct T
    {
        T() 
        {
            s[0] = s[1] = 0;
        }
        int s[2];        
    };
    
public:
    int findMaximumXOR(vector<int>& nums) {
        vector<T> trie(2 * 32 * nums.size() + 1);
        int cnt = 1, cur;
        for(int & x : nums)
        {
            cur = 0;
            for(int i = 31; i >= 0; --i)
            {
                int y = (x >> i) & 1;
                if (!trie[cur].s[y])
                {
                    trie[cur].s[y] = cnt++;                    
                }
                cur = trie[cur].s[y];                
            }
        }
        
        int ans = 0;
        for(int & x : nums)
        {
            int tmp = 0;
            cur = 0;
            for(int i = 31; i >= 0; --i)
            {
                int y = (x >> i) & 1;
                if (trie[cur].s[y^1])
                {
                    tmp |= (1 << i);
                    cur = trie[cur].s[y ^ 1];
                }
                else
                {
                    cur = trie[cur].s[y];
                }
            }
            
            if (tmp > ans)
                ans = tmp;
        }
        
        return ans;
    }
};
