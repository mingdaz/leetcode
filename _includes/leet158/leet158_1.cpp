// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        // std::cout<<idx<<","<<string(tmp)<<",";
        if(idx==-1){
            idx = 0;
            ret = read4(tmp);
        }
        // std::cout<<idx<<","<<string(tmp)<<std::endl;
        int i = 0;
        for(i=0;i<n;i++,idx++){
            if(idx==ret) {
                if(ret<4) return i; 
                ret = read4(tmp);
                idx = 0;
            }
            if(idx<ret){
                buf[i] = tmp[idx];  
            } 
            else{
                return i;
            }
        }
        return n;
    }
private: 
    int idx = -1;
    int ret;
    char tmp[4] = {0,0,0,0};
};