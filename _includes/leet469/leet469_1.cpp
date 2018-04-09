class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        /* Calculate the adjacent 3 points' perpendicular vector and
        check if they are all with the same sign. Note, need to skip those
        zero perpendicular vector how to calculate perpendicular vector?
        1221, xyxy */
        long long n = points.size(), pre = 0, cur = 0;
        for(int i = 0; i < n; i++){
            int dx1 = points[(i+1)%n][0] - points[i][0];
            int dx2 = points[(i+2)%n][0] - points[i][0];
            int dy1 = points[(i+1)%n][1] - points[i][1];
            int dy2 = points[(i+2)%n][1] - points[i][1];
            cur = dx1*dy2 - dx2*dy1;
            if(cur != 0){
                if(pre * cur < 0) return false;
                pre = cur;
            }
        }
        return true;
    }
};
