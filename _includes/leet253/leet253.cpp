/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intv) {
        if(intv.empty()) return 0;
        sort(intv.begin(),intv.end(),[](Interval& a, Interval& b){return a.start< b.start;});
        priority_queue<int,vector<int>,greater<int>> endtime;
        endtime.push(intv[0].end);
        for(int i=1;i<intv.size();i++){
            int prev = endtime.top();
            if(prev<=intv[i].start){
                endtime.pop();
            }
            endtime.push(intv[i].end);       
        }
        return endtime.size();
    }
};