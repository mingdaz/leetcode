class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res(digits);
        int carry = 1;
        for(int i= digits.size()-1;i>=0;i--){
            int temp = digits[i] + carry;
            carry = temp/10;
            res[i] = temp%10;    
        }
        if(carry==1){
            auto it = res.begin();
            it = res.insert ( it , 1 );
        }
        return res;
    }
};
