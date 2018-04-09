class Solution {
    vector<vector<int>> dp, nexts, parents;
    void calc_next(const string &pattern, int start_pos)
    {
        nexts[start_pos][start_pos] = start_pos - 1;
        for(int i = start_pos, j = start_pos - 1; i < (int)pattern.size() && j < (int)pattern.size();)
            if (j == start_pos - 1 || pattern[i] == pattern[j])
                nexts[start_pos][++ i] = ++ j;
            else
                j = nexts[start_pos][j];
    }
    void calc_rep(const string &str, int start, int end)//end 1-past the end pointer
    {
        int k = nexts[start][end] - start;
        int len = end - start, rep = len / (len - k) ;
        if (len % (len - k) == 0 && rep > 1)
        {
            dp[end - start][start] = to_string(rep).size() + dp[len - k][start] + 2;
            parents[end - start][start] = len - k + str.size();//+ str.size() to indicate this has only 1 parent;
            return;
        }
        parents[end - start][start] = 0;
        dp[end - start][start] = len;
    }
    string build_str(const string &str, int k, int i)
    {
        int j = parents[k][i];
        if (j == 0)
            return str.substr(i, k);
        if (j <= str.size())
            return build_str(str, j, i) + build_str(str, k - j, i + j);
        j -=  str.size(); //j > str.size() means it has only 1 parent instead of 2;
        return to_string(k / j) + "[" + build_str(str, j, i) + "]";
    }
public:
    string encode(const string &str) {
        nexts.resize(str.size(), vector<int> (str.size() + 1));
        dp.resize (str.size() + 1, vector<int>(str.size()));
        parents.resize(str.size() + 1, vector<int>(str.size()));
        for (int i = 0; i < str.size(); ++i)
            calc_next(str, i);
        for (int k = 1; k <= str.size(); ++k)
            for (int i = 0; i <= str.size() - k; ++ i)
                for (int j = 0; j < k; ++ j)
                    if (j == 0)
                        calc_rep(str, i, i + k);
                    else if (dp[k][i] >  dp[j][i] + dp[k - j][i + j])
                    {
                        dp[k][i] = dp[j][i] + dp[k - j][i + j];
                        parents[k][i] = j;
                    }
        return build_str(str, str.size(), 0);
    }
};