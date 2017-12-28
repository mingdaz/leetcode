class Solution {
public:
    int integerReplacement(int n) {
        //vector<int> temp(n+1,0);   空间复杂度高
        //if(n==1) return 0;
        //for(int i=2;i<=n;i++){
         //   if(i%2==0)
         //       temp[i]=temp[i/2]+1;
         //   else
         //       temp[i]=min(temp[(i-1)/2],temp[(i+1)/2])+2;
        //}
       // return temp[n];
        if(n==1) return 0;
        if(n%2==0) return 1+integerReplacement(n/2);
        long long t=n;
        if(n%2==1) return 2+min(integerReplacement((t+1)/2),integerReplacement((t-1)/2));
    }
};
