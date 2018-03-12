class Solution {
public:
    bool isMatch(string s, string p) {
        int inds = 0,indp = 0,indx=-1;
        int ls = s.length(),lp = p.length();
        while(inds<ls){
            if(indp==lp){
                if(indx<0) return false;
                else inds -= (indp-indx-2), indp = indx+1;
            }
            else if(p[indp]=='*') indx = indp,indp++;
            else if(s[inds]==p[indp]||p[indp]=='?') indp++,inds++;
            else{
                if(indx<0) return false;
                else inds -= (indp-indx-2), indp = indx+1;
            }
        }
        while(indp<lp&&p[indp]=='*') indp++;
        return indp==lp;
    }
};
