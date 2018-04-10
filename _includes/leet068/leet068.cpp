class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        int length = 0;
        int idx = 0;
        for(int i=0;i<words.size();i++){
            if(length + words[i].size() + i - idx > maxWidth){
                int tot_sp = maxWidth - length;
                int cnt = i - idx; //nubmer of word
                if(cnt==1){
                    string tmp = words[idx];
                    tmp.append(tot_sp,' ');
                    ret.push_back(tmp);
                }
                else {
                    int sp = tot_sp / (cnt-1);
                    int ex_sp = tot_sp % (cnt-1);
                    int j;
                    string tmp = "";
                    for(j=idx;j<idx+ex_sp;j++){
                        tmp.append(words[j]);
                        tmp.append(sp+1,' ');
                    }
                    for(j=idx+ex_sp;j<i-1;j++){
                        tmp.append(words[j]);
                        tmp.append(sp,' ');
                    }
                    tmp.append(words[i-1]);
                    ret.push_back(tmp);
                }
                length = words[i].size();
                idx = i;
            }
            else{
                length += words[i].size();
            }
        }
                
        int cnt = words.size() - idx; //nubmer of word
        string tmp = "";
        for(int i=idx;i<words.size()-1;i++){
            tmp.append(words[i]);
            tmp.append(1,' ');
        }
        tmp.append(words[words.size()-1]);
        // std::cout<<maxWidth - tmp.size()<<std::endl;
        tmp.append(maxWidth - tmp.size(),' ');
        // std::cout<<"["<<tmp<<"]"<<endl;
        ret.push_back(tmp);
        return ret;
    }

};