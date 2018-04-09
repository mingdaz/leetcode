class Solution {
public:
    bool isStrobogrammatic(string num) {
        int l = 0;
        int r = num.size()-1;
        while(l<r){
            if(num[l]=='6'){
                if(num[r]!='9') return false;
            }
            else if(num[l]=='9'){
                if(num[r]!='6') return false;
            }
            else if(num[l]=='8'){
                if(num[r]!='8') return false;
            }
            else if(num[l]=='1'){
                if(num[r]!='1') return false;
            }
            else if(num[l]=='0'){
                if(num[r]!='0') return false;
            }
            else 
                return false;
            l++;
            r--;
        }
        if(l==r){
            if(num[r]!='8'&&num[r]!='0'&&num[r]!='1') return false;
        }
        return true;
    }
};

