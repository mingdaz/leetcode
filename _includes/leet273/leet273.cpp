class Solution {
public:
    string numberToWords(int num) {
        if(num==0) return "Zero";
        string res = "";
        int cnt = 0;
        while(num>0){
            int rem = num%1000;
            helper(res,rem,cnt);
            num /= 1000;
            cnt ++;
            if(rem&&num) res = " " + res;
        }
        return res;
    }
private:
    void helper(string& res, int num, int cnt){
        if(num==0) return;
        string cur = "";
        if(num>=100){
            cur = cur + under20[num/100] + " Hundred";
            num = num%100;
            if(num>0) cur.push_back(' ');
        }
        if(num>=20){
            cur = cur + tens[num/10];
            num = num%10;
            if(num>0) cur.push_back(' ');
        }
        if(num>0)
            cur = cur + under20[num];
        if(cnt>0)
            cur = cur + " " + level[cnt];
        res = cur + res;        
    }

    vector<string> level = { "", "Thousand", "Million", "Billion"};
    vector<string> under20 = {
        "","One","Two","Three","Four","Five","Six","Seven","Eight","Nine",
        "Ten","Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
        "Eighteen", "Nineteen"};
    vector<string> tens = {
      "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"  
    };
};