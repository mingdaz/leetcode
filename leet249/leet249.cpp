class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> dict;
        for(int i=0;i<strings.size();i++){
            int d = strings[i][0] -'a';
            string key = strings[i];
            key[0] = 'a';
            for(int j=1;j<strings[i].length();j++){
                key[j] = (key[j]-'a'+26-d)%26+'a';
            }
            dict[key].push_back(strings[i]);
        }
        for(auto it = dict.begin();it!=dict.end();++it){
            vector<string> ans = it->second;
            sort(ans.begin(),ans.end());
            res.push_back(ans);
        }
        return res;
    }
    
};
