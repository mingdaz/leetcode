class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        res.push_back(word);
        for(int i=1;i<=word.size();i++){
            for(int j=0;j<=word.size()-i;j++){
                string pre = word.substr(0,j) + to_string(i);
                // res.push_back(pre + word.substr(j+i));
                if(j+i+1<word.size()){
                    pre = pre + word.substr(j+i,1);
                    vector<string> temp = generateAbbreviations(word.substr(j+i+1));
                    for(auto str:temp){
                        res.push_back(pre+str);
                    }    
                }
                else{
                    res.push_back(pre + word.substr(j+i));
                }
            }
        }
        return res;
    }
};
