class Solution {
public:
    string fractionToDecimal(long a, long b) {
        string res;
        string dec = "";
        int sig = 1;
        if(a==0) return "0";
        if(a<0){
            a = -a;
            sig *= -1;
        } 
        if(b<0) {
            b = -b;
            sig *= -1;
        }
        if(sig<0){
            res = "-";
        }
        unordered_map<long,int> r;
        res += to_string(a/b);
        if(a%b==0) return res;
        else{
            a = a%b;
            res += ".";
        }   
        
        while(a&&r.find(a)==r.end()){
            r[a] = dec.size();
            a*=10;
            if(a<b){
                dec = dec + "0";  
            }
            else{
                int p = a/b;
                a = a%b;
                dec = dec + to_string(p);    
            }
        }
        if(a != 0) dec = dec.insert(r[a],"(") + ")";
        res = res + dec;
        return res;
    }
    
};
