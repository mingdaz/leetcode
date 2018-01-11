class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>> m(128);
        for(int i=0;i<128;i++){
            m[i].second=i;
        }
        for(auto c:s){
            m[c].first++;
        }
        string res;
        sort(m.rbegin(),m.rend());
        for(auto p:m){
            if(p.first>0)
                res.append(p.first,p.second);
        }

        return res;
    }
};
