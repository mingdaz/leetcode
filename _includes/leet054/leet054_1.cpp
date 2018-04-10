class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int m = matrix.size();
        if(m==0) return ret;
        int n = matrix[0].size();
        if(n==0) return ret;
        int rt = 0,rb = m-1;
        int cl = 0,cr = n-1;

        while(rt<=rb&&cl<=cr){
            for(int i = cl;i<=cr;i++){
                ret.push_back(matrix[rt][i]);
            }
            rt++;
            if(rt>rb) break;
            for(int i = rt;i<=rb;i++){
                ret.push_back(matrix[i][cr]);
            }
            cr--;
            if(cl>cr) break;
            for(int i = cr;i>=cl;i--){
                ret.push_back(matrix[rb][i]);
            }
            rb--;
            if(rt>rb) break;
            for(int i = rb;i>=rt;i--){
                ret.push_back(matrix[i][cl]);
            }
            cl++;
        }
        return ret;
    }
};