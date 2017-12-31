class Solution {
public:
    int maxProduct(vector<string>& words) {
        int len = 0;
        for(int i=0;i<words.size();i++){
            for(int j=i;j<words.size();j++){
                if(i==j) continue;
                if(share(i,j,words)) continue;
                else{
                    int newl = words[i].size()*words[j].size();
                    if(newl>len) len = newl;
                } 
            }
        }
        return len;
    }
private:
    bool share(int i, int j, vector<string>& words){
        bool dict[128] = {};
        for(char c:words[i]){
            dict[c] = true;
        }
        for(char c:words[j]){
            if(dict[c]) return true;
        }
        return false;
    }
};
