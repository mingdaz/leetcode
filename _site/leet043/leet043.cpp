class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")
            return "0";
        int len1 = num1.length();
        int len2 = num2.length();
        int i,j;
        int carry = 0;
        int temp;
        string res(len1+len2,'0');
        for(i=len1-1;i>=0;i--){
            for(carry = 0,j=len2-1;j>=0;j--){
                temp = (num1[i]-'0')*(num2[j]-'0')+res[i+j+1]-'0'+carry;
                carry = temp/10;
                res[i+j+1] = temp%10+'0';
            }
            res[i] = carry+'0';
        }
        if(carry) return res;
        return res.substr(1);
    }
};
