class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> bits(n,0);
        for(int i=0;i<n;i++){
            for(char c:words[i]){
                bits[i] |= (1<<(c-'a'));
            }
            // std::cout<<bits[i]<<std::endl;
        }
        int res = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((bits[i]&bits[j])!=0) continue;
                int newl = words[i].size()*words[j].size();
                if(newl > res) res = newl;
            }
        }
        return res;
    }
};
