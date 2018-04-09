class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int rb = matrix.size();
        if(rb==0) return res;
        int cb = matrix[0].size();
        if(cb==0) return res;
        int ra = 0;
        int ca = 0;
        int idx = 0;
        int i;
        int tot = rb*cb;
        res.resize(tot);
        while(idx<tot){
            for(i=ca;i<cb;i++,idx++){
                res[idx] = matrix[ra][i];
            }
            if(idx>=tot) break;
            cb--,ra++;
            for(i=ra;i<rb;i++,idx++){
                res[idx] = matrix[i][cb];
            }
            if(idx>=tot) break;
            rb--;
            for(i=cb-1;i>=ca;i--,idx++){
                res[idx] = matrix[rb][i];
            }
            if(idx>=tot) break;
            for(i=rb-1;i>=ra;i--,idx++){
                res[idx] = matrix[i][ca];
            }
            ca++;
        }
        return res;

    }
};
