class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int> bucket(citations.size(),0);
        int cnt = 0;
        for(int c:citations){
            if(c<citations.size()){
                cnt++;
                bucket[c]++;
            }
        }
        if(cnt==0) return citations.size();
        cnt = citations.size() - cnt;
        for(int i = citations.size()-1;i>=0;i--){
            cnt += bucket[i];
            if(cnt>=i) return i;
        }
        return 0;
    }
};
