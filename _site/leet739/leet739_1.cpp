class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n,0);
        vector<int> temp(101,0);
        for(int i=n-1;i>=0;i--){
            int idx = n;
            for(int t=temperatures[i]+1;t<101;t++){
                if(temp[t]>0&&temp[t]<idx) idx = temp[t];
            }
            temp[temperatures[i]] = i;
            if(idx<n) res[i] = idx - i;
        }
        return res;
    }
};
