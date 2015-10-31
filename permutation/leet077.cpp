/* Lexicographic ordered generation
 Without recursions, generate all combinations in sequence. 
Basic logic: 
put n items in the first n of m slots; 
each step, if right most slot can be moved one slot further right, do so; 
otherwise find right most item that can be moved, 
move it one step and put all items already to its right next to it.
*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        int i = 0;
        vector<int> p(k, 0);
        while (i >= 0) {
            p[i]++;
            if (p[i] > n) --i;
            else if (i == k - 1) result.push_back(p);
            else {
                ++i;
                p[i] = p[i - 1];
            }
        }
        return result;
    }
};