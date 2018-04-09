class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        while(--n){
            string tmp;
            int count = 1;
            char c = s[0];
            for(int i=1;i<s.length();i++){
                if(s[i]==c)count++;
                else{
                    tmp.push_back(count+'0');
                    tmp.push_back(c);
                    count = 1;
                    c = s[i];
                }
            }
            tmp.push_back(count+'0');
            tmp.push_back(c);
            s = tmp;
        }
        return s;
    }
};
