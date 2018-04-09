class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        vector<pair<char,int>> myset;
        int i,j;
        for(i=0;i<S.size();i++){
            for(j=i+1;S[i]==S[j]&&j<S.size();j++){
                ;
            }
            myset.push_back(pair<char,int>(S[i],j-i));
            i = j-1;
        }
        int cnt = 0;
        for(auto word:words){
            if(helper(word,myset)){
                cnt++;
            }
        }
        return cnt;
    }
    
    bool helper(string& S, vector<pair<char,int>>& myset){
        int i,j,idx = 0;
        for(i=0;i<S.size();i++,idx++){
            for(j=i+1;S[i]==S[j]&&j<S.size();j++){
                ;
            }
            // myset.push_back(pair<char,int>(S[i],j-i));
            if(myset[idx].first!=S[i]) return false;
            if(myset[idx].second<j-i) return false;
            if(myset[idx].second==2&&2>j-i) return false;
            i = j-1;
        }
        return idx==myset.size();
    }
};