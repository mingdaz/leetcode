class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        if(len<2)return 0;
        if(len==2)return max(0,prices[1]-prices[0]);
        len--;
        vector<int> profit(len,0);
        vector<int> assitpf(len,0);
        for(int i=0;i<len;i++)
            profit[i]=prices[i+1]-prices[i];
        int maxp=0,prev2max=0;
        for(int i=0;i<len;i++){
            if(i>=3)
                prev2max=max(prev2max,assitpf[i-3]);
            if(i==0){
                assitpf[i]=max(profit[i],0);
                maxp=assitpf[i];
            } else{
                assitpf[i]=profit[i]+max(assitpf[i-1],max(prev2max,0));
                maxp=max(maxp,assitpf[i]);
            }
        }
        return maxp;
    }
};
