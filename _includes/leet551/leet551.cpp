class Solution {
public:
    bool checkRecord(string s) {
        int A_cnt = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='A') {
                A_cnt++;
                if(A_cnt>1) return false;
            }
            else if(s[i]=='L'){
                int L_cnt = 0;
                while(i<s.length()&&L_cnt<3&&s[i]=='L'){
                    i++;
                    L_cnt++;
                }
                if(L_cnt>2) return false;
                else i--;
            }
        }
        return true;
    }
};
