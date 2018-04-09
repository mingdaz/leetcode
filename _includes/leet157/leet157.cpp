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
    	char *src = new char[4];
    	int i = 0, rtn = 4;
    	while(i < n && rtn == 4){
       		rtn = read4(src);
        	memcpy(buf + i, src, rtn);
        	i += rtn;
    	}
    	return i >= n ? n : i;
	}
};
