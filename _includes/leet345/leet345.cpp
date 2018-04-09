class Solution {
public:
    string reverseVowels(string s) {
        int i,j;
        for(i=0,j=s.length();i<j;i++,j--){
            while(i<j&&helper(s[i]))i++;
            while(i<j&&helper(s[j]))j--;
            swap(s[i],s[j]);
        }
        return s;
    }
private:
    bool helper(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'
          ||c=='A'||c=='E'||c=='I'||c=='O'||c=='U') return false;
        return true;
    }
};
