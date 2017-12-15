class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int total = 0;
        for (auto c : S)
        {
            if (c != '-')
                total ++;
        }
        
        if (total == 0)
            return "";
        int group = ceil(double(total) / K);
        int firstGroup = total - (group - 1) * K;
        string ans(group - 1 + total, ' ');
        int i = 0;
        int j = 0;
        int g = group;
        while (g --)
        {
            int num = (g == group - 1) ? firstGroup : K;
            while (num --)
            {
                while (S[j] == '-')
                {
                    j ++;
                }
                ans[i ++] = toupper(S[j ++]);                
            }
            if (g != 0) ans[i ++] = '-';
        }
        
        return ans;
    }
};
