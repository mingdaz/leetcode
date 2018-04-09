class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int sLen = s.size(),wordL,wSize,i,j,start,count;
        vector<int> res;
        if(!(wSize=words.size())||!(wordL=words[0].size())||(sLen<wSize*wordL)) return res;
        
        unordered_map<string,int> dict;
        for(i=0;i<wSize;i++){
            ++dict[words[i]];
        }
        
        for(j=0;j<wordL;j++){
            for(i=j,start=j,count=0;i<=sLen-wordL;i+=wordL){
                if(dict.count(s.substr(i,wordL))==0){
                    while(start<i){
                        ++dict[s.substr(start,wordL)];
                        start += wordL;
                    }
                    start = i+wordL;
                    count = 0;
                    continue;
                }
                if(--dict[s.substr(i,wordL)]<0){
                    while(dict[s.substr(i,wordL)]<0){
                        ++dict[s.substr(start,wordL)];
                        start += wordL;
                        count--;
                    }
                }
                if(++count==wSize){
                    res.push_back(start);
                    ++dict[s.substr(start,wordL)];
                    count--;
                    start += wordL;
                }    
            }
            while(start<i){
                ++dict[s.substr(start,wordL)];
                start += wordL;
            }
            
        }
        return res;
    }
};
