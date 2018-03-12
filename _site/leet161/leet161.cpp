class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int sl = s.length();
		int tl = t.length();
		
		if(abs(sl-tl)>1) return false;
		bool edit = false;
 		int i=0,j=0;
 		while(i<sl&&j<tl){
            if(s[i]==t[j]) i++,j++;
            else if(edit) return false;
            else{
                edit = true;
                if(sl>tl) i++;
                else if(sl<tl) j++;
                else i++,j++;
            }  
		}
		return edit||i<sl||j<tl;
    }
};

