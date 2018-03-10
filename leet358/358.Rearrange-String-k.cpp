class Solution {
    bool static cmp (const pair<int,int> &a, const pair<int,int> &b){
        return a.first == b.first ?  a.second < b.second : a.first > b.first;
    }
public:
    string rearrangeString(string s, int k) {
        if(!k)
            return s;
        string res;
        vector<pair<int,int>> dict(26);
        for(char c : s) {
            ++dict[c - 'a'].first;
            dict[c - 'a'].second = c - 'a';
        }
        
        sort(dict.begin(), dict.end(), cmp);
        int i = 1, j = 0;
        
        while(dict[i].first == dict[0].first) i++;
        int len = (dict[0].first - 1) * k + i;
        if(len > s.size())
            return "";
        
        for(int j = 0; j < i; j++)
            res += dict[j].second + 'a';
        
        vector<string> block(dict[0].first, res);
        
        while( i < dict.size()) {
            while(dict[i].first--) {
                block[j++] += dict[i].second + 'a';
                j %= block.size() - 1;
            }
            i++;
        }
        
        res = "";
        for(string &s : block) {
            res += s;
        }
        return res;
    }
};