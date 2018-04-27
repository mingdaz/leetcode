class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int count, int pos) {
        int n = (int)heights.size();
    for (int k = 0; k < count; k++) {
        // drop to x
        int minIndex = pos, minHeight = heights[pos];
        int i = pos;
        while (i - 1 >= 0 && heights[i] >= heights[i - 1]) {
            if (heights[i] > heights[i - 1]) {
                minIndex = i - 1;
                minHeight = heights[i - 1];
            }
            i --;
        }
        
        if (minIndex < pos) {
            heights[minIndex] ++;
            continue;
        }
        
        i = pos;
        while (i + 1 < n && heights[i] >= heights[i + 1]) {
            if (heights[i] > heights[i + 1]) {
                minIndex = i + 1;
                minHeight = heights[i + 1];
            }
            i ++;
        }
        heights[minIndex] ++;
    }
    return heights;
    }
};