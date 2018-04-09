class Solution {
public:
    string findContestMatch(int n) {
        vector<string> p(n,"");
        for(int i=1;i<=n;i++){
            p[i-1] = to_string(i);
        }
        while(p.size()>1){
            for(int i=0,j=p.size()-1;i<j;i++,j--){
                p[i] = "(" + p[i] + "," + p[j] + ")";
            }
            int n = p.size()/2; 
            p.resize(n);            
        }
        return p[0];
    }
};
