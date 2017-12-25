class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int cnt;
        for(int i=0;i<data.size();i++){
            cnt = 0;
            if(data[i]<0x80) continue;
            else if(data[i]<0xC0||data[i]>0xF7) return false;
            else if(data[i]>=0xC0&&data[i]<0xE0) cnt = 2;
            else if(data[i]>=0xE0&&data[i]<0xF0) cnt = 3;
            else cnt = 4;
            while(--cnt&&++i<data.size()){
                if(data[i]<0x80||data[i]>0xBF) return false;
            }
            if(cnt) return false;
        }
        return true;
    }
};
