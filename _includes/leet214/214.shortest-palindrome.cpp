class Solution {
public:
    //based on KMP
    int* calnext(string s){
        int *n=new int[s.size()];
        int j=0,i=1;
        n[0]=0;
        while(i<s.size()){
            if(s[i]==s[j]){
                n[i]=j+1;
                i++;
                j++;
            }
            else{
                if(j>0)
                    j=n[j-1];
                else
                    n[i++]=0;
            }
        }
        return n;
    }
    
    string shortestPalindrome(string s) {
        int L=s.length();
        string s1=s;
        reverse(s1.begin(),s1.end());
        string s2=s+'/'+s1;
        int *n=calnext(s2);
        return s1.substr(0,s.size()-n[s2.size()-1])+s;
    }
};