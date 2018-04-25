class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int idx = 0;
        int length = 0;
        string tmp = "";
        for(int i=0;i<words.size();i++){
            if(length+words[i].size()+ i-idx>maxWidth){
                int tot_space = maxWidth - length;
                int cnt = i - idx-1;
                if(cnt==0){
                    tmp = words[idx] + string(tot_space,' ');
                }
                else{
                    int base = tot_space/cnt;
                    int offset = idx + tot_space%cnt;
                    for(;idx<i;idx++){
                        tmp.append(words[idx]);
                        if(idx<i-1)
                            tmp.append(base+(idx<offset),' ');
                    }   
                }
                res.push_back(tmp);
                length = words[i].size();
                tmp.clear();
                idx = i;
            }
            else{
                length += words[i].size();
            }
        }
        if(idx<words.size()){
        tmp.clear();
        for(;idx<words.size();idx++){
            tmp.append(words[idx]);
            if(idx+1<words.size())
                tmp.push_back(' ');
        }
        tmp.append(maxWidth-tmp.size(),' ');
        res.push_back(tmp);            
        }
        return res;
    }
};