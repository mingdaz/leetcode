class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i=0;
        int j=0;
        int m = word.length();
        int n = abbr.length();
        while(i<n){
            if(abbr[i]=='0' ) return false;
            if(isdigit(abbr[i])){
                int temp = 0;
                while(i<n&&isdigit(abbr[i])){
                    temp = temp*10 + abbr[i] - 48;
                    i++;
                }
                j = j+temp;
            }
            else{
                if(i<n&&j>=m) return false;
                if(i<n&&j<m&&word[j]!=abbr[i]) return false;
                i++,j++;
            }
        }
        return j==m;
    }
};
