class Solution {
    static bool comp1(const string& str1, const string& str2){
        if(str1.size()==str2.size()){
            int x = count(str1.begin(), str1.end(), '0');
            int y = count(str2.begin(), str2.end(), '0');
            return x<y;
        }
        return str1.size()<str2.size();
    }
    static bool comp2(const string& str1, const string& str2){
        if(str1.size()==str2.size()){
            int x = count(str1.begin(), str1.end(), '1');
            int y = count(str2.begin(), str2.end(), '1');
            return x<y;
        }
        return str1.size()<str2.size();
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        if(m<n)
            sort(strs.begin(), strs.end(), comp1);
        else
            sort(strs.begin(), strs.end(), comp2);
        int m1 = m;
        int n1 = n;
        int zero, one;
        int count1 = 0;
        for(auto str: strs){
            zero = count(str.begin(), str.end(), '0');
            one = count(str.begin(), str.end(), '1');
            if(m1>=zero && n1>=one){
                m1-=zero;
                n1-=one;
                count1++;
            }
        }
        m1 = m;
        n1 = n;
        int count2 = 0;
        for(int i = strs.size()-1; i>=0; --i){
            zero = count(strs[i].begin(), strs[i].end(), '0');
            one = count(strs[i].begin(), strs[i].end(), '1');
            if(m1>=zero && n1>=one){
                m1-=zero;
                n1-=one;
                count2++;
            }
        }
        return max(count1, count2);
    }
};
