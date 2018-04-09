class Solution {
public:
    int lengthLongestPath(string input) {
        stack<int> path;
        int len = input.size();
        int idx = 0;
        int pre = 0;
        int cur_len = 0;
        int max_len = 0;
        int level = 0;

        bool is_file = false;
        while(idx<len){
            level = 0;
            while(input[idx]=='\t') {
                idx ++;
                level ++;
            }
            pre = idx;
            is_file = false;
                

            while(idx<len&&input[idx]!='\n'){
                if(input[idx]=='.') 
                    is_file = true;
                idx++;  
            } 
            
            while(level<path.size()){
                cur_len -= path.top(); // remove dir
                path.pop();
                cur_len--; // remove '/'
            }
            if(cur_len<0) cur_len = 0;
            path.push(idx-pre);
            if(level>0) cur_len++; // add '/'
            cur_len += path.top();
            if(is_file) max_len = max(max_len,cur_len);
            idx++;
        }
        return max_len;
         
    }
};
