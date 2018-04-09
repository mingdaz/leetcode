class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> res(s.length()+1);
        int i,p,q;
        for(i=0;i<res.size();i++){
            res[i] = i+1;
        }
        i = 0;
        while(i<s.length()){
            if(s[i]=='D'){
                p = i;
                while(i<s.length()&&s[i]=='D'){
                    i++;
                }
                q = i;
                while(p<q) swap(res[p++],res[q--]);
            }
            i++; 
        }
        return res;
    }
};
