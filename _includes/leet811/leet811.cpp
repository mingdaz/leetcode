class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int> dict;
        for(auto str:cpdomains){
            int idx = str.find(' ');
            int cnt = atoi(str.substr(0,idx).c_str());;
            
            string key = str.substr(idx);
            while(idx!=string::npos){
                key = str.substr(idx+1);             
                dict[key] += cnt;
                idx = str.find('.',idx+1);
            }
        }
        vector<string> res;
        for(auto it = dict.begin();it!=dict.end();++it){
            res.push_back(to_string(it->second)+" "+it->first);
        }
        return res;
    }
};