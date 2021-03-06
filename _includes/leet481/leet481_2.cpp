class Solution {
public:
    int magicalString(int n) {
        vector<char> s(n, 0);
        int i=0;    //index of next entry
        int j=0;
        // i - the beginning of the next entry to fill
        // j - the entry reprents the # of occurrence aka. the group string
        char c = 1;
        char groupCh = 1;        // current char of the group
        int numc=0;         //number of chars so far, calculated based on 'j' string
        int ans=0;
        while(numc < n) {
            s[i++] = c;
            ans = ans + (2 - groupCh) * c; 
            groupCh = 3 - groupCh;
            numc += c;
            if(numc >= n) break;
            if(s[j++] == 2)  {
                s[i] = c;
                ans = ans + (2 - groupCh) * c;
                groupCh = 3 - groupCh;
                numc += c;
                ++i;
            }
            c = 3 - c;
        }
        if(numc > n && groupCh == 2) {
            ans -= (numc - n);
        }
        return ans;
    }

};
