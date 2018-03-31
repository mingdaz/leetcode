class Solution {
public:
    int rotatedDigits(int N) {
        int cnt = 0;
        for(int i=1;i<=N;i++){
            if(helper(i)) cnt++;
        }
        return cnt;
    }
    
    bool helper(int i){
        int j = 0;
        int k = i;
        int weight = 1;
        while(i>0){
            int d = i%10;
            if(d==3||d==7||d==4) return false;
            i = i/10;
            if(d==2) d=5;
            else if(d==5) d=2;
            else if(d==6) d=9;
            else if(d==9) d=6;
            j += d*weight;
            weight *= 10;
        }
        return j!=k;
    }
};