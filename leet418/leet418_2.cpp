class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string s;
        for(int i = 0; i < sentence.size(); i ++) {
            s += sentence[i] + " ";
        }
        int l = s.length();
        
        int j = 0;
        for(int i = 0; i < rows; i ++) {
            j += cols;
            if (s[j%l] == ' ') {
                j ++;
            } else {
                while(j > 0 and s[(j-1)%l] != ' ') {
                    j --;
                }
            }
        }
        return j/l;
    }
};
