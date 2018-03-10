// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    char tmp[4];
	int i4 = 0;
	int n4 = 0;
	int read(char *buf, int n) {
		int i = 0;
		while( i<n &&( i4<n4 || (i4=0)<(n4=read4(tmp)) ))
			buf[i++] = tmp[i4++];
		return i;
	}
};
