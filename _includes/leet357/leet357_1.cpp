class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int res = 1;
        for(int i=1;i<=min(9,n);i++)
            res += helper(i);
        return res;
    }
    int helper(int n){
        if(n>10) return 0;
        int res = 9;
        int pos = 9;
        n--;
        while(n>0){
            res*=pos;
            pos--;
            n--;
        }
        return res;
    }
};
