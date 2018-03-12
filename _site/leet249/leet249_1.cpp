class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        int cnt = 0;
        unordered_map<string,int> dict;
        for(auto str:strings){
            int idx;
            string key = str;   
            if(str[0]!='a'){
                int shift = str[0] - 'a';
                for(int i=0;i<key.size();i++){
                    key[i] = str[i] - shift;
                    if(key[i]<'a')key[i] = key[i] + 26;
                }
            }
            // std::cout<<key<<","<<str<<std::endl;
            if(dict.find(key)==dict.end()){
                dict[key] = cnt++;
                res.push_back(vector<string>(0));
            }
            idx = dict[key];
            res[idx].push_back(str);
        }
        return res;
    }
};
