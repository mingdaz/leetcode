/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool sortbyfirst(const Interval &a,
                   const Interval &b)
{
       return a.start<b.start;
}

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),sortbyfirst);  
        priority_queue <int, vector<int>, greater<int> > endtime;
        for(auto intv:intervals){
            if(endtime.size()==0){
                endtime.push(intv.end);
            }
            else{
                if(endtime.top()<=intv.start){
                    endtime.pop();    
                }                
                endtime.push(intv.end);
            }
        }
        return endtime.size();
    }
};
