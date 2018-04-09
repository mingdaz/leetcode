class Solution {
public:
    double myPow(double x, long n) {
        if(n==0) return 1.0;
        if(n<0) return 1.0/myPow(x,-n);
        vector<double> ret(32,1.0);
        long pow = 1;
        int i;
        double tmp = x;
        for(i=1;i<32&&pow<=n/2;i++){
            ret[i] = tmp;
            tmp = tmp*tmp;
            pow = pow*2;
        }
        n -= pow;
        while(n>0){
            while(pow >n){
                pow/=2;
                i--;
            }
            tmp *= ret[i];
            n -= pow;
        }
        return tmp;
    }
};