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
 	static bool cmp(Interval& a,Interval& b){
		return a.start<b.start;
	}
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
		int time = -1;
		for(int i=0;i<intervals.size();i++){
			if(intervals[i].start<time) return false;
			time = intervals[i].end; 
		}
		return true;
    }
	
};

