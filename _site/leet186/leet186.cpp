class Solution {
public:
    void reverseWords(string &s) {
    	int i=0,j=s.length()-1;
		while(i<j){
			swap(s[i++],s[j--]);
		}
		i = s.find_first_not_of(' ');
		while(i<s.length()){
			int end = s.find_first_of(' ',i);
		 	if(end==string::npos) j = s.length()-1;
			else j = end-1;
			while(i<j){
				swap(s[i++],s[j--]);
			}
			i = s.find_first_not_of(' ',end);
		}
    }
};
