class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res = "";
        for(auto substr:d){
            if(substr.size()>res.size()||(substr.size()==res.size()&&substr.compare(res)<0)){
                if(match(s,substr)) res = substr;
            }
        }
        return res;
    }
private:
    bool match(string a, string b){
        if(b.size()>a.size()) return false;
        int i,j;
        for(i=0,j=0;j<b.size()&&i<a.size();i++){
            if(a[i]==b[j]) j++;
        }
        return j==b.size();
    }    
};
