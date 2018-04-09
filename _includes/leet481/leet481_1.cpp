class Solution {
public:
    int magicalString(int n) {
        if(n==0) return 0;
        queue<int> Q;
        Q.push(2);
        int i = 3;
        int cnt = 1;
        while(i<n){
            int tmp = Q.front();
            int c = Q.back()==1?2:1;
            if(tmp==1){
                Q.push(c);
                i++;
                if(c==1) cnt++;
            } 
            else {
                Q.push(c);
                i++;
                if(c==1) cnt++;
                if(i==n) break;
                Q.push(c);
                i++;
                if(c==1) cnt++;
            }
            Q.pop();
        }
        return cnt;
    }
};
