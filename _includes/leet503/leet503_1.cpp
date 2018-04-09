class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<pair<int,int>> st;
        vector<int> res( nums.size() , -1 );
        for( int i = 0 ; i < 2 * nums.size() ; ++i ){
            int j = i % nums.size();
            while( st.size() && st.top().first < nums[j] ){
                res[st.top().second] = nums[j];
                st.pop();
            }
            if( i < nums.size() )
                st.push( make_pair( nums[j] , j ) );
        }
        return res;
    }
};
