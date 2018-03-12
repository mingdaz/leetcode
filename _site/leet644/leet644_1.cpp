class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> preS(n, 0);
        preS[0] = nums[0];
        for (int i = 1; i < n; ++i)
        {
            preS[i] = preS[i-1] + nums[i];
        }
        
        deque<int> q;
        double ret = preS[n-1] / n;
        for (int j = k-1; j < n; ++j)
        {
            while(q.size() >= 2 && density(preS, q[q.size()-2], q.back()-1) >= density(preS, q.back(), j-k))
            {
                q.pop_back();
            }
            q.push_back(j-k+1);
            while(q.size() >= 2 && density(preS, q[0], j) <= density(preS, q[1], j))
            {
                q.pop_front();
            }
            ret = max(ret, density(preS, q.front(), j));
        }
        return ret;
    }
private:
    double density(vector<double>& preS, int l, int r)
    {
        if (l == 0)
        {
            return preS[r] / (r + 1);
        }else
        {
            return (preS[r] - preS[l-1]) / (r - l + 1);
        } 
    }
};