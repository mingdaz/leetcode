class Solution {
public:
    bool isStrobogrammatic(string num) {
        int i = 0,j = num.length()-1;
        while(i<j){
            switch(num[i]){
                case '0': if(num[j]!='0') return false; break;
                case '1': if(num[j]!='1') return false; break;
                case '6': if(num[j]!='9') return false; break;
                case '8': if(num[j]!='8') return false; break;
                case '9': if(num[j]!='6') return false; break;
                default: return false;
            }
            i++;
            j--;
        }
        if(i==j){
            if(num[i]!='0'&&num[i]!='1'&&num[i]!='8')
                return false;
        }
        return true;
    }
};
