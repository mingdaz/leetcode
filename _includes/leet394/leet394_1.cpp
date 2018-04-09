class Solution {
public:
    string decodeString(string s) {
        int st = 0;
        return decode(s,st,1);
    }
private:
    string decode(string& s, int& st, int rep){
        string tmp = "";
        while(st<s.size()&&s[st]!=']'){
            while(st<s.size()&&!isdigit(s[st])&&s[st]!=']'){
                tmp.push_back(s[st]);
                st++;
            }
            if(st<s.size()&&s[st]!=']'){
                int sub_rep = 0;
                while(st<s.size()&&isdigit(s[st])){
                    sub_rep = sub_rep*10 + s[st] - '0';
                    st++;
                }
                st++;
                tmp += decode(s,st,sub_rep);
            }
        }
        if(st<s.size()&&s[st]==']') st++;
        string ans = "";
        if(rep==0||tmp.size()==0) return ans;
        while(rep) {
            ans += tmp;
            rep--;
        }
        return ans;
    }
};
