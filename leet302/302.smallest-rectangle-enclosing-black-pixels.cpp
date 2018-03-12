class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        if(image.size()==0 || image[0].size()==0) return 0;
        int left, right, up, down, m = image.size(), n = image[0].size();
        left = bs(image, 0, y, 0, m - 1, true, true);
        right = bs(image, y, n - 1, 0, m - 1, true, false);
        up = bs(image, 0, x, left, right - 1, false, true);
        down = bs(image, x, m - 1, left, right - 1, false, false);
        return (right-left) * (down-up);
    }
    
    int bs(vector<vector<char>>& image, int lower, int upper, int top, int bottom, bool hori, bool go_lower){
        int mid;
        bool inside = false;
        while(lower <= upper){
            mid = lower + ((upper-lower)>>1);
            inside = false;
            /* Check the boundary */
            for(int i = top; i <= bottom; i++){
              if((hori ? image[i][mid] : image[mid][i]) == '1'){
                  inside = true;
                  break;
              }
            }
            if(go_lower){
                //Find the position 2
                if(inside == false) lower = mid + 1;
                else upper = mid - 1;
            }
            else{
                if(inside == true) lower = mid + 1;
                else upper = mid - 1;
            }
        }
        return lower;
    }
};