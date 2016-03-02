class Solution {
public:
    Solution() {
        mapping = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
    }
    int strobogrammaticInRange(string low, string high) {
        if(low == high) return isStrobogrammatic(high);
        if(isLarger(low, high)) return 0;
        int count1 = countBelow(low);
        int count2 = countBelow(high);
        if(isStrobogrammatic(low)) count1--;
        return count2 - count1;
    }
    bool isLarger(const string& a, const string& b) {
        int m = a.size(), n = b.size();
        if(m != n) return m > n;
        for(int i = 0; i < m; ++i) {
            if(a[i] > b[i]) return true;
            if(a[i] < b[i]) return false;
        }
        return false; //equal, false
    }

    //count strobo numbers from 0 to num including num
    int countBelow(string num) {
        int count = 1; //"0"
        for(int n = 1; n < num.size(); ++n) {
            int tmp = stroboLengthN(n);
            if(n == 1) count += tmp-1; //not include zero 
            else count += tmp-tmp/5; //not include zero
        }
        count += sameLengthStroboBelow(num, false);
        return count;
    }
    //count strobogrammatic numbers <= str, with the same length as str (starting with "0" or "1" depending on countZero)
    int sameLengthStroboBelow(string str, bool countZero) {
        int n = str.size();
        int count = 0;
        if(n == 1) {
            int v = str[0]-'0';
            count = stroboBelow(v, 1);
            if(!countZero) count --;
        } else if (n == 2) {
            int v = (str[0]-'0')*10 + (str[1]-'0');
            count = stroboBelow(v, 2);
            if(!countZero) count --;
        } else {
            int v1 = (str[0]-'0'), v2 = (str[n-1]-'0');
            //count strobo with first digit being 1 .. v1-1.
            if(v1 > 0) {
                int tmp = stroboBelow(v1*10-1, 2);
                if(!countZero) tmp--;
                count += tmp*stroboLengthN(n-2); 
            }
            string sub = str.substr(1, n-2);
            if(mapping[v1] >= 0) count += sameLengthStroboBelow(sub, true);
            if(v2 < mapping[v1] && isStrobogrammatic(sub)) count--; //avoid overcounting
        }
        return count;
    }

    // number of strobos <= v with d digits (including "0" or "00").
    // v is a number between 0-9 (when d = 1) or 0-99 (when d = 2).
    // 1d strobos: "0", "1", "8"
    // 2d strobos: "00", "11", "69", "88", "96"
    int stroboBelow(int v, int d) {
       int count = 0;
       if(d == 1) {
           if(v < 1) count = 1;
           else if(v < 8) count = 2;
           else count = 3;
       } else if(d == 2) {
           if(v < 11) count = 1;
           else if(v < 69) count = 2; //11
           else if(v < 88) count = 3;
           else if(v < 96) count = 4;
           else count = 5;     
       }
       return count;
    }

    //count strobo for digit n (can have leading zeros)
    int stroboLengthN(int n) {
        if(n == 0) return 0;
        int count = (n % 2 == 1) ? 3 : 5;
        while(n > 2) {
            n -= 2;
            count *= 5;  
        }
        return count;
    }

    bool isStrobogrammatic(string num) {
        int n = num.size();
        for(int i = 0; i < n/2; ++i) {
            char c1 = num[i];
            char c2 = num[n-i-1];
            if( (c1 == '0' && c2 == '0') ||
                (c1 == '1' && c2 == '1') ||
                (c1 == '6' && c2 == '9') ||
                (c1 == '8' && c2 == '8') ||
                (c1 == '9' && c2 == '6') ) continue;
            return false;
        }
        if(n % 2 == 1) {
            char c = num[n/2];
            if(c != '0' && c != '1' && c != '8') return false;
        }
        return true;
    }
    vector<int> mapping;
};
