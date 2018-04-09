class Solution {
public:
    double soupServings(int N) {
        int n = N/25 + (N%25!=0);
        if(N>5000) return 1;
        vector<vector<double>> s(n+1,vector<double>(n+1,-1));
        return helper(n,n,s);
    }
    double helper(int A,int B,vector<vector<double>>& s){
        if(A<=0||B<=0){
            if (A<=0 && B<=0) 
                return 0.5;
            else if( A<=0) 
                return 1;
            else if( B<=0) 
                return 0;
        }
        if(s[A][B]<0)  
            if (A<=0 && B<=0) 
                s[A][B] = 0.5;
            else if( A<=0) 
                s[A][B] = 1;
            else if( B<=0) 
                s[A][B] = 0;
            else 
                s[A][B] = 0.25*(helper(A-4,B,s)+helper(A-3,B-1,s)+helper(A-2,B-2,s)+helper(A-1,B-3,s));
        return s[A][B];

    }
};