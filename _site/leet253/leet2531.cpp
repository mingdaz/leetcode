class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int ans = 0;
        if(!intervals.size())
            return ans;
        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size();
        priority_queue<int, vector<int>, greater<int> > pq;
        pq.push(intervals[0].end);
        for(int i = 1; i < n; ++ i){
            int start_time = intervals[i].start, end_time = pq.top();
            if(start_time >= end_time){
                pq.pop();
            }
            pq.push(intervals[i].end);
        }
        ans = pq.size();
        return ans;
    }
private:
    static bool cmp(Interval &inta, Interval &intb){
        if(inta.start == intb.start)
            return inta.end < intb.end;
        return inta.start < intb.start;
    }
};
