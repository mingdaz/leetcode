/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
class mycomparison{
    bool reverse;
public:
    mycomparison(const bool& revparam=true){
        reverse=revparam;
        
    }
    bool operator() (const Interval& lhs, const Interval&rhs) const{
        if (reverse) return (lhs.end>rhs.end);
        else return (lhs.end<rhs.end);
    }
};

class Solution {

	static bool cmp(Interval& a,Interval& b){
		return a.start<b.start;
	}
	static bool cmpend(Interval& a,Interval& b){
		return a.end<b.end;
	}
	priority_queue<Interval,vector<Interval>,mycomparison> EndtimeQ;
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
		sort(intervals.begin(),intervals.end(),cmp);
		EndtimeQ.push(intervals[0]);
		for(int i=1;i<intervals.size();i++){
			if(intervals[i].start>=EndtimeQ.top().end) EndtimeQ.pop();
			EndtimeQ.push(intervals[i]);
		}
		return EndtimeQ.size();
    }
};

